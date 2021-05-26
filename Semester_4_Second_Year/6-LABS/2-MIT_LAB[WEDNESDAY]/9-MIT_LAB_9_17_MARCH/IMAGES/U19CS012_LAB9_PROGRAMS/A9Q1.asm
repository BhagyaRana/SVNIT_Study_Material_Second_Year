
; ASSIGNMENT 9 Q1

; (Q1) The Given String Is Stored At Memory Location 1000 Onwards:
; ”Microprocessor And Interface” Ended With ‘0dh’.
; WAP To Count Occurrences Of Each Character In Given String [Frequency Array of [a-z] & [A-Z]]
; Output Is Displayed From Memory Location 2000.

; Initialise [H-L] to Point to First Memory Location
LXI H, 1000H

MAIN:	MOV A, M		; A <- [M]
		CALL ASCII		; Convert it to ASCII
		MOV A, M		; A <- [M]
		INX H			; Point to Next Character
		CPI 0DH			; Compare with 14
		JNZ MAIN		
HLT

; Get the Extra Number from 'A' [Eg: 'B' = 1, a = '32']
ASCII:	CPI 41H 			; ASCII OF A = 65 = (41)H & 'a' = 97 =  
		RC				; If White Space [ASCII = 32 = 02H] is Encountered,
						; [02H - 41H < 0 & C = 1]  then Return
		SUI 41H			; Otherwise Subtract (41)H
		JMP STORE		; Store it in M
RET

STORE:	LXI D, 2000H		; Intial Location for Output 
		MOV E, A			; Increment E <- A like 2000 D = 20 & E = 00 => A  
		LDAX D			; Store the Frequency [DE] -> A
		INR A			; Increment the Frequency A++
		STAX D			; Store the Frequency back [DE] <- A
		RET 	