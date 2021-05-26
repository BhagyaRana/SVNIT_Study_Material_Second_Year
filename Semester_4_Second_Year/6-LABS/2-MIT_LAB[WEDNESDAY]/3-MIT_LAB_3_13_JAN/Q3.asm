
;(3) WAP to load the bit pattern 91H in register B and 87H in register C.
; Mask all the bits except D0 from registers B and C.

; Load 91H in Register B
MVI B, 91H
; Load 87H in Register C
MVI C, 87H

MOV A, B
ANI 01H	 ; Mask all Bits of Except D0 Bit ie (0000 0001) = (01)H
STA 3000H

MOV A, C
ANI 01H  ; Mask all Bits of Except D0 Bit ie (0000 0001) = (01)H
STA 3001H

HLT

