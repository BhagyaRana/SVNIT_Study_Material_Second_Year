
;A string of readings is stored in memory, locations starting at 2070H, 
; and the end of the string is indicated by the byte 0DH.
; WAP to check each byte in the string,
; and the save the bytes in the range of 30H to 39H (both inclusive) in memory locations starting from 2090H.

; [U19CS012] [BHAGYA VINOD RANA] 

LXI H, 2070H
LXI D, 2090H
; Intialise it with 30H-1 = 2FH
MVI B, 2FH

LOOP: MVI A, 0DH
	   CMP M
	   JZ exit
	   MOV A, B
	   CMP M
	   JC ok1
	   INX H
           JMP LOOP

exit: HLT

; 30H <= M [Checks]
ok1: MOV A, M
        CPI 3AH
        JC ok2
        INX H
        JMP LOOP

; M <= 39H [Check]
ok2: MOV A, M
	STAX D
	INX D
	INX H
	JMP LOOP
