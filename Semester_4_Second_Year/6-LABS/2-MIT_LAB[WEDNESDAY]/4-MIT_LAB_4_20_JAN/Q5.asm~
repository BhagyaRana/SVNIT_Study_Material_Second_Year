;(5) Write a program to Split 8 bit HEX data into two nibbles and store it in memory.

; Load A Number from Location 2000H [ABCD WXYZ]
LDA 2000H
; Store Original Number in Register B [ABCD WXYZ]
MOV B, A
; Mask the Upper 4 Bits 
; (ABCD WXYZ)&(0000 1111) = (0000 WXYZ)
ANI 0FH
; Store at Location 2001H
STA 2001H
;----------------------------------------------------------------
; Restore the Original Number in Accumulator
MOV A, B
; Mask the Lower 4 Bits 
; (ABCD WXYZ)&(1111 0000) = (ABCD 0000)
ANI 0F0H
; Rotote Accumulator Right (0ABC D000)
RRC
; Rotote Accumulator Right (00AB CD00)
RRC
; Rotote Accumulator Right (000A BCD0)
RRC
; Rotote Accumulator Right (0000 ABCD)
RRC
; Store at Location 2002H
STA 2002H
HLT
