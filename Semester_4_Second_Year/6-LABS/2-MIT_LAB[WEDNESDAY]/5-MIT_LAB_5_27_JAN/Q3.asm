;(3) Write a Program to search an 8-bit number from the array of 8-bit data.

; Input: First Location 2000H = Element to Search
; Location 2001H Contain the Number of Elements('n') in Array
; Followed By 'n' Numbers from Location [2002,2003,...,200(n+1)]

; Output: At Location 3000H = Whether Element Found or Not
; Output = '1' Indicates Element Found Else '0' Indicates Not Found Case

; To Intialise the Answer Location [To Reset the Answer of Previous Execution]
MVI A, 00H
STA 3000H

LDA 2000H
; D is the Element to Be Searched in Array
MOV D, A
; Input 'n'
LDA 2001H
; Intialise Counter C
MOV C, A

; Intialise the H-L Pair Register
LXI H, 2001H
; Let the First Element of Array be Compared

MOV A, M
CMP D
JNZ NOTFOUND
JMP FOUND

NOTFOUND: DCR C ; Decrement the Counter [Since One Number Compared]
		    JMP LOOP

LOOP: INX H        ; Point it to Next Location
          MOV A, M   ; Trasfer the Contents in Register A
          CMP D         ; (A - D) [A==D,Z=1,CY=0] [A<D,CY=1] [A>D,CY=0]
          JZ FOUND ; Z == 1 ; Number Found
	  XRA A
          DCR C         ; Decrement the Counter
          JNZ LOOP  ; Until C Doesn't Reach Zero
	  HLT

FOUND: MVI A, 01H 
             STA 3000H
	     HLT


