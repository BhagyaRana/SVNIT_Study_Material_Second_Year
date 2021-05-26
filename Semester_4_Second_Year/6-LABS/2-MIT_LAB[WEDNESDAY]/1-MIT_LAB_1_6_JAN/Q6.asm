;Q-(6) Write a program to subtract two 16 bit numbers.
; Numbers are stored in four consecutive memory location as 8-bit numbers. (Use instruction SBB) 
MVI A,00
; Intiatilize the Register B with 16-bit [Number 1](lsb) at Location 3000h
LDA 3000h
MOV B, A
; Intiatilize the Register C with 16-bit [Number 1](msb) at Location 3001h
LDA 3001h
MOV C, A
; Intiatilize the Register D with 16-bit [Number 2](lsb) at Location 3002h
LDA 3002h
MOV D, A
; Intiatilize the Register E with 16-bit [Number 2](msb) at Location 3003h
LDA 3003h
MOV E, A

; Subtract (lsb) of Two Numbers
MOV A,B ; A <- B
SBB D ; A <- A-D
; Store the LSB Result at location 3005h
STA 3005h

MVI A, 00
; Subtract (msb) of Two Numbers
MOV A,C ; A <- B
SBB E ; Subtract with Borrow
; Store the MSB Result at location 3005h
STA 3006h
hlt
