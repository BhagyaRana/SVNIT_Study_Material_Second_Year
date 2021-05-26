; 2. Write a Program to Implement strcpy Function

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

str1 db "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
msg1 db "Enter String : $"
msg4 db "Enter length : $"
msg2 db "Enter n : $"
msg5 db " $"

len1 db ?
; 'n' in the Question
len db 05h	; 1Fh = 31 characters (Length of String to be copied)
; Source
; str1 db "MICROPROCESSOR AND INTERFACING$"
; Destination
str2 db "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"

.code
mov ax,@data
mov ds,ax

mov es,ax
mov ch,00h

; Take String Input
read str1
print msg5

print msg2
mov ah,01h
int 21h
sub al,'0'
mov len,al
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
