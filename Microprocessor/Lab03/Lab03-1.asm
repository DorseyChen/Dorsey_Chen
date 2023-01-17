ORG 0000H
JMP START
ORG 0050H
;-------------------------
START:
	MOV R0,#01110000B
	MOV R1,#10110000B
	MOV R2,#11010110B
	MOV R3,#11101001B
	MOV R5,#00H 		;counter 0
MAIN1:
	CJNE R5,#10,MAIN2	;R5!=10 跳main2
	MOV R5,#00H 		;控制整體速度
	INC R0
MAIN2:
	CJNE R0,#7AH,SHOW1 ;R0!=10 跳show1
	INC R1
	MOV R0,#70H
SHOW1:
	MOV P1,R0
	CALL DELAY
	CJNE R1,#0BAH,SHOW2;R1!=10 跳show2
	INC R2
	MOV R1,#0B0H
SHOW2:
	MOV P1,R1
	CALL DELAY
	CJNE R2,#0DAH,SHOW3;R2!=10 跳show3
	INC R3
	MOV R2,#0D0H
SHOW3:
	MOV P1,R2
	CALL DELAY	
	CJNE R3,#0EAH,SHOW4;R3!=10 跳show4
	MOV R3,#0E0H
SHOW4:
	MOV P1,R3
	CALL DELAY
	INC R5
	JMP MAIN1
;-----------------------;dealy 0.01s
DELAY:
	MOV R6,#20
DELAY1:
	MOV R7,#255
DELAY2:
	DJNZ R7,DELAY2
	DJNZ R6,DELAY1
	RET	
END