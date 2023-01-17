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
	MOV		TH0,#227	;timer0 產生方波給counter1 clock輸入(p3.5)用
	MOV		TL0,#227		
	SETB	TR0			;TR0=1 可以由外部控制 
	MOV		TH1,#0		;counter1 數總共count幾次		
	MOV		TL1,#0			 
	SETB	TR1			;TR1=1 可以由外部控制
SHOW:					;LOOP show
	MOV		A,R2		
	ADD		A,#0D0H		;顯示百位
	MOV		P2,A		
	CALL	DELAY		
	MOV		A,R1		
	ADD		A,#0B0H	
	MOV		P2,A		;顯示十位
	CALL	DELAY
	MOV		A,R0		
	ADD		A,#70H	
	MOV		P2,A		;顯示個位
	CALL	DELAY
	JMP		SHOW
SET1:
	CPL 	P1.0   		;TF0=1
	CLR 	TF0
	RETI
GETRESULT:				;給trigger 產生echo接到P3.3當echo high時啟用counter1
	MOV		A,TL1		;開始接收來自timer0的clock,echo low時觸發interrupt
	MOV		B,#100		
	DIV		AB		
	MOV		R2,A		;百位R2
	MOV		A,B		
	MOV		B,#10		
	DIV		AB		
	MOV		R1,A		;十位R1
	MOV		R0,B		;個位R0
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