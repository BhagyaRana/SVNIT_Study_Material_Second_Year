; Q-(3) 
; 3000H <- (B&C&E), 3001H <- (B|C|E) and 3002H <- (B^C^E)
MVI A,00
; Intialize the Register B with 8-bit [Number 1] at Location 3004h
LDA 3004h
MOV B, A
; Intialize the Register C with 8-bit [Number 2] at Location 3006h
LDA 3006h
MOV C, A
; Intialize the Register E with 8-bit [Number 3] at Location 3008h
LDA 3008h
MOV E, A
; AND Operation
MOV A, B
ANA C
ANA E
STA 3000h
; OR Operation
MOV A, B
ORA C
ORA E
STA 3001h
; XOR Operation
MOV A, B
XRA C
XRA E
STA 3002h
hlt