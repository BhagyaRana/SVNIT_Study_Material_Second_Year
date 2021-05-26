
;(2) WAP to load the data byte 8EH in register D and F7H in register E.
; Mask the high-order bits (D7-D4) from both the data bytes, 
; Exclusive-OR the low-order bits (D3-D0) and display the answer

; Load 8EH in Register D 
MVI D, 8EH
; Load F7H in Register E
MVI E, 0F7H
; Copy D to Accumulator
MOV A,D
; Mask High-Order (D7-D4) of D
ANI 0FH
; Copy it to Register D
MOV D,A
; Copy E to Accumulator
MOV A,E
; Mask High-Order (D7-D4) of E
ANI 0FH
; XOR between Masked high-order bits of D and E
XRA D
; Display at Output Port at Location 01h 
OUT 01H
HLT

