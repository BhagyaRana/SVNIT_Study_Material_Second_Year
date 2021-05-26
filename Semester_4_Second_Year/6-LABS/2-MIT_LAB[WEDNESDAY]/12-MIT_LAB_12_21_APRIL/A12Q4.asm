; (4) Write a Program to find occurrences of a given number in a list of N numbers given through keyboard.

.model small
.stack 100
.8086

.data
n db ?
ans db 00h

x db ?
y db "$"

cr equ odh
lf equ 0ah

msg1 db "n=$"
msg2 db "Enter Numbers :$"
msg3 db "Enter the number to check its occurences :$"
msg4 db "  $"

p db ?

; PRINT MACRO 
print macro msg
mov ah,09h
mov dx,offset msg
int 21h
endm

; READ MACRO
read macro no
mov ah,01h
int 21h
sub al,'0'
mov bl,0ah
mul bl
mov no,al
mov ah,01h
int 21h
sub al,'0'
add no,al
endm	

.code
mov ax,@data
mov ds,ax

print msg1
read n

print msg4
print msg3
read x

print msg4
print msg2

mov ch,00h
mov cl,n

up: read p
	mov al,x
	cmp al,p
	jnz next	; Both Equal?
	inc ans
	next: inc p	; Increment the Count
	print msg4
	loop up

mov ax,4c00h
int 21h
end
