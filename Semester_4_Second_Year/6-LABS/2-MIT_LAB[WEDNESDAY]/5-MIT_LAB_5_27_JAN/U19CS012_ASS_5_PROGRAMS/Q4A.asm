
; (4A)-WAP to arrange data in Ascending order. 
; Assume suitable memory location for data and result.

; Input : First Location 2000H = Contains the Number of Elements ('n') in Array
; Followed by 'n' Numbers From Location [2001, 2002, ..., 200n]

; Output : Sorted in the Save Location [2001, 2002, ..., 200n]
; Saved Space! Bubble Sort is Inplace Sorting!

; ASCENDING Order [Bubble Sort] [Observe B & C Register Values]

; Input 'n' : Number of Elements in Array
LDA 2000H
; Initialise B = 'n'
MOV B,A
; B = n-1 = i
DCR B	

LOOP3: LXI H, 2000H
	    ; Initialise C = 'n'
	    MOV C, M
	    ; C = n-1
	    DCR C
	    ; Increment H to Point to First Array Element
	    INX H

LOOP2: MOV A,M  ; Store Val(A[j]) in ACC
	    INX H 	     ; Point it to Next Location H -> A[j+1]
	    CMP M	     ; Compare (A[j] & A[j+1])
	    ; If A<M then CY=1 [If A[j+1] > A[j] , No Need to Swap]
	    JC LOOP1  ;[LOOP1 = No Swap] [JC -> JNC (For Descending!)]
	    ; Otherwise Swap A[j] & A[j+1]
	    MOV D, M
	    MOV M, A
	    DCX H
	    MOV M, D
	    INX H
LOOP1: DCR C  	; j--
	    JNZ LOOP2  ; [If C!=0 goto LOOP2]
	    DCR B	        ; i--
	    JNZ LOOP3 ; 
HLT