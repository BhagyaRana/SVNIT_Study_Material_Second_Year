
; Q-(2) Write a program for two’s complement of 8-bit number.

MVI A,00
; Load the Data at Location 3000 to Accumulator
LDA 3000h                         ; [A] <- [3000]
; CMA -> Complement the Contents of Accumulator
CMA                                    ; [A] <- Complement([A])
; Add 01 to One's Complement to Obtain Two's Complement
ADI 01		       ;  [A] <- [A] + 01
; Store the Result at Location 3004
STA 3004h 		       ; [3004] <- Two's_Complement([A])

hlt

