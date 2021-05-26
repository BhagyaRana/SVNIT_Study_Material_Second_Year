; (4) WAP for Fibonacci Series using Call and Subroutine.

; Input (Location 2000H)   : Limit 'n' Upto Which Fibonaaci Number is to be found  
; Output (Location 2001H Onwards) : [0, 1, 1, 2, 3, 5, 8, 13, 21, ... ]
; LIMITATION:   n <= 14

LDA 2000H 	     ; Input the Limit [n] Upto Which Fibonacci Number Need to be Printed
DCR A 	     ; First Fibonacci is 0
MOV E,A             ; Copy 'n-1' to E
CALL fibonacci     ; CALL the Sub-Routine
HLT

fibonacci: LXI H, 2002H          ; HL = 3000H
	       MVI M, 01H	       ; M = 01 [2nd Element]
	       MOV B, M                 ; B = 01
               DCR E                       ; E--
	       JZ return                  ; IF Z==1 => Return 
		INX H			; HL Points Next Location
		MVI M, 01H		; M = 01 [3rd Element]
		MOV C, M		; C = M
		DCR E			; E--
		MVI A, 00H		; A = 00H
LOOP: 	ADD B			; A = A + B
		ADD C 			; A = A + C
		; Sum of Previous Two Terms
		INX H   			; HL Points Next Location
		MOV M, A		; M = A 
		MOV B, C 		; B = C [Prev]
		MOV C, A			; C = A [Curr]
		MVI A, 00H		; A = 00H
		DCR E			; E--
		JNZ LOOP		; IF Z != 0 => LOOP
return: RET				; End of Sub-Routine
	