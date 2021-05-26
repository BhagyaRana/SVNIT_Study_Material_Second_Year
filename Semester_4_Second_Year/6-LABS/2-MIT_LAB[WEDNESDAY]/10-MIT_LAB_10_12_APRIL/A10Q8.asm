; Q-(8) Program for division of signed 16-bit numbers

.model small
.stack 100
.8086

.data
num1 dw -4FF1H
num2 dw 0512H

quotient dw ?
remainder dw ?

.code
mov ax, @data
mov ds, ax

mov ax, num1

; CWD (convert word to doubleword)
cwd
idiv num2

mov quotient, ax
mov remainder, dx

mov ax, 4C00H
int 21h
end