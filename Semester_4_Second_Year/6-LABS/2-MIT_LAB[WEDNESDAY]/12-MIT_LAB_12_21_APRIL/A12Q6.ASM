;Q-(6) Write a Program to reverse a given string.

.model small
.stack 100
.8086

.data
; Length of String
len dw 000CH 
; Source String
str1 db " ecnalubma $"
; Reverse String
str2 db "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"

.code
mov ax,@data
mov ds,ax

mov es,ax
mov cx,len
mov si,offset str1
add si,len
mov di,offset str2

cld
up: mov al,[si]
    mov [di],al
    inc di
    dec si
    loop up

; Print the Reverse String
mov ah,09h
mov dx,offset str2+3
int 21h

mov ax,4c00h
int 21h
end
