; 5. Write a Program to move a string from source to destination.

.model small
.stack 100
.8086

.data
; 'n' in the Question
len db 00h	; 1Fh = 31 characters (Length of String to be copied)
; Source
str1 db "MICROPROCESSOR AND INTERFACING$"
; Destination
str2 db "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"

.code
mov ax,@data
mov ds,ax

mov es,ax
mov ch,00h
mov cl,len  ; Initialize Counter

cmp cl,00H
je here

; Initialize [SI] & [DI]  
mov si,offset str1
mov di,offset str2

; Clear Direction Flag
cld

up: movsb
loop up

here:
; Print the Answer
mov ah,09h
mov dx,offset str2
int 21h

mov ax,4c00h
int 21h
end
