; Q-(2) Write a Program to find smallest/largest number in a given array of 16 bits numbers.

.model small
.stack 100
.8086

.data
; Number Of Elements in Array
n dw 000AH
; Elements of Array
a dw 1320h, 3123h, 0EB54h, 4347h, 5605h, 1086h, 4309h, 0DC2h, 12FFh, 4500h
; Answer
ans dw ?

.code
mov ax,@data
mov ds,ax

; Intialize the Counter, Offset and Sum [Intial = 0]
mov cx, n
mov si,offset a
mov ax,0000h

up:		cmp ax,[si]		; if (arr[i]>ans)
		jnc next		
		mov ax,[si]		; YES Update ans = arr[i]
next:	inc si			; NO Continue the Loop
		inc si
		loop up
mov ans,ax

mov ax,4c00h
int 21h
end
