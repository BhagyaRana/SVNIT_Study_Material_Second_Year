
;(5) WAP to find Multiplication of Two 8-Bit Numbers using Call and Subroutine.

; INPUT: Enter Two Numbers to Multiply at Location 2000H & 2001H
; OUTPUT: Result is Shown at Two Location (2004)H [AA] & (2003)H [BB]  [AA BB]H

LXI H, 2000H
MOV B, M	; First Number = Register B
INX H
MOV C, M      ; Second Number = Register C

MVI E, 00H

CALL MULTIPLY

INX H 	; Extra Space
; Final Result
INX H	; 2003H
MOV M, A
INX H
MOV M, E      ; 2004H
HLT

; B*C = Adding 'B',  C times to Accumulator
MULTIPLY: MVI A, 00H
		  LOOP: ADD B
			    JNC SKIP ; If No Carry, Jump to SKIP
			    INR E 	; Add it to Carry
		  SKIP: DCR C	; Decrement the Counter
			    JNZ LOOP
		  RET	; Return from Sub-Routine