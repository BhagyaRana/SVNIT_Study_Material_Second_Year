; (3) Write a Program to sort 16 bits given numbers in ascending /descending order.

.model small
.stack 100
.8086

.data

n db 0AH
;storing in b for refernce 
b dw 1410h,3443h,0db54h,4337h,5675h,0086h,4209h,0cd2h,12ffh,4500h

a dw 1410h,3443h,0db54h,4337h,5675h,0086h,4209h,0cd2h,12ffh,4500h
i db ?
tmp db ?

.code
mov ax,@data
mov ds,ax

; Initialize
mov ch,00h
mov cl,n
dec cl
mov si,offset a
mov i,00h

up1:    mov tmp,cl  ; 

        mov cl,n
        sub cl,i
        inc i
        dec cl      ; cl = n-i-1
        mov bx, 0000h

up2:    mov ax, [si+bx]
        mov dx, [si+bx+2]
        cmp ax, dx  ; if (ax>=dx) goto next
        jnc next    
        mov [si+bx], dx     ; Swap
        mov [si+bx+2], ax

next:   inc bx
        inc bx
        loop up2
        mov cl, tmp
        loop up1

mov ax, 4C00H
int 21h
end
