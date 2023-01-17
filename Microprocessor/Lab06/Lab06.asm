	ORG		0000H
	JMP		LED_SHOW
	ORG		0050H
LED_SHOW:
	JB P3.2,LED_SHOW 	//�d�ݶɱ׶}�����L�n��
	MOV R0,#72			//�N72����R0�A�q�}�C���̫�@�Ӷ}�l	
	MOV DPTR,#TABLE	//�]�w�}�C	
	MOV R1,#24			//�]�w24������counter
NEXT_COLUMN:
	CALL READ_BYTE		//�ഫR0����
	MOV P0,A			//��ܨ�P0
	CALL READ_BYTE
	MOV P2,A			//��ܨ�P2
	CALL READ_BYTE
	MOV P1,A			//��ܨ�P1
	CALL DELAY
	DJNZ R1,NEXT_COLUMN	// �p�GR1!=24�h�A�]�@���������
	JMP	LED_SHOW		//����}�Y�q�s�}�l 	
READ_BYTE:		  
	DJNZ R0,FILL		//��R0�O���O0
	MOV R0,#72			//���mR0
	RET
FILL:
	MOV A,R0			//�NR0���A���@�ثe�n��ܪ���ƶ���
	MOVC A,@A+DPTR
	CPL A				//����A�t�XLED�O	
	RET
;---------------------------------------
TABLE:
	DB 00000000B,00000000B,00000000B
	DB 00000000B,00001100B,00000000B
	DB 00000000B,00001100B,01100000B
	DB 00000000B,00001100B,01100000B
	DB 00000000B,00001100B,01100000B	
	DB 00111111B,11111111B,11100000B
	DB 00111111B,11111111B,11100000B
	DB 00000000B,00001100B,01100000B
	DB 00000000B,00001100B,01100000B
	DB 00000000B,00001100B,01100000B	
	DB 00001100B,00001100B,00110000B
	DB 00001100B,11111111B,00110000B
	DB 00001100B,10011001B,00110000B
	DB 00001100B,10011001B,00110000B
	DB 00001100B,10011001B,00110000B
	DB 11111111B,11111111B,11111110B
	DB 11111111B,11111111B,11111110B
	DB 00001100B,10011001B,00110000B
	DB 00001100B,10011001B,00110000B
	DB 00001100B,10011001B,00110000B
	DB 00001100B,11111111B,00110000B
	DB 00001100B,00000000B,00110000B
	DB 00000000B,00000000B,00000000B
	DB 00000000B,00000000B,00000000B
;----------------------------------------
DELAY:
	MOV R5,#03FH									 
DELAY1:
	MOV R6,#01FH
DELAY2:
	MOV R7,#01H
DELAY3:
	DJNZ R7,DELAY3
	DJNZ R6,DELAY2
	DJNZ R5,DELAY1
	RET
END