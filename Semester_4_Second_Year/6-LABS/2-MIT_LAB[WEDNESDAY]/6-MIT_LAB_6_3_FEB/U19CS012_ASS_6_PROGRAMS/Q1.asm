; The following block of data is stored in memory locations from 3055H to 305AH.
; WAP to transfer the block of data in reverse order at same memory location.
; DATA (HEX): 22, A5, B2, 99, 7F, 37

; Point HL to First Location
LXI B, 3055H
; Intialise the Counter to 6 [Since 6 Numbers]
MVI H, 06H

; COPY IT TO TEMOPARY LOCATION SERIALLY

; Point DE to Location 2000H
LXI D, 2000H
LOOP: LDAX B ; A <- (BC)
      STAX D ; (DE) <- A
      INX B ; i++
      INX D ; j++
      DCR H ;Decrease the Counter
      JNZ LOOP 

; COPY FROM TEMOPARY LOCATION back to Same Location [3055-305A] 
; IN REVERSE ORDER

DCX D ; DE Pair is pointing to Last Location
LXI B, 3055H
MVI H, 06H

LOOP2: LDAX D ; A <- (DE)
       STAX B ; (BC) <- A
       DCX D  ; j--   
       INX B  ; i++
       DCR H  ; Decrement Counter
       JNZ LOOP2
HLT
