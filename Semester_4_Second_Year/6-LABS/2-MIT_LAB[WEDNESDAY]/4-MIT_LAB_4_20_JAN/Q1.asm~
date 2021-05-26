;(1) Write a program to check the 4th bit of 8-numbers stored from location 2000H.
;[Done Without JUMP Statement] [U19CS012]

; INPUT : 8 Numbers will be Taken from Location [2000-2008]

; OUTPUT:
; If 4th Bit is Set, 01H will be Stored
; Otherwise if 4th Bit is Not Set, 00H will be stored

; Intialize H to Point to Location 2000H
LXI H, 2000H;
; ---------------------------------------------------------

MOV A,M
;To Check 4th Bit, We will AND with 0000 1000 = 08H
ANI 08H
JZ print1 ;If Accumulator is Zero, Jump to Label
MVI A, 01H ; Control Reaches Here Only, if A != 0
; Print the Output at Location 01H [I/O Port]
print1: OUT 01H
; Increment H to Point to Next Location
INX H

; ------------------PATTERN REPEATS------------------------
MOV A,M
ANI 08H
JZ print2
MVI A, 01H
print2: OUT 02H
INX H
; ---------------------------------------------------------
MOV A,M
ANI 08H
JZ print3
MVI A, 01H
print3: OUT 03H
INX H
; ---------------------------------------------------------
MOV A,M
ANI 08H
JZ print4
MVI A, 01H
print4: OUT 04H
INX H
; ---------------------------------------------------------
MOV A,M
ANI 08H
JZ print5
MVI A, 01H
print5: OUT 05H
INX H
; ---------------------------------------------------------
MOV A,M
ANI 08H
JZ print6
MVI A, 01H
print6: OUT 06H
INX H
; ---------------------------------------------------------
MOV A,M
ANI 08H
JZ print7
MVI A, 01H
print7: OUT 07H
INX H
; ---------------------------------------------------------
MOV A,M
ANI 08H
JZ print8
MVI A, 01H
print8: OUT 08H
INX H
; ---------------------------------------------------------

HLT
