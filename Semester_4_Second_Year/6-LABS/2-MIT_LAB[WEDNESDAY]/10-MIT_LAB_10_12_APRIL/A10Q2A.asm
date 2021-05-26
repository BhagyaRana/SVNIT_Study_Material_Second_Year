; Q2 (A) : Program to subtract two numbers [16 bit subtraction]

dosseg
model small
.8086

.data   ; DATA SEGMENT
num1 dw 9876H
num2 dw 1234H
ans dw ?
borrow db 00H

.code   ; CODE SEGMENT
mov ax,@data
mov ds,ax

mov ax,num1
mov bx,num2

sub ax,bx

jnc skip
mov borrow, 01H
skip: mov ans,ax

; HLT
mov ax,4C00H
int 21h
end
