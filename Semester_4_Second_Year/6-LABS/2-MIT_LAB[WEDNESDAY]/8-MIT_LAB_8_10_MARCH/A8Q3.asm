
; (Q)-3 A set of ASCII Hex digits is stored in the Input Buffer memory.
; Write a program to convert these numbers into Binary. 
; Add these numbers in Binary, and store the result in the Output-Buffer memory.

MVI B, 0AH 		; Counter
MVI C, 00H		; Register to Store Sum 
LXI D, 2000H	; Source Pointer for ASCII [INPUT]
LXI H, 3000H	; Destination Pointer for Equivalent Binary [OUTPUT]

MAIN:	LDAX D		; Get the Input in Accumulator
		CALL ASC_TO_BIN
		MOV M, A	; Storing the Binary Equiv to Location by [HL]
		MOV A, C		; Get the Sum
		ADD M		; Add the Binary Equiv to Sum
		MOV C, A		; Store C <- C + Binary_Equiv
		INX H		; Point to Next Location [INPUT]
		INX D		; Point to Next Location [OUTPUT]
		DCR B		; Decrement the Counter
		JNZ MAIN
MOV M, C			; Final Sum Stored
HLT

; INPUT (A) 	: ASCII Code
; OUTPUT (A) 	: BINARY Equivivalent 

ASC_TO_BIN: SUI 30H	; Subtract 30H to Get Numeric Value
			CPI 0AH	; If Less than 10, No Need to Convert [Return]
			RC
			SUI 07H	; For A - F
			RET
