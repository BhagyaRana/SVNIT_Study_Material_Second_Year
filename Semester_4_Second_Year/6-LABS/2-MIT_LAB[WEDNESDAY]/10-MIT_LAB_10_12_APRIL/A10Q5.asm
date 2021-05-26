; Q-(5) Program for division of unsigned 8-bit numbers

model small
.stack 100
.8086

.data
num1 db 9DH
; This Should not be Zero [Divide by Zero Error]
num2 db 1CH
quotient db ?
remainder db ?

.code
mov ax,@data
mov ds,ax

; Making it 16 Bit [00 num1] [(16 Bit)/(8 Bit)]
mov ah, 00H
mov al, num1

div num2

mov quotient, al
mov remainder, ah

mov ax,4C00h
int 21h
end
