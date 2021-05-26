
;Q4

; To Intialise
MVI A, 10H
SUB A
; Z Flag Set
; Program Starts Here
MVI A, 5EH
ADI 0A2H
MOV C, A
HLT