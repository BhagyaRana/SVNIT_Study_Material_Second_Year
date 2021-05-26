
; (2A)-WAP to find largest number from the array of 8-bit data. 
; Assume suitable memory location for data and result. 

; Input: First Location 2000H = Contain the Number of Elements('n') in Array
; Followed By 'n' Numbers from Location [2001,2002,...,200n]

; Output: At Location 3000H = Largest/Smallest Element in Array

; Input 'n'
LDA 2000H
; Intialise Counter C
MOV C, A
; Intialise the H-L Pair Register
LXI H, 2000H
; Let the First Element of Array be Highest/Smallest
MOV A, M
; Decrement the Counter [Since One Number Compared]
DCR C

LOOP: INX H    ; Point it to Next Location
      MOV B, M ; Trasfer the Contents in Register B
      CMP B    ; (A - B) [A==B,Z=1,CY=0] [A<B,CY=1] [A>B,CY=0]
      JNC SMALLER ;If Carry!=1,i.e. CY=0 [B<=ANS]
      MOV A, B

SMALLER: DCR C       ; Decrement the Counter
	 JNZ LOOP    ; Until C Doesn't Reach Zero
	 STA 3000H   ; Largest Number Stored at Location 3000H
HLT


