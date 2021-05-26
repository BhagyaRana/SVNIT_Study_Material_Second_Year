; Q - (6) Program for division of unsigned 16-bit numbers

model small
.stack 100
.8086

.data
num1 dw 2A81H
num2 dw 003CH
quotient dw ?
remainder dw ?

.code
mov ax,@data
mov ds,ax

mov ax,num1
div num2

mov quotient,ax
mov remainder,dx

mov ax,4c00h
int 21h
end
