; Q2 (B) : Program to subtract two numbers [32 bit subtraction]

dosseg
model small
.8086

.data   ; DATA SEGMENT
; Double Word [DD]
num1 dd 97DE207AH
num2 dd 46AC1313H
ans dd ?
borrow db ?

.code   ; CODE SEGMENT
mov ax,@data
mov ds,ax

mov dl,00h  ; Borrow [Intial]

mov ax,word ptr num1
mov bx,word ptr num2

sub ax,bx

mov word ptr ans,ax

mov ax,word ptr num1+2
mov bx,word ptr num2+2
; Subract with the Borrow from Previous Subtraction
sbb ax,bx
mov word ptr ans+2,ax

jnc skip
inc dl  ; Increment the Borrow
skip: mov borrow,dl

; HLT
mov ax,4C00h
int 21h
end
