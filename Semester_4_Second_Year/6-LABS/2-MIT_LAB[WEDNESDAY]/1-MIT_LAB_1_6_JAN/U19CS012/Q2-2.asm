; Q-(2)Write a program to add two 8-bit numbers. Store the result at one memory location.

; Method (2) : Data from Register at Address 3000h & 3002h

MVI A,00
; Intiatilize the Register B with 8-bit [Number 1] at Location 3000h
LDA 3000h
MOV B, A
; Intiatilize the Register D with 8-bit [Number 2] at Location 3002h
LDA 3002h
MOV D, A
; Reset the Accumulator
MVI A,00
; Add B to Accumulator
ADC B
; Add D to Accumulator
ADC D
; Store Result from Accumulator at Location 3004h
STA 3004h

hlt