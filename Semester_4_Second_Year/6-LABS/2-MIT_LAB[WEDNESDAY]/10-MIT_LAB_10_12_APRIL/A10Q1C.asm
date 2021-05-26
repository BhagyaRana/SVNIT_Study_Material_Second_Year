; Q1 (C): Program to add two numbers [32 bit addition Using DD]

dosseg
model small
.8086

.data   ; DATA SEGMENT
; Double Word [DD]
num1 dd 123403A0H
num2 dd 0ABC0FFFH
; Answer & Carry
ans dd ?
carry db ?

.code   ; CODE SEGMENT
mov ax,@data
mov ds,ax
mov dl, 00H

; Intialize the Word Pointers
mov ax,word ptr num1
mov bx,word ptr num2
add ax,bx

mov word ptr ans,ax
mov ax,word ptr num1+2
mov bx,word ptr num2+2
; Add the Carry of Previous Lower 16 Bit Part
adc ax,bx
mov word ptr ans+2,ax

jnc skip
inc dl  ; Increment the Carry
skip: mov carry, dl

; HLT
mov ax,4C00h
int 21h
end
