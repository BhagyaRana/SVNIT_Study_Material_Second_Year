;Q-(6) Write a Program to Multiply Two 8-bit Numbers.
; Adding Number 1 , "Number 2 Times "  = Num1 * Num2 

; Taking 3000h Location in HL Pointer 
LHLD 3000h	 ; H <- 3001, L <- 3000

XCHG		 ; H <- D, L <- E
; Intializing the Counter
MOV C, D        ; C <- D
MVI D, 00        ; D <- 00

LXI H, 0000    ; H <- 00, L <- 00

loop: DAD D    ; HL <- HL+DE
	DCR C     ; C <- C-1

JNZ loop      ; If Zero Flag=0, goto loop

SHLD 3004h    ;  H <- 3005, L <- 3004
HLT	


