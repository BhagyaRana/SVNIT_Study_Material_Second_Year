
;Q7

	MVIC, 03H
	LXI H, 2000H
	MOV A, M
	DRC C
LOOP:   INX H
	MOV B, M
	CMP B
	JNC LOOP2
	MOV A, B
LOOP2:  DCR C
	JNZ LOOP
	STA 2100H
	HLT