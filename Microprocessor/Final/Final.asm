	ORG		0000H
	JMP		START
	ORG		000BH 	  		;T/C0
	JMP		SET1
	ORG		0013H     		;INT1
	JMP		GETRESULT	
	ORG		0050H
START:
	SETB 	IT1
	MOV		IP,#00000100B 	;INT1 priority 1
	MOV		IE,#10000110B	;interrupt enable ,TF0,INT1,ALL
	CLR 	P1.0
 	CLR		TF0				;clear timer 0 over flow flag
	CLR		TF1				;clear timer 1 over flow flag
	MOV		TMOD,#11100010B  ;GATE p3.3 gate control C1 MODE2/NOGATE T0 MODE2
	MOV		TH0,#227		;timer0 ���ͤ�i��counter1 clock��J(p3.5)��
	MOV		TL0,#227		
	SETB	TR0				;TR0=1 �i�H�ѥ~������ 
	MOV		TH1,#0			;counter1 ���`�@count�X��		
	MOV		TL1,#0			 
	SETB	TR1				;TR1=1 �i�H�ѥ~������
	MOV 	R0,#0			;�NR0�]���@�ӫ׼ưѦ�	
	MOV		R1,#255
	MOV		R2,#00010001B
	MOV		R3,#00010001B
MAIN:
	SETB   P1.1
	CALL   MOVE
	CLR	    P1.1
	CALL   MOVE
	CALL   CHECK
	JMP MAIN
MOVE:
	MOV		A,R2
	MOV		P0,A		
	RR		A
	MOV		R2,A
	MOV		A,R3
	MOV		P2,A			
	RR		A
	MOV		R3,A
	CALL	DELAY
	INC		R0
	CJNE	R0,#100,MOVE
	MOV		R0,#0
	RET
CHECK:
	MOV		A,R1
	SUBB	A,#5
	JC		MOVEBACK
	CLR		C
	RET
MOVEBACK:
	MOV		A,R2
	MOV		P0,A		
	RL		A
	MOV		R2,A
	MOV		A,R3
	MOV		P2,A			
	RL		A
	MOV		R3,A		
	CALL	DELAY
	INC		R0
	CJNE	R0,#255,MOVEBACK
	MOV		R0,#0
	CLR		C
TURN:
	MOV		A,R3
	MOV		P2,A		
	RR		A
	MOV		R3,A
	CALL	DELAY
	INC		R0
	CJNE	R0,#255,TURN
	MOV		R0,#0
	RET
SET1:
	CPL     P1.0		   	;TF0=1
	CLR     TF0
	RETI
GETRESULT:				   	;��trigger ����echo����P3.3��echo high�ɱҥ�counter1
	MOV	    A,TL1          	;�}�l�����Ӧ�timer0��clock,echo low��Ĳ�ointerrupt
	MOV 	R1,A
INITIALTC:
	CLR	    TF1	                        
	MOV	    TH1,#0	
	MOV	    TL1,#0
	RETI
DELAY:
	MOV	R6,#200
DELAY1:
	MOV	R7,#100
DELAY2:
	DJNZ	R7,DELAY2
	DJNZ	R6,DELAY1
	RET
END