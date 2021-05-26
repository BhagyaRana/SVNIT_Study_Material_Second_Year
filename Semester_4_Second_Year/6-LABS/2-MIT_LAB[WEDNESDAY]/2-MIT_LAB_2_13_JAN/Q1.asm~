
; Q-(1) Write a program for one’s complement of 8-bit number

MVI A,00
; Load the Data at Location 3000 to Accumulator
LDA 3000h                         ; [A] <- [3000]
; CMA -> Complement the Contents of Accumulator
CMA                                    ; [A] <- Complement([A])
; Store the Result at Location 3002
STA 3002h                        ; [3002] <- [A]

hlt

