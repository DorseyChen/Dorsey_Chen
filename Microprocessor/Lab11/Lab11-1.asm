	ORG		0000H
	JMP		START
	ORG		000BH 	  	;T/C0
	JMP		SET1
	ORG		0013H     	;INT1
	JMP		GETRESULT	
	ORG		0050H
START:
	SETB 	IT1
	MOV		IP,#00000100B 	;INT1 priority 1
	MOV		IE,#10000110B	;interrupt enable ,TF0,INT1,ALL
	CLR 	P1.0
 	CLR		TF0			;clear timer 0 over flow flag
	CLR		TF1			;clear timer 1 over flow flag
	MOV		TMOD,#11100010B  ;GATE p3.3 gate control C1 MODE2/NOGATE T0 MODE2
	MOV		TH0,#227	;timer0 ���ͤ�i��counter1 clock��J(p3.5)��
	MOV		TL0,#227		
	SETB	TR0			;TR0=1 �i�H�ѥ~������ 
	MOV		TH1,#0		;counter1 ���`�@count�X��		
	MOV		TL1,#0			 
	SETB	TR1			;TR1=1 �i�H�ѥ~������
SHOW:					;LOOP show
	MOV		A,R2		
	ADD		A,#0D0H		;��ܦʦ�
	MOV		P2,A		
	CALL	DELAY		
	MOV		A,R1		
	ADD		A,#0B0H	
	MOV		P2,A		;��ܤQ��
	CALL	DELAY
	MOV		A,R0		
	ADD		A,#70H	
	MOV		P2,A		;��ܭӦ�
	CALL	DELAY
	JMP		SHOW
SET1:
	CPL 	P1.0   		;TF0=1
	CLR 	TF0
	RETI
GETRESULT:				;��trigger ����echo����P3.3��echo high�ɱҥ�counter1
	MOV		A,TL1		;�}�l�����Ӧ�timer0��clock,echo low��Ĳ�ointerrupt
	MOV		B,#100		
	DIV		AB		
	MOV		R2,A		;�ʦ�R2
	MOV		A,B		
	MOV		B,#10		
	DIV		AB		
	MOV		R1,A		;�Q��R1
	MOV		R0,B		;�Ӧ�R0
INITIALTC:
	CLR		TF1		
	MOV		TH1,#0		
	MOV		TL1,#0
	RETI		       	
DELAY:			
	MOV		R6,#20	
DELAY1:
	MOV		R7,#30
DELAY2:
	DJNZ	R7,DELAY2
	DJNZ	R6,DELAY1
	RET
END