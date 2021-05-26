
; Q-(1) - Store the data byte 25H into memory location 3000H

; Add 25h [37 in Decimal] to Accumulator [Initially Empty]
ADI 25h

; Store the Result of Accumuator at Location 3000h
STA 3000h

; Result : We will Find 37 [25h] At Location 3000h

;Interrupt
hlt

