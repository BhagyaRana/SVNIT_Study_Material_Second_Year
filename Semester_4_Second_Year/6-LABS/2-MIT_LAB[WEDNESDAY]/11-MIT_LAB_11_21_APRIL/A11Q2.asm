; Q - (2) Write Program to move data from source to destination using indirect addressing mode (Block Move without overlap)

.model small
.stack 100
.8086

.data
; Number of Elements in Array
n dw 6 
; The Contents of Array
arr dw 11H, 22H, 33H, 44H, 55H, 66H
; The ans Array
ans dw ?

.code
mov ax,@data
mov ds,ax

; Initialize the Counter
mov cx, n
; Initialize the Stack Pointer
mov si, 0000H
; Intialize the Destination Pointer
mov di, 0000H

transfer:   mov ax, arr[si]
	      inc si
	      inc si
	      mov ans[di], ax
	      inc di
	      inc di
	      loop transfer ; DCR cx & if cx!=0 goto trnafer

; HLT     
mov ax,4C00H
int 21h
end



