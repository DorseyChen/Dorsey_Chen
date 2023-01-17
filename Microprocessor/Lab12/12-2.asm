	ORG	00H
	JMP	    MAIN
	ORG	50H
MAIN:
	MOV	TMOD,#00100000B                ;TIMER1 MODE2 USE XTAL
	MOV	TL1,#0E6H                      ;BAUD RATE 1200
	MOV	TH1,#0E6H
	ANL	PCON,#01111111B		       ;SMODE = 0
	SETB	TR1                            ;Timer 1 start
	MOV	SCON,#01010000B		       ;SERIAL 1 REN ENABLE MODE1
	CLR	RI
WAIT1:						
	JNB	RI,WAIT1		       ;等待接收
	MOV	A,SBUF	
	ADD	A,#32			       ;ASCII大寫字母+32=ASCII小寫字母
	CLR	RI			       ;清除接收FLAG
	CLR	TI
	MOV	SBUF,A			       ;輸出
WAIT2:
	JNB	TI,WAIT2		       ;等待傳輸完成
	CLR	TI			       ;清除傳送FLAG
	CLR	RI
	JMP	WAIT1

END
