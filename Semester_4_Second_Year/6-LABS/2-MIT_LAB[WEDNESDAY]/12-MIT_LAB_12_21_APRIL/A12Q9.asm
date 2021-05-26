; (9) Write a Program to search a character in a given string.

.model small
.stack 100
.8086

.data

len1 db ?
char db ?
ans dw ?	
str1 db "$$$$$$$$$$$$$$$$$$$$$$$$$$"
msg1 db "Enter String : $"
msg4 db "Enter length : $"
msg2 db "Enter the character to find :$"
msg5 db " $"
msg3 db "Character found at :$"

; PRINT MACRO
print macro msg
mov ah,09h
mov dx,offset msg
int 21h
endm

; READ MACRO
read macro str
print msg4
mov ah,01h
int 21h
sub al,'0'
mov len1,al
mov cl,al
mov ch,00h
print msg5
print msg1
mov si,offset str
nextc: mov ah,01h
int 21h
mov [si],al
inc si
loop nextc
endm

.code
mov ax,@data
mov ds,ax

mov es,ax
print msg2
mov ah,01h
int 21h
mov char,al

read str1
print msg5

mov di,offset str1

mov cl,len1
mov ch,00h

mov al,char

repnz scasb

mov ans,di
sub ans,offset str1

mov ax,4c00h
int 21h
end
