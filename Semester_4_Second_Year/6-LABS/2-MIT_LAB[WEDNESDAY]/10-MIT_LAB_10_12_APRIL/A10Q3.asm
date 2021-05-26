; Q-(3) Program to multiply signed 16-bit numbers

dosseg
model small
.8086

.data   ; DATA SEGMENT
num1 dw 0421H
num2 dw 003EH
ans dw ?

.code   ; CODE SEGMENT
mov ax,@data
mov ds,ax

mov ax,num1
imul num2

mov ans, ax

mov ax,4C00h
int 21h
end
