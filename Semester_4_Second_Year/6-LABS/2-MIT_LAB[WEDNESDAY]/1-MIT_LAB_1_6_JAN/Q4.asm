; Q-(4) Exchange the contents of memory locations 2000H and 4000H 

; Intialize Accumulator to 00
MVI A,00
; Store the Contents at Location 2000H in B register [Temporary Var]
LDA 2000h
MOV B, A
; Store the Contents at Location 4000H at Location 2000H
LDA 4000h
STA 2000h
; Store the Contents from B Register [Temp] to Location 4000H
MVI A, 00
ADD B
STA 4000h

hlt