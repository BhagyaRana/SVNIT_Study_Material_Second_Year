
; (2) - A set of ten BCD readings is stored in the Input Buffer.
;Convert the numbers into binary and add the numbers. 
;Store the sum in the Output Buffer, the sum can be larger than FFH.

; INPUT : Enter 10 Numbers from Location 2000H Onwards
; OUTPUT: Get Sum at Address 3001 & 3000  

MVI B, 0AH 		; Count of Numbers to Sum
LXI D, 2000H	; Location of First Data Byte
LXI H, 0000H	; [HL] Pair Stores , Sum = 0 [Intially]

MAIN:	CALL BCD_TO_BIN
	    	; The Binary Number is Stored in A
	    	MOV C, A  	; Store the Binary Number in C
		MOV A, B		; Store the Counter 'B'
		MVI B, 00H	; [BC] = [0000 Binary_Answer]
		DAD B 		; [HL] <- [HL] + [BC]
		INX D		; Point to Next Location
		MOV B, A		; Restore Back the Counter Value in B
		DCR B		
		JNZ MAIN
		SHLD 3000H	; Answer of Sum is Stored at Location 3000H
HLT

BCD_TO_BIN:		PUSH B	; Store Value of BC Register in Stack
				PUSH H	; Store Value of HL Register in Stack [To Free Registers]
				LDAX D	; Get Data from Location Pointed by [DE]
				ANI 0FH	; Mask Upper 4 Bits : [0000 abcd] => Get Lower 4 Bits	    	
				MOV B, A ; B <= Lower 4 Bits
				LDAX D 	; Get Data from Location Pointed by [DE] 
				ANI 0F0H; Mask Lower 4 Bits : [abcd 0000] => Get Upper 4 Bits
				RRC		; [0abc d000]
				RRC		; [00ab cd00]	
				RRC		; [000a bcd0]
				RRC		; [0000 abcd]			
				MOV H, A ; H <= Upper 4 Bits
				MVI C, 09H 
MULTIPLY:		ADD H	; (Upper 4 Bits)x10 + (Lower 4 Bits)
				DCR C					
				JNZ MULTIPLY
				ADD B	; Add Lower 4 Bits
				POP H	; Restore Back the [HL] Values
				POP B	; Restore Back the [BC] Values
				RET
