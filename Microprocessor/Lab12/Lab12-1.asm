	ORG    00H
	JMP    MAIN
	ORG    50H
MAIN:
	MOV	TMOD,#00100000B                  ;TIMER1:12MHz MODE 2 
	MOV	TL1,#0E6H                        ;BAUD RATE 1200
	MOV	TH1,#0E6H							 
	MOV	SCON,#01010000B		 	 ;SERIAL MODE1
	ANL	PCON,#01111111B			 ;SMOD=0
	SETB	TR1                              ;TIMER1 START
	CLR	RI
WAITa:						 ;┕パSERIAL钡Μ计
	JNB	RI,WAITa
	MOV	A,SBUF
	CLR	RI				 ;ASCII-48 = 计计
	SUBB	A,#48
	ORL	A,#70H				 ;+70H眔LED计
	MOV	R3,A	
WAITb:
	JNB	RI,WAITb
	MOV	A,SBUF
	CLR	RI
	SUBB	A,#48				 ;ASCII-48 = 计计
	ORL	A,#0B0H				 ;+B0H眔LED计
	MOV	R2,A	
WAITc:
	JNB	RI,WAITc
	MOV	A,SBUF
	CLR	RI
	SUBB	A,#48				 ;ASCII-48 = 计计
	ORL	A,#0D0H				 ;+D0H眔LED计
	MOV	R1,A	
WAITd:
	JNB	RI,WAITd
	MOV	A,SBUF
	CLR	RI
	SUBB	A,#48				 ;ASCII-48 = 计计
	ORL	A,#0E0H			         ;+E0H眔LED计
	MOV	R0,A	
SHOW:						 ;礚癹伴ㄏㄤ陪ボ
	MOV	P0,R3
	CALL	DELAY
	MOV	P0,R2
	CALL	DELAY
	MOV	P0,R1
	CALL	DELAY
	MOV	P0,R0
	CALL	DELAY
	JMP	SHOW
	
	
DELAY:
	MOV R4, #12
DELAY1:
	MOV R5, #0FFH
DELAY2:
	DJNZ R5, DELAY2
	DJNZ R4, DELAY1
	RET
END