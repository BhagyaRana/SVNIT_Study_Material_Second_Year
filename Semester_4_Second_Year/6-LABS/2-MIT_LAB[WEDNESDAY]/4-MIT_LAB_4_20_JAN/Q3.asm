
;(3) Write a Program to shift a 16-bit data 1 bit left. 
; Assume data is in the HL register pair 

; INPUT : 16 BIT DATA at Location 3001H & 3000H

LHLD 3000H

; Observation : To Shift 16-bit data by 1 Bit : We add [HL] to itself
; Since Left Shift Means Multiplying by 2
; [H-L] <- [H-L] + [H-L] 
; DAD -> Add Register Pair to [H-L]
DAD H

; OUTPUT : 16 BIT DATA at Location 3006H & 3005H
SHLD 3005H

HLT

