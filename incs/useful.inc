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
  option casemap:none
  
  .nolist
  .nocref

  WIN32_LEAN_AND_MEAN equ 1

  include windows.inc
  include winsock2.inc
  include wincrypt.inc
  include urlmon.inc
  
  .list
  .cref
  
ifdef USE_X86
  CPU_MODE equ 32
else
  CPU_MODE equ 64
endif

BUFSIZ       equ 1FFh
ROL_CONSTANT equ 9

ROL32 macro iNum:req, iBits:req
  exitm <((iNum shl iBits) and 0FFFFFFFFh) or (iNum shr (32-iBits))>
endm

ifdef USE_CRC
  ; Reversed Castagnoli polynomial (0x1EDC6F41)
  ; which intel crc32 instruction uses
  CRC32C_POLY equ 082F63B78h

  UPDATECRC32 macro crc:req, v:req
    crc = crc xor v
    rept 8
      crc = (crc shr 1) xor (CRC32C_POLY and -(crc and 1))
    endm
    exitm <crc>
  endm

  API_HASH macro s:req
    local crc
    
    crc = 0
    forc x, <s>
      if @InStr(1, <x>, <!">) eq 0
        crc = UPDATECRC32 (crc, '&x')
      endif
    endm
    
    crc = UPDATECRC32 (crc, 0)
    
    exitm<(crc and 0FFFFFFFFh)>
  endm
else
  ; case sensitive
  API_HASH macro s:req
    local h
    
    h = 0
    forc x, <s>
      if @InStr(1, <x>, <!">) eq 0
        h = ROL32((h + '&x'), ROL_CONSTANT)
      endif
    endm
    
    h = ROL32(h, ROL_CONSTANT)

    exitm<(h and 0FFFFFFFFh)>
  endm
endif

; return length of string
MSTRLEN macro s:req
  local len
  
  len = 0
  
  forc x, <s>
    if @InStr (1, <x>, <!">) eq 0
      len = len + 1
    endif
  endm
  
  exitm <len>
endm

STRING macro s:req
  db MSTRLEN(s)
  db s
endm

; case insensitive
; converts string to upper case
DLL_HASH macro s:req
  local h
  local char
  
  h = 0
  
  forc x, <s>
    if @InStr(1, <x>, <!">) eq 0
      char = '&x' and 5Fh
      
      h = ROL32((h + char), ROL_CONSTANT)
      h = ROL32 (h, ROL_CONSTANT)
    endif
  endm

  exitm<(h and 0FFFFFFFFh)>
endm

SWAP32 macro x:req
  exitm<((((x) and 0FF000000h) shr 24) or \
         (((x) and 000FF0000h) shr  8) or \
         (((x) and 00000FF00h) shl  8) or \
         (((x) and 0000000FFh) shl 24))>
endm

SWAP64 macro x:req
  exitm<( (SWAP32(x shr 32) or \
          (SWAP32(x) shl 32)))>
endm

; convert ipv4 string to address
; doesn't validate format
INET macro s:req
  local dwIp
  local bOctet
  
  dwIp   = 0
  bOctet = 0
  
  forc x, <s>
    if @InStr (1, <x>, <!">) eq 0
      if @InStr (1, <x>, <.>) eq 1
        dwIp = dwIp or bOctet
        dwIp = dwIp shl 8
        bOctet = 0
      else
        bOctet = bOctet * 10
        bOctet = bOctet + x
      endif
    endif
  endm
  dwIp = dwIp or bOctet
  exitm <SWAP32(dwIp)>
endm

; convert ipv6 string to address
; doesn't validate format
; doesn't handle consecutive colons
INET6 macro s:req
  local dwIp
  local bOctet
  
  dwIp   = 0
  bOctet = 0
  
  forc x, <s>
    if @InStr (1, <x>, <!">) eq 0
      if @InStr (1, <x>, <:>) eq 1
        dwIp = dwIp or bOctet
        dwIp = dwIp shl 8
        bOctet = 0
      else
        bOctet = bOctet * 16
        bOctet = bOctet + x
      endif
    endif
  endm
  dwIp = dwIp or bOctet
  exitm <SWAP32(dwIp)>
endm

; macro same as htons()
MHTONS macro A:req
  exitm <(((A and 0FF00h) shr 8) or \
         (((A and 000FFh) shl 8)))>
endm

; structure used to keep state, x and y
RC4_KEY struc
  x dword ?
  y dword ?
  s byte 256 dup (?)
RC4_KEY ends

MAX_NUM_LEN equ 128 ; this represents 1024 bit number

BIGNUM struc
  len dd ?
  num db MAX_NUM_LEN dup (?)
BIGNUM ends

DH_KEY struc
  p        BIGNUM <>
  g        BIGNUM <>
  pub_key  BIGNUM <>
  priv_key BIGNUM <>
DH_KEY ends

HOME_SPACE struct
  _rcx  QWORD ?
  _rdx  QWORD ?
  _r8   QWORD ?
  _r9   QWORD ?
HOME_SPACE ends
  
REG struc
  lo dw ?
  hi dw ?
REG ends

PUSHAD_STRUCT struc
  _edi  REG  <>
  _esi  REG  <>
  _ebp  REG  <>
  _esp  REG  <>
  _ebx  REG  <>
  _edx  REG  <>
  _ecx  REG  <>
  _eax  REG  <>
PUSHAD_STRUCT ends

LSA_UNICODE_STRING  struct 
  Length_       WORD  ?
  MaximumLength WORD  ?
  Buffer        PWSTR ?
LSA_UNICODE_STRING  ends

PLSA_UNICODE_STRING typedef ptr LSA_UNICODE_STRING
UNICODE_STRING      typedef     LSA_UNICODE_STRING
PUNICODE_STRING     typedef ptr LSA_UNICODE_STRING

LDR_DATA_TABLE_ENTRY  struct 
  InMemoryOrderLinks  LIST_ENTRY  <>
  DllBase             PVOID ?
  EntryPoint          PVOID ?
  SizeOfImage         DWORD ?
  FullDllName         UNICODE_STRING  <>
  BaseDllName         UNICODE_STRING  <>
  Flags               DWORD ?
  LoadCount           WORD  ?
  TlsIndex            WORD  ?
LDR_DATA_TABLE_ENTRY  ends

PLDR_DATA_TABLE_ENTRY typedef ptr LDR_DATA_TABLE_ENTRY

PEB_LDR_DATA  struct 
  Length_                         DWORD ?
  Initialized                     DWORD ?
  SsHandle                        PVOID ?
  InLoadOrderModuleList           LIST_ENTRY  <>
  InMemoryOrderModuleList         LIST_ENTRY  <>
  InInitializationOrderModuleList LIST_ENTRY  <>
  EntryInProgress                 PVOID ?
PEB_LDR_DATA  ends

PPEB_LDR_DATA typedef ptr PEB_LDR_DATA

PEB struct 
  Reserved1     BYTE 2 dup (?)
  BeingDebugged BYTE ?
  Reserved2     BYTE 1 dup (?)
  Reserved3     PVOID 2 dup (?)
  Ldr           PPEB_LDR_DATA ?
PEB ends

PPEB typedef ptr PEB

; size is 28 bytes, sockaddr_in is 16
in6_addr  struct 
  union u
    Byte_ u_char 16 dup (?)
    Word_ u_short 8 dup (?)
  ends
in6_addr  ends

sockaddr_in6  struct 
  sin6_family   SWORD ?
  sin6_port     u_short ?
  sin6_flowinfo u_long  ?
  sin6_addr     in6_addr <>
  sin6_scope_id u_long  ?
sockaddr_in6  ends

SOCKADDR_IN6 typedef sockaddr_in6
