;(2) WAP to swap lower 4 bit nibble with upper 4 bit nibble of 
; 8 bit data at memory location 2100H and place a result to location 2101H.

; Load the 8 bit Number from Location 2100H
LDA 2100H ; ABCD WXYZ

; Store Original Number in Temporary Register B
MOV B, A   ; ABCD WXYZ
; --------------------------------------------------------
; (ABCD WXYZ)&(0000 1111) = (0000 WXYZ)
ANI 0FH ; To Mask the Upper 4 Bit Nibble

; Rotate Accumulator Left (Z000 0WXY)
RAL
; Rotate Accumulator Left (YZ00 00WX)
RAL
; Rotate Accumulator Left (XYZ0 000W)
RAL
; Rotate Accumulator Left (WXYZ 0000)
RAL
; Store (WXYZ 0000) in Register C
MOV C, A ;
; --------------------------------------------------------
; Now Get the Orginal Number Back in Accumulator
MOV A, B ; ABCD WXYZ

; (ABCD WXYZ)&(1111 0000) = (ABCD 0000)
ANI 0F0H ; To Mask the Lower 4 Bit Nibble

; Rotate Accumulator Right (0ABC D000)
RAR
; Rotate Accumulator Right (00AB CD00)
RAR
; Rotate Accumulator Right (000A BCD0)
RAR
; Rotate Accumulator Right (0000 ABCD)
RAR
; --------------------------------------------------------
; Now OR it with C
; A(0000 ABCD)|C(WXYZ 0000) = (WXYZ ABCD)
ORA C
STA 2101H
HLT