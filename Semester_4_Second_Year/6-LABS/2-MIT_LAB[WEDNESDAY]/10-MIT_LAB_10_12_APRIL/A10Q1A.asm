; Q1 (A): Program to add two numbers [16 bit addition]

dosseg
model small ; code & Data Segment fits in 64 KB
.8086

.data   ; DATA SEGMENT

; Intialise the First Number [QW - (Define Word)]
num1 DW 1234H
; Intialise the Second Number
num2 DW 5140H
; Variable ('ans') to Store the Answer
ans DW ?
; Declare carry as an 8-bit variable with a value 0
carry DB 00H

.code   ; CODE SEGMENT

MOV AX, @DATA
MOV DS, AX

; Move the First Number (num1 data-word) in 'ax' reg 
    MOV AX, num1
; Move the Second Number (num2 data-word) in 'bx' reg
    MOV BX, num2
; 16 Bit Addition
    ADD AX, BX
    JNC skip
    MOV carry, 01H
; Store the Result in 'ans' data-word
skip: MOV ans, AX

; HLT
; 4CH is the parameter for the terminate function
MOV AH, 4CH 
; If AL is 00h then the program terminated without an error.
MOV AL, 00H
INT 21h
END
