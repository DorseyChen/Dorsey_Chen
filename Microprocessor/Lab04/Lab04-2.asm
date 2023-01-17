ORG 0000H
JMP START
ORG 0050H

START:
	MOV R0,#0
	MOV R1,#10H
	MOV DPTR,#TABLE	
LOOP:
	MOV P1,#00H
	MOV A,R0
	MOVC A,@A+DPTR
	MOV P0,A
	MOV P1,R1
	CALL DELAY			
	INC R0			
	CJNE R0,#7,LOOP		
	MOV R0,#0
	MOV A,R1
	RR A			
	MOV R1,A
	CJNE R1,#80H,LOOP	
	JMP START
TABLE:
	DB		40H
	DB		20H
	DB		10H
	DB		08H
	DB		04H
	DB		02H
	DB		01H
DELAY:
	MOV		R6,#100
DELAY1:
	MOV		R7,#100
DELAY2:
	MOV 	R5,#20
DELAY3:
	DJNZ 	R5,DELAY3
	DJNZ	R7,DELAY2
	DJNZ	R6,DELAY1
	RET
END