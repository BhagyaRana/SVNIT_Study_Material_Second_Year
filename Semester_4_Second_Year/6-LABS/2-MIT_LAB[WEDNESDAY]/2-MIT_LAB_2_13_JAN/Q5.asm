
; Q-(5) Write a program to shift 8-bit no by three bits right. Assume data
; is in register C

MVI A,00
; Intialise the Register C with 8-Bit Number at Location 3000h
LDA 3000h
MOV C,A
; Rotate Accumulator Right [1st Time] [Accumulator has C's Data]
RAR
; Rotate Accumulator Right [2st Time]
RAR
; Rotate Accumulator Right [3st Time]
RAR
;Store the Results at Location 3002h
STA 3002h
hlt


