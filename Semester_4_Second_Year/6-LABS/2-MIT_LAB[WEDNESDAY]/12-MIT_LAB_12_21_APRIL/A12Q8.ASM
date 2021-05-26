; (8) Write a Program to merge two strings entered through keyboard.

.model small
.stack 100
.8086

.data

len1 db ?
len2 db ?	

str1 db "$$$$$$$$$$$$$$$$$$$$$$"
str2 db "$$$$$$$$$$$$$$$$$$$$$$"

final db "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"

msg1 db "Enter String : $"
msg3 db "Final String : $"
msg4 db "Enter Length : $"
msg5 db " $"

; PRINT MACRO
print macro msg
mov ah,09h
mov dx,offset msg
int 21h
endm

; LISTEN MACRO [Take Length of String & String Input]
listen macro str
print msg4
mov ah,01h
int 21h
sub al,'0'
mov len2,al
mov cl,al
mov ch,00h
print msg5
print msg1
mov si,offset str
next:   mov ah,01h
        int 21h
        mov [si],al
        inc si
        loop next
endm

.code
mov ax,@data
mov ds,ax

mov es,ax
listen str1

mov al,len2
mov len1,al

print msg5

listen str2

print msg5

cld
mov si,offset str1
mov di,offset final
mov ch,00h
mov cl,len1
rep movsb

dec di
mov si,offset str2
mov cl,len2
rep movsb

print msg3
print msg5
print final

mov ax,4c00h
int 21h
end
