
; Q-(3) Data bytes are stored in memory locations from 2050H to 205FH.
; To insert an additional five bytes of data, It is necessary to shift the data string by five memory locations. 
; WAP to store the data string from 2055H to 2064H.
; Use any sixteen bytes of data to verify your program.

; [U19CS012] [BHAGYA VINOD RANA] 

LXI H, 205FH       ;Last location of our intial bytes 
LXI D, 2064h        ;Last Location of our final bytes i.e.after shifting
MVI B, 016h          ; Total number of elements (22)

LOOP: MOV A, M             ; Move to Acc. A from memory
	  STAX D                ; Store it to new required location 
	  DCX H	              ; Previous Memory Location 
	  DCX D	              ; Previous Memory Location 
	  DCR B	              ; Decrease in elements
	  JNZ LOOP            ; Loop until all elements are iterated.

HLT

