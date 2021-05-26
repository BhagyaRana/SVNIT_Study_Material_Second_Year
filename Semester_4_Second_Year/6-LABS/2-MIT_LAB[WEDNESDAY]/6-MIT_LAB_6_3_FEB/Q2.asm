; (2) Find the square of the given numbers from memory location 6100H
; and store the result from memory location 7000H.

; INPUT
; Location 60FFH : 'n' : Number of Elements
; Followed by 'n' Numbers from : (6100)H to (6100+n)H 
; LIMITATION: Only Numbers between [0-15] Accepted

; OUTPUT
; Square of Numbers are Stored from Location : (7000)H to (7000+n)H

LDA 60FFH ; Input 'n'
; Store 'n' in Register C
MOV C, A

; Load the First Number
LXI  H, 6100H 
; Load the Place where Square of Numbers need to be stored
LXI  D, 7000H 

LOOP: MVI A, 00H ; Intialise Accumulator
	  MOV B, M ; Copy the Number to Register 'B'

; Squaring : Adding the Number 'n' , n times
SQUARE: ADD M 
  		DCR B
		; Until B Reaches 0
		JNZ SQUARE

; Store the Result in DE Register Pair
STAX D
INX H   ; Next Number in Array
INX D   ; Next Destination Location

DCR C
JNZ LOOP ; Until All Elements of Array are Traversed

HLT
