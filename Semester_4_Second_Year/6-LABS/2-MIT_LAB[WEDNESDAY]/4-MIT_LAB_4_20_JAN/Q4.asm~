;(4) Write a Program to calculate the factorial of a number between 0 to 8. 

; Take Input [0-8] From Location 2000H
LDA 2000H

CPI 02H ; Check if Number is Greater than 1
JC zerofac

; Store it in Register B
MOV B, A
; Intialize Register Pair H-L [00 00] 
LXI H, 0000H
; Intialize Register Pair D-E [00 01]
LXI D, 0001H
; Increment B
INR B

Multiply: DCR B
	      ; Check if B is Zero or Not
	      JZ print ; If B is Zero Jump to Print Answer
	      ; Copy B's Value in C
	      MOV C, B
	      ; Increment C		
              INR C
	      ; Intialize Register Pair H-L [00 00] 
	      LXI H, 0000H

Addition: DCR C
	       ; Check if C is Zero or Not
	       JZ addbreak  ;If C is Zero, goto addbreak
		; [HL] = [HL] + [DE]               
		DAD D
	       JMP Addition

addbreak: MOV E, L
		 MOV D, H
		JMP Multiply

zerofac: LXI H, 0001H ;Store Result = 1 = 0! =1!

print: SHLD 2002H
HLT