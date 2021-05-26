; Q - (1) : Write a Program for data transfer using different addressing modes.

.model small
.stack 100
.8086

.code
mov AX,@data
mov DS,AX

; 1) IMMEDIATE ADDRESSING MODE
mov CL, 12H     ; Moves 12 immediately into CL register
mov BX, 1234H   ; Moves 1234 immediately into BX register
mov SI, 75H
mov BX, 04H

; 2) REGISTER ADDRESSING MODE
mov CL, DL      ; Moves data of DL register into CL register
mov AX, BX      ; Moves data of BX register into AX register

; 3) DIRECT ADDRESSING MODE
mov CL, [34H]   ; Moves data from location 34H in the data segment into CL 
                ; Phy Addr = DS * 10H + 4

; 4) INDIRECT ADDRESSING MODES

; 4.1) REGISTER INDIRECT ADDRESSING MODE
MOV CL, [BX]    ; Moves a byte from the address pointed by BX in Data
                ; Segment into CL.
                ; Physical Address calculated as DS * 10H + BX

; 4.2) REGISTER RELATIVE ADDRESSING MODE
MOV CL, [BX+4]  ; Moves a byte from the address pointed by BX+4 in
                ; Data Seg to CL.
                ; Physical Address: DS * 10H + BX + 4H

; 4.3) BASE INDEXED ADDRESSING MODE
MOV CL, [BX+SI] ; Moves a byte from the address pointed by BX+SI in Data Segment to CL.
                ; Physical Address: DS * 10H + BX + SI

; 4.4) BASE RELATIVE PLUS INDEX ADDRESSING MODE
MOV CL, [BX+DI+20]  ; Moves a byte from the address pointed by BX+SI+20H in Data Segment to CL.
                    ; Physical Address: DS * 10H + BX + SI+ 20H

; 5) IMPLIED ADDRESSING MODE

STC ; Sets the Carry Flag
CLD ; Clears the Direction Flag

; HLT
mov AX,4c00h
int 21H
end