
;(4) WAP to clear the CY flag,to load number FFH in register B,and increment B.
; If the CY flag is set, display 01 at the output port,
; otherwise, display the contents of register B.

; Load Number FFH in Register B 
MVI B, 0FFH

; Increment Register B 
INR B ; B = 00H

; Comment/Uncomment Based on Making Carry Flag = Set/Unset
STC 	; Set Carry Flag Cy = 1
CMC	; Clear Carry Flag Cy = 0

; Jump on Carry CY=1
JC Disp1 
; If Carry CY=0, Display B
JNC Disp2 

Disp1: MVI A,01h
       OUT 01h
       JC exit1
Disp2: MOV A,B
       OUT 01H
       JNC exit1

exit1: NOP 

HLT
