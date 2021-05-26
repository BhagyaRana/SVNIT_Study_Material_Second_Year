; Q-(1) Write ALP to ADD/SUB ‘n’ 16 bit numbers stored in consecutive memory location.

.model small
.stack 100
.8086

.data
; Number of Elements 'n'
n dw 0005H
; Data of 5 Elements
a dw 1211H, 0A145H, 4817H, 3C12H, 12F7h
; Answer & Carry 
ans dw ?
carry db ?

.code
mov ax,@data
mov ds,ax

; Intialize the Counter = n
mov cx, n
; Intialize the SI
mov si,offset a
; Intial Sum = 0
mov ax,0000h
; Intial Carry = 0
mov dl,00


up:		add ax, [si]
		jnc next	; IF Carry Generated
		inc dl		 
next:	inc si
		inc si
		loop up

mov ans,ax
mov carry,dl

mov ax, 4C00H
int 21h
end
