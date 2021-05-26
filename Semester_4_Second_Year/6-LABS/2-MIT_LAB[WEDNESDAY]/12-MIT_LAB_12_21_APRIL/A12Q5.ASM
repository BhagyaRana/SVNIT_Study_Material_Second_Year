; 5. Write a Program to move a string from source to destination.

.model small
.stack 100
.8086

.data
len db 11h	; 11h = 17 Length of String
; Source
str1 db "this is a string $"
; Destination
str2 db "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"

.code
mov ax,@data
mov ds,ax

mov es,ax
mov ch,00h
mov cl,len  ; Initialize Counter

; Initialize [SI] & [DI]  
mov si,offset str1
mov di,offset str2

; Clear Direction Flag
cld

up: movsb
loop up

; Print the Answer
mov ah,09h
mov dx,offset str2
int 21h

mov ax,4c00h
int 21h
end
