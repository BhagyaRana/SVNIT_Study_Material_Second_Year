; Q-2) Write An 8085 Program To Check The Substring From Given String
; Given String: "Hello World" 	<= s
; Substring: "Wor"			<= substr

LXI H, 2000H	; Starting String Location
LDA 3000H		; Substring to Find Location
MOV B, A		; Store Starting Charater in B <- A

MAIN:	MOV A, M	; Chech s[i] with 1st character of substr 'Wor' i.e. W
		CMP B
		CZ	CHECK	; Check if it is Valid Substring
		MOV A, M
		INX H
		CPI 0DH		; Check for End of String 
		JNZ MAIN
HLT

CHECK:	PUSH H		; Safely Store HL
		LXI D, 3000H	; Location of Sub-String

LOOP:	LDAX D			; A = substr[j]
		CMP M			; Compare the substr[j] & s[i]
		JNZ NOTEQUAL	; If substr[j] != s[i] Then it can't be Substring 
		INX D
		INX H
		LDAX D
		CPI 0DH
		JNZ LOOP
; Control Reaches Here -> Substring is Found
POP H	
XCHG		; [DE] <-> [HL]
INX H	
INX H
MOV M, E	; (lower nibble) Store s[i]'s Location to [end of substring + 2] Location 
INX H	
MOV M, D	; (upper nibble)
HLT

NOTEQUAL:	POP H	; Restore [HL] and Return
			RET	