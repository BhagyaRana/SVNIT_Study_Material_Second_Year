
; Q-(4) Write a program to shift 8-bit no by three bits left. Assume data
; is in register C

MVI A,00
; Intialise the Register C with 8-Bit Number at Location 3000h
LDA 3000h
MOV C,A
; Rotate Accumulator Left [1st Time] [Accumulator has C's Data]
RAL
; Rotate Accumulator Left [2st Time]
RAL
; Rotate Accumulator Left [3st Time]
RAL
;Store the Results at Location 3002h
STA 3002h
hlt

