ORG 0000H
JMP MAIN
ORG 0050H
;----------------
MAIN:
	MOV DPTR,#NTABLE
LOOP1:
	MOV R2,#0			
LOOP2:
	MOV A,R2						
	MOVC A,@A+DPTR	
	MOV P1,A			
	INC R2						
	ACALL DELAY
	CJNE R2,#7,LOOP2		
	JMP LOOP1

NTABLE:
	DB 00000011B
	DB 01000001B
	DB 10011111B	
	DB 00000011B
	DB 00000001B
	DB 00001101B
	DB 00011011B
;-----------------------------
DELAY:
	MOV R5,P3
	INC R5
DELAY1:
	MOV R6,#0FFH
DELAY2:
	MOV R7,#099H
DELAY3:
	DJNZ R7,DELAY3
	DJNZ R6,DELAY2
	DJNZ R5,DELAY1
	RET
	END