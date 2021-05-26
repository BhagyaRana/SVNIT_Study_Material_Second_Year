; Q-(10) Write a Program to find occurrences of a given character in a given string through keyboard.

.model small
.stack 100
.8086

.data

;PRINT MACRO
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


len1 db ?
char db ?

ans db 00h	

str1 db "$$$$$$$$$$$$$$$$$$$$$$$$$$"
msg1 db "Enter String : $"
msg4 db "Enter length : $"
msg2 db "Enter the character to find :$"
msg5 db " $"

.code
mov ax,@data
mov ds,ax

mov es,ax
print msg2  ; Enter Character

; Take Character input and Store in AL
mov ah, 01h
int 21h
mov char, al

; Take String Input
read str1
print msg5

; DI -> Pointing to Str1 [Intialize DI]
mov di,offset str1
; Intialize Counter
mov cl,len1 
mov ch,00h

mov al,char

up: mov ah,[di]
    cmp ah,al   ; Compare if the Character is Same?
    jnz skip    
    inc ans     ; Increment the Frequency of character 
    skip: inc di
    loop up

; HLT
mov ax,4c00h
int 21h
end
