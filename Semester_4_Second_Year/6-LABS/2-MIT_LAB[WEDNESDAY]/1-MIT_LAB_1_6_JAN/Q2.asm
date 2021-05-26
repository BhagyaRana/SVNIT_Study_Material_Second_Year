
; Q-(2)Write a program to add two 8-bit numbers. Store the result at one memory location.

; Direct Method

; Intiatilize the Register B with 8-bit [Number 1]
MVI B, 01h
; Intiatilize the Register D with 8-bit [Number 2]
MVI D, 01h
; Add B to Accumulator
ADD B
; Add D to Accumulator
ADD D
; Store Result from Accumulator at Location 3004h
STA 3004h


hlt