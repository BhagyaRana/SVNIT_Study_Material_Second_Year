
;A set of ten bytes is stored in memory starting with the address 2050H.
; WAP to check each byte ,  and 
; save the bytes that are higher than 60and lower than 100 in memory locations starting from 2060H.

; [U19CS012] [BHAGYA VINOD RANA]  

LXI H, 2050H
LXI D, 2060H
MVI B, 3BH
MVI C, 0AH
MVI A, 00H

LOOP:  MOV A, B
	   CMP M
           JC ok1
	   INX H
	   DCR C
	   JNZ LOOP
	   JMP exit

exit: HLT

; 3CH (60) <= M [Checks]
ok1: MOV A, M
        CPI 65H
        JC ok2
        INX H
	DCR C
        JNZ LOOP
	JMP exit

; M <= 65H (100) [Checks]
ok2: MOV A, M
	STAX D
	INX D
	INX H
	DCR C
	JNZ LOOP
	JMP exit
