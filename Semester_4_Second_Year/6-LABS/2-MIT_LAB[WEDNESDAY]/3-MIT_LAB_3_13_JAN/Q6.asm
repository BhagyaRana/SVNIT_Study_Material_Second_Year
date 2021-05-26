
;(6) WAP to Load two unsigned numbers in reg. B and reg. C, respectively.
; Subtract C from B.
; If the result is in 2’s complement, 
; convert the result in absolute magnitude and display it at PORT 1,
; otherwise, display the positive result. 
; Execute the program with the following sets of data.

; Load Value from Location 3000H for Reg B
LDA 3000H
MOV B,A
; Load Value from Location 3001H for Reg C
LDA 3001H
MOV C,A

MOV A, B
SUB C

; If Carry is Not Set, Jump to Output the Result
JNC print

; Otherwise Take 2's Complement
; Complement the Accumulator [1's Complement]
CMA
; Add 1 to (1's Complement)
ADI 01H

print: OUT 01H

HLT

