;Assigment 12 Q7 

.model small
.stack 100
.8086

.data
len dw 0024h	
str1 db "ab CD ef GH ij KLMN opqr STUV wxyz $"

.code
mov ax,@data
mov ds,ax

mov es,ax
mov cx,len
mov si,offset str1

cld
up: mov al,[si]
    cmp al, 20   ; ASCII OF ' ' = 32 = 20h
    jz next
    cmp al, 41h  ; ASCII OF 'A' = 65 = 41h
    jc next
    ; cmp al, 7Ah  ; ASCII of 'z' = 122 = 7AH
    ; jnc next
    cmp al,5Ah  ; ASCII of 'd' = 100
    jnc smalla
    add al,20h  ; Add 32 to Get Lower Case
    mov [si],al 
    jmp next

    smalla: sub al, 20h     ; Subtract 32 to Get Upper Case
            mov [si], al

    next: inc si
    loop up

; Print the Answer
mov ah,09h
mov dx,offset str1
int 21h

mov ax,4c00h
int 21h
end
