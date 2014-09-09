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

ifdef USE_IAT

  ; cpystr (di, si, cx);
  cpystr:

  ifdef USE_X86
      pushad
  else
      push   rdi
      push   rcx
  endif
      xor    eax, eax
      lodsb                   ; length of string in esi
      xchg   eax, ecx         ; ecx = eax
      rep    movsb
      xchg   eax, ecx         ; eax = 0
      stosb
  ifdef USE_X86
      mov    [esp][PUSHAD_STRUCT._esi], esi
      popad
  else
      pop    rcx
      pop    rdi
  endif
      ret
endif
  
ifdef USE_X86

  resolve_api32:

  ifdef USE_IAT  
      ; ebx = getapi ("GetProcAddress"); 
      mov    eax, API_HASH ("GetProcAddress")
      call   getapi
      test   eax, eax
      jz     exit_resolve32
      
      xchg   eax, ebx
      
      ; eax = getapi ("GetModuleHandleA");
      mov    eax, API_HASH ("GetModuleHandleA")
      call   getapi
      test   eax, eax
      jz     exit_resolve32
      
      ; load DLL string
      call   cpystr
      
      ; ebp = GetModuleHandleA ("module");
      push   edi
      call   eax
      test   eax, eax
      jz     exit_resolve32
      
      xchg   eax, ebp
      
      xor    eax, eax
      lodsb                        ; number of API to resolve
      xchg   eax, ecx
  resolve_loop:
      call   cpystr                ; copy string from esi to edi
      
      push   ecx
      push   edi                   ; API string
      push   ebp                   ; base of kernel32
      call   ebx                   ; GetProcAddress (ebp, edi);
      pop    ecx
      test   eax, eax
      jz     exit_resolve32
      
      stosd
      loop   resolve_loop    
  else
      xor    eax, eax
      lodsb                        ; eax = number of hashes
      xchg   eax, ecx
  resolve_loop:
      lodsd
      call   getapi
      test   eax, eax
      jz     exit_resolve32
      
      stosd
      loop   resolve_loop
  endif
  
  exit_resolve32:
      ret
else

      ; #############################################################
      ;
      ; resolve API addresses
      ;
      ; #############################################################
      
      ra_stk struc
        hs      HOME_SPACE <>
        
        @api    BYTE 64 dup (?)
      ra_stk ends

      RA_STK_SIZE  equ ((sizeof (ra_stk) and -16) + 16) - 8
      
  resolve_api64:
  ifdef USE_IAT  
      mov    r12, rsp
      add    rsp, -RA_STK_SIZE
      
      ; rbx = getapi ("GetProcAddress"); 
      mov    eax, API_HASH ("GetProcAddress")
      call   getapi
      test   rax, rax
      jz     exit_resolve64
      
      xchg   rax, rbx
      
      ; load DLL string
      call   cpystr
      
      ; rax = getapi ("GetModuleHandleA");
      mov    eax, API_HASH ("GetModuleHandleA")
      call   getapi
      test   rax, rax
      jz     exit_resolve64
      
      ; rbp = GetModuleHandleA ("kernel32")
      push   rdi
      pop    rcx
      call   rax
      test   rax, rax
      jz     exit_resolve64
      
      xchg   rax, rbp
      
      xor    eax, eax
      lodsb                        ; number of API to resolve
      xchg   eax, ecx
  resolve_loop:
      call   cpystr                ; copy string from esi to edi
      
      mov    r14, rcx
      push   rdi                   ; API string
      pop    rdx
      push   rbp                   ; base of kernel32
      pop    rcx
      call   rbx                   ; GetProcAddress (ebp, edi);
      mov    rcx, r14
      test   eax, eax
      jz     exit_resolve64
      
      stosq
      loop   resolve_loop
      
      mov    rsp, r12
  else
      xor    eax, eax
      lodsb                        ; eax = number of hashes
      xchg   eax, ecx
  resolve_loop:
      lodsd
      call   getapi
      test   eax, eax
      jz     exit_resolve64
      
      stosq
      loop   resolve_loop
  endif
  exit_resolve64:
      ret
endif