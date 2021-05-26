
;(5) Write a program to mask lower bit of an 8-bit number.

; Load HL Pair with Data 3000H
LDA 3000H
; Copy the Number to Reg B [For Reference] 
MOV B, A
; AND Immediate F0H = (1111 0000) with Accumulator
ANI 0F0H	 ; Lower bit Masked 
; Store Result at Memory Location 3001H
STA 3001H 
HLT
