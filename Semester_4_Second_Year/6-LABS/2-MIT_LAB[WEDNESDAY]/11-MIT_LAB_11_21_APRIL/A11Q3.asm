; Q-(3) 3. Write a Program to move a block of data from source to destination (With overlap in either direction).

.model small
.stack 100
.8086

.data

x db 01h,02h,03h,04h,05h,06h,07h,08h,09h,0ah
y db 10 dup(?)

.code
mov ax,@data
mov ds,ax

mov ES,ax
mov si,offset x
mov di,offset y

mov cx, 0ah
add si, 0009h
add di, 0004h

again:
	mov al,[si]
	mov [di],al
	dec si
	dec di
	dec cl
	jnz again

mov ah,4ch
int 21h
end


