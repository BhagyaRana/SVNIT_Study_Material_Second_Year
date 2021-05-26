; Q-(4) Write a Program to interchange two blocks of data

.model small
.stack 100
.8086

.data
; Number of Bytes in Each Block
bytecnt equ 05
; Source Block Data
src db 11H, 22H, 33H, 44H, 55H
; Destination Block Data
dst db 66H, 77H, 88H, 99H, 0AAH

.code
mov ax, @data
mov ds, ax

; Intialize SI, DI and Counter
lea si, src
lea di, dst
mov cl, bytecnt

up: mov al,[si]     ; To Swap Store Value in Temp Variable
    mov bl,[di]
    mov [si],bl     ; Store the Old Destination Value in [SI]
    mov [di],al     ; Store the Old Source Value in [DI]
    inc si
    inc di
    dec cl 
    jnz up

mov ax,4C00H
int 21h
end
