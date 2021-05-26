; Q1 (B): Program to add two numbers [32 bit addition]

dosseg
model small
.8086

.data   ; DATA SEGMENT

; First 32 Bit Number
num1high dw 1254H
num1low dw 25A0H
; Second 32 Bit Number
num2high dw 5835H
num2low dw 3627H
; 'ans' to Store Result of 32 Bit Addition
anshigh dw ?
anslow dw ?
; Carry
carry db 00H

.code    ; CODE SEGMENT
mov ax,@data
mov ds,ax

; Add Lower 16 Bit Part
mov ax,num1low
mov bx,num2low
add ax,bx
; Store Answer in 'anslow'
mov anslow,ax
; Add Higher 16 Bit Part
mov ax,num1high
mov bx,num2high
; Add with Carry [Generated from Addn of Lower Bit]
adc ax,bx
; Store Answer in 'anshigh'
mov anshigh,ax

; If Carry was Generated
jnc skip
mov carry, 01H
skip: mov anshigh,ax

;HLT 
mov ax,4C00h
int 21h
end
