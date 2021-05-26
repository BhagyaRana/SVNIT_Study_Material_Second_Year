
; Q-(1) WAP to convert a given number of binary data bytes into their BCD equivalents
; & Store them as unpacked BCDs in the output buffer [3000H Onwards]
; The number of data bytes is specified in register D in the main program. 

MVI D, 05H   	; COUNTER = Number of Data Bytes [Elements to Convert] 
LXI H, 2000H  	; Starting Address of First Data Byte	
LXI B, 3000H	; Starting Address of Destination Location

MAIN:	MOV A, M	; Get the Data in Accumulator
      		CALL BIN_TO_BCD
		DCR D		; Decrement the Counter 'D'
		INX H		; [HL] Points to Next Location
		JNZ MAIN ; Until Counter 'D' Reaches Zero, Keep on Reading Data
HLT

BIN_TO_BCD:	PUSH H		; Store HL Location Safely
			MVI H, 00H	; Hundreds Place Counter
			MOV L, H		; Tens Place Counter

HUNDRED:	CPI 64H 		; Compare with 100
			JC TENS		; If Less than 100, Then CY = 1, So Goto Tens Place
			SUI 64H		; Subtract 100
			INR H		; Increment Hundreds Counter
			JMP HUNDRED

TENS: 		CPI 0AH		; Compare with 10
			JC  UNITS	; If Less the 10, Then CY = 1, So Goto Units Place
			SUI 0AH		; Subtract 10
			INR	L		; Increment Tens Counter
			JMP TENS

UNITS: 		STAX B		; Push the Units Digit = A at Location Pointer by BC Pair
			INX B
			MOV A, L		; Get Tens Counter
			STAX B
			INX B
			MOV A, H	; Get Hundred Counter
			STAX B
			INX B
			POP H		; Get the Original [HL] Location Back 
RET 
	 