
;Q-(7) Write a Program to find Largest of two 8-bit numbers.

	MVI A,00h
	LDA 3000h	; loads value at Memory Location 3000h 
	MOV B, A	; Store it in Reg B			     [B <- Num 1]
	LDA 3001h	; loads value at Memory Location 3001h [Acc <- Num 2]
	
	; If A>B , then CF = 0 and if A<B, then CF = 1
	CMP B		; Compare B with A

	JNC here	; Jump if Carry flag is Reset (Carry flag = 0)
	MOV A, B	; Num1 is Greater 

here: STA 3005h	; store result at Memory Location 3005
	HLT	;Terminates the program

