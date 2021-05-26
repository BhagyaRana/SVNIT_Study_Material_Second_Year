
;Q-(1) Display Lower Order Bits [D3-D0]

; Load A8H in Register C
MVI C, 0A8H 

; Copy it to Accumulator
MOV A, C

; AND with "0F" to Mask Higher Order Bits i.e. [D7-D4]
ANI 0FH

; Display the Lower Bits[D3-D0] at Output Port
OUT 01H

HLT

