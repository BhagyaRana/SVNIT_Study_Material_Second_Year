;(1) Write a program to Add ten 8-bit numbers stored in memory starting from 3000H.
;Store your result at 3050H.

; 10 Numbers to Sum
MVI D, 0AH
; Initialize the H-L Register Pair to Point at Location 3000H
LXI H, 3000H
; Initialise the Sum and Carry
MVI A,00H ; SUM
MVI C,00H ; CARRY

LOOP: ADD M ; Add the Data Pointer By H-L to Acc.
      INR L
      JNC no_carry
      ; Otherwise Carry Generated
      INR C ; C <- C + 1
      
no_carry: DCR D ;Decrease the Number of Element in Array Counter
	  JNZ LOOP ; Until it Reaches Zero

; Sum is Stored at Location 3050H
STA 3050H
MOV A, C
; Carry is Stored at Location 3051H
STA 3051H
HLT

