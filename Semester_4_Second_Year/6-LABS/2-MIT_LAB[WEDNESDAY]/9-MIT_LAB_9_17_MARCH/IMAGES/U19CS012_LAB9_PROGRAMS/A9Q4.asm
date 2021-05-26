;(4) - WAP to Convert 8 Bit BCD Number to its Respective ASCII Code.

; Input Memory Location : 2000H
; Output Memory Location : 3000H & 3001

LXI H, 2000H	; Packed BCD Number's Location
CALL BCD2BIN
INX H
INX H
MOV D, A		; Storing Binary Number in 'D' [For Reference]

; Ones and Ten's Digit are in 'B' & 'C'
MOV A, C		; A <- C
ADI 1EH		; 1EH = 30 & DIGIT + 30 -> ASCII
MOV M, A		; Tens Digit Stored
INX H		; Next Location
MOV A, B		; A <- B
ADI 1EH		; Get ASCII by Adding 1EH
MOV M, A		; Ones Digit Stored
HLT

BCD2BIN:	MOV A, M  	; [abcd efgh]
			ANI 0FH		; Mask Upper 4 Bits [abcd efgh & 0000 1111] 
			MOV C, A		; Store it in C [0000 efgh]
			MOV A, M	; [abcd efgh]
			ANI 0F0H	; Mask Lower 4 Bits [abcd efgh & 1111 0000]
			RRC			; [0abc d000]
			RRC			; [00ab cd00]
			RRC			; [000a bcd]
			RRC			; [0000 abcd]
			MOV B, A		; Tens Digit 
			MVI D, 09H	; A <- A*10
MUL: 		ADD B
			DCR D
			JNZ MUL
			ADD C		; Add Ones Digit at Last
RET
