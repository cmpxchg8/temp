; *********************************************************************
;
;   Copyright (C) 2014 Kevin Devine - @cmpxchg8
;
;   This program is free software: you can redistribute it and/or modify
;   it under the terms of the GNU General Public License as published by
;   the Free Software Foundation, either version 3 of the License, or
;   (at your option) any later version.
;
;   This program is distributed in the hope that it will be useful,
;   but WITHOUT ANY WARRANTY; without even the implied warranty of
;   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;   GNU General Public License for more details.
;
;   You should have received a copy of the GNU General Public License
;   along with this program.  If not, see <http://www.gnu.org/licenses/>.
;
; *********************************************************************

  ; #####################################################################
  ;
  ; Generate a 32-bit hash of string
  ;
  ; in:  rax/eax : pointer to string
  ;
  ; out: eax : hash of string
  ;
  ; #####################################################################
hash32:

ifdef USE_X86
    pushad
    xchg   eax, esi
else
    push   rsi
    push   rdx
    
    push   rax
    pop    rsi
endif
    xor    eax, eax
    cdq                                ; edx = (eax >= 0x80000000) ? -1 : 0 
hash_api:
    lodsb
ifdef USE_CRC
    crc32  edx, al
else
    add    edx, eax
    rol    edx, ROL_CONSTANT
endif
    dec    eax                         ; if (eax != 0) goto hash_api;
    jns    hash_api                    ; would be signed at end of string

ifdef USE_X86
    mov    [esp][PUSHAD_STRUCT._eax], edx
    popad
else
    xchg   eax, edx
    
    pop    rdx
    pop    rsi
endif
    ret

ifdef USE_X86    
  ifdef USE_IAT

    ; ###############################################################
    ;
    ; Resolve API address based on hash using Import Address Table
    ;
    ; in:  eax = hash of API string to find, ebx = base of DLL to search
    ; out: eax = address or zero for failure
    ;
    ; ###############################################################  
  search_iat:
      pushad
      
      mov    eax, [ebx][IMAGE_DOS_HEADER.e_lfanew]
      add    eax, 8                ; get import directory
      
      ; if (IMAGE_DATA_DIRECTORY.VirtualAddress == 0) goto exit_iat;
      mov    eax, [ebx+eax+78h]
      test   eax, eax
      jz     exit_iat
      
      lea    ebp, [eax+ebx]
  nxt_desc:
      mov    esi, ebp              ; esi = current descriptor
      lodsd                        ; OriginalFirstThunk +00h
      xchg   eax, edx              ; temporarily store in edx
      lodsd                        ; TimeDateStamp      +04h
      lodsd                        ; ForwarderChain     +08h
      lodsd                        ; Name_              +0Ch
      test   eax, eax
      jz     exit_iat              ; if (Name_ == 0) goto exit_iat;
      lodsd                        ; FirstThunk         +10h
      mov    ebp, esi              ; ebp = next descriptor
      
      lea    esi, [edx+ebx]        ; esi = OriginalFirstThunk + image base
      lea    edi, [eax+ebx]        ; edi = FirstThunk + image base
  load_api:
      lodsd                        ; eax = IMAGE_THUNK_DATA.u1.Function, pOriginalFirstThunk++;
      scasd                        ; pFirstThunk++;
      test   eax, eax              ; if (IMAGE_THUNK_DATA.Function == 0)
      jz     nxt_desc              ; goto nxt_desc
      
      cdq                          
      inc    edx                   ; will be zero if eax >= 0x80000000
      jz     load_api              ; IMAGE_THUNK_DATA.u1.Ordinal & IMAGE_ORDINAL_FLAG
      
      lea    eax, [eax+ebx+2]      ; IMAGE_IMPORT_BY_NAME.Name_
      call   hash32                ; get hash of API string    
      
      cmp    [esp][PUSHAD_STRUCT._eax], eax  ; found match?
      jne    load_api
      
      mov    eax, [edi-4]          ; IMAGE_THUNK_DATA.u1.Function    
  exit_iat:
      mov    [esp][PUSHAD_STRUCT._eax], eax
      popad
      ret
      
  else

    ; ###############################################################
    ;
    ; Resolve API address based on hash using Export Address Table
    ;
    ; in:  eax = hash, ebx = base of DLL to search
    ; out: eax = address or zero for failure
    ;
    ; ###############################################################
  search_eat:
      pushad
      ; [IMAGE_DOS_HEADER.e_lfanew]
      mov    eax, [ebx+3ch]
      
      ; [IMAGE_NT_HEADERS.OptionalHeader.DataDirectory][IMAGE_DIRECTORY_ENTRY_EXPORT][IMAGE_DATA_DIRECTORY.VirtualAddress]
      mov    ecx, [ebx+eax+78h]
      jecxz  exit_eat
      
      ; [IMAGE_EXPORT_DIRECTORY.NumberOfNames        ] = 18h
      ; [IMAGE_EXPORT_DIRECTORY.AddressOfNameOrdinals] = 24h
      lea    esi, [ebx+ecx+18h]
      push   4
      pop    ecx
  load_rva:
      lodsd
      add    eax, ebx
      push   eax
      loop   load_rva
      
      ; AddressOfNameOrdinals
      pop    edi
      ; AddressOfNames 
      pop    edx
      ; AddressOfFunctions
      pop    esi
      ; NumberOfNames    
      pop    ecx
      
      sub    ecx, ebx
      jz     exit_eat
  find_api_eat:
      mov    eax, [edx+4*ecx-4]
      add    eax, ebx
      call   hash32
      
      cmp    eax, dword ptr[esp][PUSHAD_STRUCT._eax]
      loopne find_api_eat
      jne    exit_eat
      
      xchg   eax, ebx
      xchg   eax, ecx
      
      movzx  eax, word ptr [edi+2*eax]
      add    ecx, [esi+4*eax]
  exit_eat:
      mov    [esp][PUSHAD_STRUCT._eax], ecx
      popad
      ret
  endif
    
  ; ###############################################################
  ;
  ; Resolve API address based on hash
  ;
  ; in:  eax = hash of API string to find
  ; out: eax = address or zero for failure
  ;
  ; ###############################################################  
getapi:
    pushad
    push   30h
    pop    ecx
    
    assume fs:nothing
    
    mov    eax, dword ptr fs:[ecx]
    mov    eax, [eax][PEB.Ldr]
    mov    edi, [eax][PEB_LDR_DATA.InInitializationOrderModuleList.Flink]
    jmp    load_base
scan_tbls:
    mov    eax, [esp][PUSHAD_STRUCT._eax]
  ifdef USE_IAT
      call   search_iat            ; Import Address Table
  else
      call   search_eat            ; Export Address Table
  endif
    test   eax, eax
    jnz    exit_getapi32

    mov    edi, [edi][LDR_DATA_TABLE_ENTRY.InMemoryOrderLinks.Flink]
load_base:
    mov    ebx, [edi][LDR_DATA_TABLE_ENTRY.DllBase]
    test   ebx, ebx
    jnz    scan_tbls
exit_getapi32:
    mov    [esp][PUSHAD_STRUCT._eax], eax
    popad
    ret
    
else

  ifdef USE_IAT

    ; ###############################################################
    ;
    ; Resolve API address based on hash (Import Address Table)
    ;
    ; in:  r8d = hash of API string to find, rbx = base of DLL to search
    ; out: rax = address or zero for failure
    ;
    ; ###############################################################  
  search_iat proc uses rdi rsi rbp rbx

      mov    eax, [rbx][IMAGE_DOS_HEADER.e_lfanew]
      add    eax, 18h              ; get import directory
      
      ; if (IMAGE_DATA_DIRECTORY.VirtualAddress == 0) goto exit_iat;
      mov    eax, [rbx+rax+78h]
      test   eax, eax
      jz     exit_iat
      
      lea    rbp, [rax+rbx]
  nxt_desc:
      push   rbp
      pop    rsi
      lodsd                        ; OriginalFirstThunk +00h
      xchg   eax, edx              ; temporarily store in edx
      lodsd                        ; TimeDateStamp      +04h
      lodsd                        ; ForwarderChain     +08h
      lodsd                        ; Name_              +0Ch
      test   eax, eax
      jz     exit_iat              ; if (Name_ == 0) goto exit_iat;
      lodsd                        ; FirstThunk         +10h
      push   rsi
      pop    rbp
      
      lea    rsi, [rdx+rbx]        ; OriginalFirstThunk + image base
      lea    rdi, [rax+rbx]        ; FirstThunk + image base
  load_api:
      lodsq                        ; IMAGE_THUNK_DATA.u1.Function
      scasq
      test   eax, eax              ; if (IMAGE_THUNK_DATA.Function == 0)
      jz     nxt_desc              ; goto nxt_desc
      
      cqo
      inc    edx                   ; will be zero if rax >= 0x8000000000000000
      jz     load_api              ; IMAGE_THUNK_DATA.u1.Ordinal & IMAGE_ORDINAL_FLAG
      
      lea    rax, [rax+rbx+2]      ; IMAGE_IMPORT_BY_NAME.Name_
      call   hash32                ; get hash of API string    
      
      cmp    eax, r8d              ; found match?
      jne    load_api
      
      mov    rax, [rdi-8]          ; IMAGE_THUNK_DATA.u1.Function    
  exit_iat:
      ret
  search_iat endp
  
  else

    ; ###############################################################
    ;
    ; Resolve API address based on hash using Export Address Table
    ;
    ; in:  r8d = hash, rbx = base of DLL to search
    ; out: rax = address or zero for failure
    ;
    ; ###############################################################
  search_eat proc uses rsi rbx rdi rcx

      ; [IMAGE_DOS_HEADER.e_lfanew]
      mov    eax, [rbx][IMAGE_DOS_HEADER.e_lfanew]
      add    eax, 10h
      
      ; [IMAGE_NT_HEADERS.OptionalHeader.DataDirectory][IMAGE_DIRECTORY_ENTRY_EXPORT][IMAGE_DATA_DIRECTORY.VirtualAddress]
      mov    ecx, [rbx+rax+78h]
      jecxz  exit_getapi_eat
      
      ; [IMAGE_EXPORT_DIRECTORY.NumberOfNames        ] = 18h
      ; [IMAGE_EXPORT_DIRECTORY.AddressOfNameOrdinals] = 24h
      lea    rsi, [rbx+rcx+18h]
      push   4
      pop    rcx
  load_rva:
      lodsd
      add    rax, rbx
      push   rax
      loop   load_rva
      
      ; AddressOfNameOrdinals
      pop    rdi
      ; AddressOfNames 
      pop    rdx
      ; AddressOfFunctions
      pop    rsi
      ; NumberOfNames    
      pop    rcx
      
      sub    rcx, rbx
      jz     exit_getapi_eat
  find_api_eat:
      mov    eax, [rdx+4*rcx-4]
      add    rax, rbx
      call   hash32
      
      cmp    eax, r8d
      loopne find_api_eat
      jne    exit_getapi_eat
      
      xchg   rax, rbx
      xchg   rax, rcx
      
      movzx  eax, word ptr [rdi+2*rax]
      mov    eax, [rsi+4*rax]
      add    rcx, rax
  exit_getapi_eat:
      mov    rax, rcx
      ret
  search_eat endp

  endif

  ; ###############################################################
  ;
  ; Resolve API address based on hash
  ;
  ; in:  eax = hash of API string to find
  ; out: eax = address or zero for failure
  ;
  ; ###############################################################  
getapi:
    push   rbx
    push   rdi
    mov    r8d, eax
    
    push   60h
    pop    rbx
    
    mov    rax, gs:[rbx]
    mov    rax, [rax+18h]        ; PEB.Ldr
    mov    rdi, [rax+30h]        ; PEB_LDR_DATA.InInitializationOrderModuleList.Flink
    jmp    load_base64
scan_tbls64:

ifdef USE_IAT
    call   search_iat            ; Import Address Table
else
    call   search_eat            ; Export Address Table
endif
    test   rax, rax
    jnz    exit_getapi64
    
    mov    rdi, [rdi]            ; LDR_DATA_TABLE_ENTRY.InMemoryOrderLinks.Flink
load_base64:
    mov    rbx, [rdi+10h]        ; LDR_DATA_TABLE_ENTRY.DllBase
    test   rbx, rbx
    jnz    scan_tbls64
    xchg   eax, ebx
exit_getapi64:
    pop    rdi
    pop    rbx
    ret
    
endif