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
	JNB	RI,WAIT1		       ;���ݱ���
	MOV	A,SBUF	
	ADD	A,#32			       ;ASCII�j�g�r��+32=ASCII�p�g�r��
	CLR	RI			       ;�M������FLAG
	CLR	TI
	MOV	SBUF,A			       ;��X
WAIT2:
	JNB	TI,WAIT2		       ;���ݶǿ駹��
	CLR	TI			       ;�M���ǰeFLAG
	CLR	RI
	JMP	WAIT1

END
