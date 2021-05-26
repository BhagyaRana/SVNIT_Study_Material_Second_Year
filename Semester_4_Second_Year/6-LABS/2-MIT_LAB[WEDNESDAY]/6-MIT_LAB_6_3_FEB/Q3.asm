;(3) WAP to find Factorial of a given number using Call and Subroutine.

; Input    : Enter a Number 'n' at Location 2000H 
; Output  : Output the answer of 'n!' at Location 2002H

; Load 'n' From Location 2000H
LDA 2000H
; Check if Number is Less than 2 [0!=1!=1]
CPI 02H 
JC zerofac

MOV B, A   ; Copy 'n' to B = Counter
LXI D, 01H ; DE Register Pair Stores Our Factorial Answer

LOOP: CALL factorial ; Call the Sub-Routine [Function]
	   DCR B
	   JNZ LOOP
; After the Loop Ends, HL Rp Will have Answer
SHLD 2002H
HLT

zerofac: LXI H, 0001H ; Store Result = 1 = 0! = 1! 
	      SHLD 2002H
HLT

; Factorial Function [Sub-Routine] ; [DE] <- [DE] * [B]
; Multiply Reg B [Value] with "DE" Rp and Store the Result Back in "DE" Rp

factorial: MOV A, B
	       LXI H, 00H
		UP: DAD D
      		      DCR A
                      JNZ UP
		; Exhange HL Rp <-> DE Rp
                XCHG
RET ; Return after Function Call