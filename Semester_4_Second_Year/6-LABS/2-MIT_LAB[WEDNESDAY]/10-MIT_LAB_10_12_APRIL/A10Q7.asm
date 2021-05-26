; Q-(7) Program for division of signed 8-bit numbers

.model small
.stack 100
.8086

.data
num1 db -82H 
num2 db 05H 
quotient dw ?
remainder dw ?

.code
mov ax, @data
mov ds, ax

mov ah, 00H
mov al, num1

; CBW (convert byte to word) [Sign Preserving]
cbw
idiv num2

mov quotient, ax
mov remainder, dx

mov ax, 4C00H 
int 21h
end
