	ORG 0000H
	JMP START
	ORG 0050H
START:
	MOV B,#00H 				//��l��B�@��������઺�p�ƾ�
	MOV	R4,#00010001B		//��l��R4���@������������ܼ�
LOOP:
	MOV A,B					
	CJNE A,#00H,REG			//�d��B�O���O0
ROW1:
	MOV P0,#01111111B		//�d��ROW����
	CALL DELAY
	MOV A,P0
	ANL A,#00001111B
	MOV R1,#1				//�NR1�]��1���@�઺���ת��Ѧ�
	CJNE A,#00001111B,COL1
ROW2:
	MOV P0,#10111111B
	CALL DELAY
	MOV A,P0
	ANL A,#00001111B
	MOV R1,#5			    //�NR1�]��5���@�઺���ת��Ѧ�
	CJNE A,#00001111B,COL1
ROW3:
	MOV	P0,#11011111B 
	CALL DELAY
	MOV	A,P0
	ANL	A,#00001111B
	MOV R1,#0				//�NR1�]��0���@������઺�T��
	CJNE A,#00001111B,COL1 
	JMP LOOP				//�S���Ʀr�Q���U	
COL1:
	CJNE A,#00001110B,COL2	//�d��COL����
	MOV R0,#0
	CJNE R1,#00H,COL1_1		//�d�ݭn���n�������
	MOV B,#01H				//counter�}�l�O��
	JMP	REG					//���������઺���
COL1_1:						//���Ϋ������
	MOV B,#00H				//�Ncounter�k�s
	JMP MAIN1				//�������
COL2:
	CJNE A,#00001101B,COL3	//�P�W	
	MOV R0,#1
	CJNE R1,#00H,COL2_1
	MOV B,#01H
	JMP	REG
COL2_1:
	MOV B,#00H
	JMP MAIN1
COL3:						 
	CJNE A,#00001011B,COL4
	MOV R0,#2
	MOV B,#00H				 //���i�঳������ƦC�A��������
	JMP MAIN1
COL4:
	CJNE A,#00000111B,LOOP 	 //�S���Ʀr�Q���U	
	MOV R0,#3
	MOV B,#00H				 //���i�঳������ƦC�A��������
	JMP MAIN1	

REG:
	MOV	A,R4				 //���J�����V�ܼ�
	CJNE R0,#00H,LEFT		 //�d�ݱ����V	
RIGHT:	
	RL A
	JMP NEXT
LEFT:
	RR A
NEXT:
	MOV p1,A				  //���
  	CALL DELAY
	MOV R4,A				  //��sR4�ѤU���ϥ�
	MOV	A,B					  //��scounter
	INC A
	MOV B,A
	CJNE A,#150,LOOP		  //�Y����150�����఻���@������
	MOV B,#01H				  //���mcounter
	JMP ROW1

MAIN1:
	CALL DELAY1S			  //�I�sDelay�O�@����
	MOV R3,#0				  //�NR3�]��0�@���p��
	MOV A,R0				  //��zR0+R1
	ADD A,R1
	MOV R2,A
	SUBB A,#5				  //�d�ݤ�V	
	JNC MAIN2				  
	MOV A,#00010001B		  //��l�Ʊ���Ѽ�
	JMP FUN1
MAIN2:
	MOV A,R2
	CLR C
	SUBB A,#4
	MOV R2,A
	MOV A,#00010001B
	JMP FUN2
FUN1:
	MOV P1,A				   //����
	CALL DELAY				   //�����������W	
	INC R3					   //R3�p��++
	RR A					   //��s����Ѽ�
	CJNE R3,#130,FUN1		   //130��
	MOV R3,#0				   //��sR3���U�@�h�j��
	DJNZ R2	,FUN1			   //�̷ӱo�쪺�Ƥj�p�ӨM�w����
	JMP LOOP				   //�^��j��
FUN2:
	MOV P1,A
	CALL DELAY
	INC R3
	RL A
	CJNE R3,#130,FUN2
	MOV R3,#0
	DJNZ R2,FUN2
	JMP LOOP
	
;-----�O�@Delay-----
DELAY1S:
	MOV R5,#255
DELAY1S1:
	MOV R6,#255
DELAY1S2:
	MOV R7,#10
DELAY1S3:
	DJNZ R7,DELAY1S3
	DJNZ R6,DELAY1S2
	DJNZ R5,DELAY1S1
	RET
;-----���qDelay-----
DELAY:
	MOV R5,#200
DELAY1:
	MOV R6,#250
DELAY2:
	DJNZ R6,DELAY2
	DJNZ R5,DELAY1
	RET
END