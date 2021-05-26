; (3) WAP to Subtract Two 8 Bit BCD Numbers.
; Input: Numbers are Stored at Location 2000H & 2001H

LXI H, 2000H
MOV B, M		; First Number in 'B'
INX H
MOV C, M		; Second Number in 'C'
INX H

; Procedure to Find B - C
MVI A, 99H		; A <- 99 [Max BCD]
SUB C		; A <- A - C
DAA			; Decimal Adjust [8 Bit in A -> 2 (4 Bit) BCD]
ADD B		; A <- A + B
DAA			; Adjust to BCD
JNC COMP		; If No Carry => Negative Number [Since A + (B - C) ]
ADI 01H		; A <- A + 1
DAA			; Adjust to BCD
MVI M, 00H		; Positive Sign
INX H		 
JMP STORE		; Store the Final Answer

COMP:	MOV D, A		
		MVI A, 99H	
		SUB D
		MVI M, 01H	; Negative Sign
		INX H
STORE: MOV M, A
HLT

