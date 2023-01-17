	ORG 0000H
	JMP START
	ORG 0050H
START:
	MOV B,#00H 				//初始化B作為持續旋轉的計數器
	MOV	R4,#00010001B		//初始化R4當作紀錄持續選轉變數
LOOP:
	MOV A,B					
	CJNE A,#00H,REG			//查看B是不是0
ROW1:
	MOV P0,#01111111B		//查看ROW按鍵
	CALL DELAY
	MOV A,P0
	ANL A,#00001111B
	MOV R1,#1				//將R1設為1當作轉的角度的參考
	CJNE A,#00001111B,COL1
ROW2:
	MOV P0,#10111111B
	CALL DELAY
	MOV A,P0
	ANL A,#00001111B
	MOV R1,#5			    //將R1設為5當作轉的角度的參考
	CJNE A,#00001111B,COL1
ROW3:
	MOV	P0,#11011111B 
	CALL DELAY
	MOV	A,P0
	ANL	A,#00001111B
	MOV R1,#0				//將R1設為0當作持續旋轉的訊號
	CJNE A,#00001111B,COL1 
	JMP LOOP				//沒有數字被按下	
COL1:
	CJNE A,#00001110B,COL2	//查看COL按鍵
	MOV R0,#0
	CJNE R1,#00H,COL1_1		//查看要不要持續旋轉
	MOV B,#01H				//counter開始記數
	JMP	REG					//跳到持續旋轉的函數
COL1_1:						//不用持續旋轉
	MOV B,#00H				//將counter歸零
	JMP MAIN1				//跳到顯示
COL2:
	CJNE A,#00001101B,COL3	//同上	
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
	MOV B,#00H				 //不可能有此按鍵排列，忽略偵測
	JMP MAIN1
COL4:
	CJNE A,#00000111B,LOOP 	 //沒有數字被按下	
	MOV R0,#3
	MOV B,#00H				 //不可能有此按鍵排列，忽略偵測
	JMP MAIN1	

REG:
	MOV	A,R4				 //載入旋轉方向變數
	CJNE R0,#00H,LEFT		 //查看旋轉方向	
RIGHT:	
	RL A
	JMP NEXT
LEFT:
	RR A
NEXT:
	MOV p1,A				  //顯示
  	CALL DELAY
	MOV R4,A				  //更新R4供下次使用
	MOV	A,B					  //更新counter
	INC A
	MOV B,A
	CJNE A,#150,LOOP		  //若重複150次旋轉偵測一次按鍵
	MOV B,#01H				  //重置counter
	JMP ROW1

MAIN1:
	CALL DELAY1S			  //呼叫Delay保護按鍵
	MOV R3,#0				  //將R3設為0作為計數
	MOV A,R0				  //整理R0+R1
	ADD A,R1
	MOV R2,A
	SUBB A,#5				  //查看方向	
	JNC MAIN2				  
	MOV A,#00010001B		  //初始化旋轉參數
	JMP FUN1
MAIN2:
	MOV A,R2
	CLR C
	SUBB A,#4
	MOV R2,A
	MOV A,#00010001B
	JMP FUN2
FUN1:
	MOV P1,A				   //旋轉
	CALL DELAY				   //延遲讓機械跟上	
	INC R3					   //R3計數++
	RR A					   //更新旋轉參數
	CJNE R3,#130,FUN1		   //130轉
	MOV R3,#0				   //更新R3給下一層迴圈
	DJNZ R2	,FUN1			   //依照得到的數大小來決定角度
	JMP LOOP				   //回到迴圈
FUN2:
	MOV P1,A
	CALL DELAY
	INC R3
	RL A
	CJNE R3,#130,FUN2
	MOV R3,#0
	DJNZ R2,FUN2
	JMP LOOP
	
;-----保護Delay-----
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
;-----普通Delay-----
DELAY:
	MOV R5,#200
DELAY1:
	MOV R6,#250
DELAY2:
	DJNZ R6,DELAY2
	DJNZ R5,DELAY1
	RET
END