	ORG 0000H
	AJMP MAIN
	ORG 0BH
	AJMP TIMER
	ORG 0050H
MAIN:
	MOV 	P0,#0H;				
	MOV 	TMOD,#00000001B;	設定timer mode1
	MOV 	TH0,#11110001B;		給timer register第一個音
	MOV 	TL0,#00011000B;				
	SETB 	ET0;				啟用timer0 interrupt
	CLR 	TF0;				重置interrupt flag
	SETB 	EA;					啟用interrupt
	SETB 	TR0;				設定edge trigger	
START:
	MOV 	R3,#0H;				暫存用
	MOV 	R4,#13;				一共七個音
SOUND:	
	MOV 	DPTR,#TABLE  		
	MOV 	A,R3
	MOVC 	A,@A+DPTR
	MOV 	R0,A;				;放入high 8bit
	INC 	R3;

	MOV 	A,R3
	MOVC 	A,@A+DPTR
	MOV 	R1,A;				;放入low 8bit
	INC 	R3;

	MOV 	A,R3
	MOVC 	A,@A+DPTR			;放入震盪次數
	MOV 	R2,A;
	INC 	R3;
	
	ACALL 	LOOP;				進入空loop

	DJNZ 	R4,SOUND;

	CALL 	DELAY;
	CALL 	DELAY;
	CALL 	DELAY;
	CALL 	DELAY;

	JMP 	START;
LOOP:
	CJNE 	R2,#0H,LOOP;		interrupt R2 次
	RET;	
TIMER:
	CPL 	P0.0;				P0.0震盪
	MOV 	TH0,R0;				重新放入timer時間
	MOV 	TL0,R1;	
	DEC 	R2;					震盪一次 R2--
	RETI; 
TABLE:							;timer時間 high 8bit;timer時間 low 8bit;震盪次數
	DB	11110110B,00001001B,196	;SOL
	DB	11110100B,00101010B,165	;MI
	DB	11110100B,00101010B,82	;MI

	DB	11110100B,11010111B,175	;FA
	DB	11110010B,10110111B,147	;RE
	DB	11110010B,10110111B,73	;RE

	DB	11110001B,00011000B,131	;DO
	DB	11110010B,10110111B,147	;RE
	DB	11110100B,00101010B,165	;MI
	DB	11110100B,11010111B,175	;FA

	DB	11110110B,00001001B,196	;SOL
	DB	11110110B,00001001B,196	;SOL
	DB	11110110B,00001001B,98	;SOL
DELAY:
	MOV 	R6,#255
DELAY1:
	MOV		R7,#255
DELAY2:	
	DJNZ 	R7,DELAY2
	DJNZ 	R6,DELAY1
	RET
END
