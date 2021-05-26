; Q-(4) Program to multiply unsigned 16-bit numbers

model small
.8086

.data
num1 dw 023AH
num2 dw 0072H
ans dw ?

.code
mov ax, @data
mov ds, ax

mov ax, num1
mul num2

mov ans,ax

mov ax,4C00h
int 21h
end
