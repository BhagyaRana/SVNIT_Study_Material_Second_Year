; Q-)11) Program to check whether given substring exist in a main string or not?

.model small
.stack 100
.8086

.data
len1 db 0Eh
; Change it to 06H <- Mango
len2 db 07h

ans db 00h	

str1 db "assassination$"
subsr db "nation$"

; subsr db "mango$" ; NOT FOUND CASE

msg5 db " $"

msg1 db "substring found $"
msg2 db "substring not found$"

temp dw ?

; PRINT MACRO
print macro msg
mov ah,09h
mov dx,offset msg
int 21h
endm


.code
mov ax,@data
mov ds,ax

mov es,ax

mov di,offset str1
mov si,offset subsr

mov ch,00h
mov cl,len1

up: mov si,offset subsr
    mov al,[si]
    repnz scasb
    cmp cx,00h
    jz terminate 
    mov temp,di
    push cx
    mov cl,len2
    dec cl
    inc si
    check:  mov al,[si]
            cmp al,[di]
            jnz skip
            inc si
            inc di
    loop check
    print msg1
    jmp terminate
    skip: pop cx
    mov di,temp
    loop up

; HLT
terminate: mov ax,4c00h
int 21h
end


