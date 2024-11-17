#include "SH367309.h"
#include "SYSTICK.h" 

#include "i2c1.h"
#include "can.h"
#include "usart.h"
#include "math.h"
#include "string.h"
#include "IO_CTRL.h"
#include "usart2.h"
/*****************************

   1.采集BQ76930的14位ADC的增益和偏置电压:void get_offset(void)
   2.采集单体电压:void Get_Batteryx(void),其中x取值1-10；
   3.BQ76930初始化 void BQ_config(void)
   4.读取BQ76930寄存器值： void readbqstate(void)
   5.
******************************/
/***********************
fuction:void get_offset(void)
************************/

/****************************************
fuction: void Get_Battery1(void)
description:系统寄存器配置,详见手册第69页
Parameters:开启CADC进行电流采集
******************************************/
 void SYS_CONF(void)
 {
    IIC1_write_one_byte(CONF,0X78);
 }



/****************************************
fuction: void Get_Battery1(void)
description:获取第1号单体电池电压
Parameters:batterylval[0],battery1val[1];
******************************************/
 u8 READ_BSTATUS1(void)
 {
	unsigned char buf[2];
  buf[0]=IIC1_read_one_byte(BSTATUS1);
	return buf[0];
 }
/****************************************
fuction: void Get_Battery1(void)
description:获取第1号单体电池电压
Parameters:batterylval[0],battery1val[1];
******************************************/
 u8 READ_BSTATUS2(void)
 {
	unsigned char buf[2];
  buf[0]=IIC1_read_one_byte(BSTATUS2);
	return buf[0];
 }
/****************************************
fuction: void Get_Battery1(void)
description:获取第1号单体电池电压
Parameters:batterylval[0],battery1val[1];
******************************************/
 u8 READ_BSTATUS3(void)
 {
	unsigned char buf[2];
  buf[0]=IIC1_read_one_byte(BSTATUS3);
	return buf[0];
 }
 /****************************************
fuction: void Get_Battery1(void)
description:获取第1号单体电池电压
Parameters:batterylval[0],battery1val[1];
******************************************/
 u8 READ_BFLAG1(void)
 {
	unsigned char buf[2];
  buf[0]=IIC1_read_one_byte(BFLAG1);
	return buf[0];
 }
  /****************************************
fuction: void Get_Battery1(void)
description:获取第1号单体电池电压
Parameters:batterylval[0],battery1val[1];
******************************************/
 u8 READ_BFLAG2(void)
 {
	unsigned char buf[2];
  buf[0]=IIC1_read_one_byte(BFLAG2);
	return buf[0];
 }
 int Batteryval[50]={0};
unsigned char shang[100]={0xAA,0x01};
unsigned char shang1[100]={0xAA,0x02};
unsigned char shang2[100]={0xAA,0x03};
unsigned char shang3[100]={0xAA,0x04};
unsigned char shang4[100]={0xAA,0x05};


unsigned char can_buf1[8]={0xAA,0x01};
unsigned char can_buf2[8]={0xAA,0x02};
unsigned char can_buf3[8]={0xAA,0x03};
unsigned char can_buf4[8]={0xAA,0x04};
unsigned char can_buf5[8]={0xAA,0x05};
unsigned char can_buf6[8]={0xAA,0x06};
unsigned char can_buf7[8]={0xAA,0x07};
unsigned char can_buf8[8]={0xAA,0x08};
unsigned char can_buf9[8]={0xAA,0x09};
unsigned char can_buf10[8]={0xAA,0x10};

 void Get_Battery1(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL1H);
  readbattbuf[0] = IIC1_read_one_byte(CELL1L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];


	Batteryval[0]= batteryval1*5/32;
//		printf("VOL1=%d\r\n",Batteryval[0]);

	shang[2]=Batteryval[0]>>8;
	shang[3]=Batteryval[0]&0XFF;
	can_buf1[2]=shang[2];
	can_buf1[3]=shang[3];

}


/****************************************
fuction: void Get_Battery2(void)
description:获取第2号单体电池电压
Parameters:battery2val[0],battery2val[1];
******************************************/
 void Get_Battery2(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL2H);
  readbattbuf[0] = IIC1_read_one_byte(CELL2L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

//	printf("VOL2=%d\r\n",batteryval1*5/32);

		Batteryval[1]= batteryval1*5/32;

	shang[4]=Batteryval[1]>>8;
	shang[5]=Batteryval[1]&0XFF;

	can_buf1[4]=shang[4];
	can_buf1[5]=shang[5];

}
/****************************************
fuction: void Get_Battery3(void)
description:获取第3号单体电池电压
Parameters:battery3val[0],battery3val[1];
******************************************/
 void Get_Battery3(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL3H);
  readbattbuf[0] = IIC1_read_one_byte(CELL3L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

//	printf("VOL3=%d\r\n",batteryval1*5/32);

	Batteryval[2]= batteryval1*5/32;

	shang[6]=Batteryval[2]>>8;
	shang[7]=Batteryval[2]&0XFF;
	

	can_buf1[6]=shang[6];
	can_buf1[7]=shang[7];

}
/****************************************
fuction: void Get_Battery4(void)
description:获取第4号单体电池电压
Parameters:battery4val[0],battery4val[1];
******************************************/
 void Get_Battery4(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL4H);
  readbattbuf[0] = IIC1_read_one_byte(CELL4L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

//	printf("VOL4=%d\r\n",batteryval1*5/32);

		Batteryval[3]= batteryval1*5/32;

	shang[8]=Batteryval[3]>>8;
	shang[9]=Batteryval[3]&0XFF;

	can_buf2[2]=shang[8];
	can_buf2[3]=shang[9];

}/****************************************
fuction: void Get_Battery5(void)
description:获取第5号单体电池电压
Parameters:battery5val[0],battery5val[1];
******************************************/
 void Get_Battery5(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL5H);
  readbattbuf[0] = IIC1_read_one_byte(CELL5L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

//	printf("VOL5=%d\r\n",batteryval1*5/32);

		Batteryval[4]= batteryval1*5/32;

	shang[10]=Batteryval[4]>>8;
	shang[11]=Batteryval[4]&0XFF;

	can_buf2[4]=shang[10];
	can_buf2[5]=shang[11];

}
/****************************************
fuction: void Get_Battery6(void)
description:获取第6号单体电池电压
Parameters:battery6val[0],battery6val[1];
******************************************/
 void Get_Battery6(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL6H);
  readbattbuf[0] = IIC1_read_one_byte(CELL6L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

//	printf("VOL6=%d\r\n",batteryval1*5/32);

		Batteryval[5]= batteryval1*5/32;

	shang[12]=Batteryval[5]>>8;
	shang[13]=Batteryval[5]&0XFF;

	can_buf2[6]=shang[12];
	can_buf2[7]=shang[13];

}/****************************************
fuction: void Get_Battery7(void)
description:获取第7号单体电池电压
Parameters:battery7val[0],battery7val[1];
******************************************/
 void Get_Battery7(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL7H);
  readbattbuf[0] = IIC1_read_one_byte(CELL7L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

	printf("VOL7=%d\r\n",batteryval1*5/32);

		Batteryval[6]= batteryval1*5/32;

	shang[14]=Batteryval[6]>>8;
	shang[15]=Batteryval[6]&0XFF;

	can_buf3[2]=shang[14];
	can_buf3[3]=shang[15];

}
/****************************************
fuction: void Get_Battery8(void)
description:获取第8号单体电池电压
Parameters:battery8val[0],battery8val[1];
******************************************/
 void Get_Battery8(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL8H);
  readbattbuf[0] = IIC1_read_one_byte(CELL8L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

	printf("VOL8=%d\r\n",batteryval1*5/32);

		Batteryval[7]= batteryval1*5/32;

	shang[16]=Batteryval[7]>>8;
	shang[17]=Batteryval[7]&0XFF;

	can_buf3[4]=shang[16];
	can_buf3[5]=shang[17];

}

/****************************************
fuction: void Get_Battery9(void)
description:获取第9号单体电池电压
Parameters:battery9val[0],battery9val[1];
******************************************/
void Get_Battery9(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL9H);
  readbattbuf[0] = IIC1_read_one_byte(CELL9L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

	printf("VOL9=%d\r\n",batteryval1*5/32);

		Batteryval[8]= batteryval1*5/32;

	shang[18]=Batteryval[8]>>8;
	shang[19]=Batteryval[8]&0XFF;
	
  shang1[2]=shang[18];
	shang1[3]=shang[19];

	can_buf3[6]=shang[18];
	can_buf3[7]=shang[19];

}
/****************************************
fuction: void Get_Battery10(void)
description:获取第10号单体电池电压
Parameters:battery10val[0],battery10val[1];
******************************************/
void Get_Battery10(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL10H);
  readbattbuf[0] = IIC1_read_one_byte(CELL10L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

	printf("VOL10=%d\r\n",batteryval1*5/32);

	Batteryval[9]= batteryval1*5/32;

	shang[20]=Batteryval[9]>>8;
	shang[21]=Batteryval[9]&0XFF;
  shang1[4]=shang[20];
	shang1[5]=shang[21];

	can_buf4[2]=shang[20];
	can_buf4[3]=shang[21];

}
/****************************************
fuction: void Get_Battery10(void)
description:获取第11号单体电池电压
Parameters:battery10val[0],battery10val[1];
******************************************/
void Get_Battery11(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL11H);
  readbattbuf[0] = IIC1_read_one_byte(CELL11L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

	printf("VOL11=%d\r\n",batteryval1*5/32);

	Batteryval[10]= batteryval1*5/32;

	shang[22]=Batteryval[10]>>8;
	shang[23]=Batteryval[10]&0XFF;
  shang1[6]=shang[22];
	shang1[7]=shang[23];
	
	can_buf4[4]=shang[22];
	can_buf4[5]=shang[23];

}
/****************************************
fuction: void Get_Battery10(void)
description:获取第12号单体电池电压
Parameters:battery10val[0],battery10val[1];
******************************************/
void Get_Battery12(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL12H);
  readbattbuf[0] = IIC1_read_one_byte(CELL12L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

	printf("VOL12=%d\r\n",batteryval1*5/32);

		Batteryval[11]= batteryval1*5/32;

	shang[24]=Batteryval[11]>>8;
	shang[25]=Batteryval[11]&0XFF;
  shang1[8]=shang[24];
	shang1[9]=shang[25];

	can_buf4[6]=shang[24];
	can_buf4[7]=shang[25];

}
/****************************************
fuction: void Get_Battery10(void)
description:获取第13号单体电池电压
Parameters:battery10val[0],battery10val[1];
******************************************/
void Get_Battery13(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL13H);
  readbattbuf[0] = IIC1_read_one_byte(CELL13L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

	printf("VOL13=%d\r\n",batteryval1*5/32);

		Batteryval[12]= batteryval1*5/32;

	shang[26]=Batteryval[12]>>8;
	shang[27]=Batteryval[12]&0XFF;
  shang1[10]=shang[26];
	shang1[11]=shang[27];
	
	can_buf5[2]=shang[26];
	can_buf5[3]=shang[27];

}

/****************************************
fuction: void Get_Battery10(void)
description:获取第14号单体电池电压
Parameters:battery10val[0],battery10val[1];
******************************************/
void Get_Battery14(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL14H);
  readbattbuf[0] = IIC1_read_one_byte(CELL14L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

	printf("VOL14=%d\r\n",batteryval1*5/32);

		Batteryval[13]= batteryval1*5/32;

	shang[28]=Batteryval[13]>>8;
	shang[29]=Batteryval[13]&0XFF;
  shang1[12]=shang[28];
	shang1[13]=shang[29];
	
	can_buf5[4]=shang[28];
	can_buf5[5]=shang[29];

}
/****************************************
fuction: void Get_Battery10(void)
description:获取第15号单体电池电压
Parameters:battery10val[0],battery10val[1];
******************************************/
void Get_Battery15(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL15H);
  readbattbuf[0] = IIC1_read_one_byte(CELL15L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

	printf("VOL15=%d\r\n",batteryval1*5/32);

		Batteryval[14]= batteryval1*5/32;

	shang[30]=Batteryval[14]>>8;
	shang[31]=Batteryval[14]&0XFF;
  shang1[14]=shang[30];
	shang1[15]=shang[31];
	
	can_buf5[6]=shang[30];
	can_buf5[7]=shang[31];

}
/****************************************
fuction: void Get_Battery10(void)
description:获取第16号单体电池电压
Parameters:battery10val[0],battery10val[1];
******************************************/
void Get_Battery16(void)
{
  unsigned int readbattbuf[2];
  unsigned int battery1val[2];
  short batteryval1;
	
  readbattbuf[1] = IIC1_read_one_byte(CELL16H);
  readbattbuf[0] = IIC1_read_one_byte(CELL16L);
 
  batteryval1= (readbattbuf[1] << 8) +readbattbuf[0];

	printf("VOL16=%d\r\n",batteryval1*5/32);

	Batteryval[15]= batteryval1*5/32;

	shang[32]=Batteryval[15]>>8;
	shang[33]=Batteryval[15]&0XFF;
  shang1[16]=shang[32];
	shang1[17]=shang[33];
	
	can_buf6[2]=shang[32];
	can_buf6[3]=shang[33];

}
/****************************************
/****************************
获取所有电池的总电压值并用串口1打印出来
 *****************************/
float SOC;
void Get_Update_ALL_Data(void)
{
	int i,Sum_val=0;
  for(i=0;i<15;i++)
	{
	   Sum_val+= Batteryval[i];
	}
	  Batteryval[16] = Sum_val;
//		printf("VOL_ALL=%d\r\n",Batteryval[16]);

	
	
	shang[34]=Batteryval[16]>>24;
	shang[35]=Batteryval[16]>>16;
	shang[36]=Batteryval[16]>>8;
	shang[37]=Batteryval[16]&0XFF;
	
  shang2[10]=shang[36];
	shang2[11]=shang[37];

	can_buf6[4]=shang[34];
	can_buf6[5]=shang[35];
	can_buf6[6]=shang[36];
	can_buf6[7]=shang[37];

}


void Get_SOC(void)
{


float SOC;

   SOC = (float)Batteryval[1];
	SOC = (SOC-2800)/(4200-2800)*100;
	Batteryval[17] = SOC;
//	printf("soc=%d\r\n",Batteryval[17]);
//	Batteryval[7] = SOC;
  shang[38]=(char)Batteryval[17];
  shang2[12]=0;
	shang2[13]=shang[38];
	can_buf7[2]=shang[38];


}






  
/****************************************
fuction: void BQ_1_config(void)
description:BQ76930初始化
Parameters: None
 //0x04寄存器0x19对应SCD延时70uS，放电短路电压33mV；
 //0x05寄存器设置检测电流为1-shot模式；
 //0x06寄存器0x39对应OCD的延时时间80mS，放电过流电压33mV；短路和过流对应电流都是60A.
******************************************/
unsigned char BQ769_INITdata[11]={0xFF,     0x00,    0x00,    0x18,    0X43,      0x00,     0x00,    0x00,    0x00,   0x00,  0x19};
void BQ_1_config(void)
{
   char i;
   for(i=0;i<11;i++)
    {
			delay_ms(50);
//			IIC1_write_one_byte_CRC(BQ769_INITAdd[i],BQ769_INITdata[i]);
    }
}



/****************************************
/****************************************
fuction:void SHIP_1_BQ769(void)
description:BQ76930进入低功耗模式
Parameters: None
******************************************/
void SHIP_1_BQ769(void)
{
//  IIC1_write_one_byte_CRC(SYS_CTRL1,0x19); //01
//  delay_ms(20);
//  IIC1_write_one_byte_CRC(SYS_CTRL1,0x1a); //10
 }

 


/****************************************
fuction:void SHIP_2_BQ769(void)
description:从BQ76930低功耗模式唤醒
Parameters: None
******************************************/
void WAKE_1_BQ769(void)
{
   MCU_WAKE_BQ_ONOFF(1);
	 delay_ms(50);
	 MCU_WAKE_BQ_ONOFF(0);
 }
/****************************************
 
 /****************************************
fuction: void Get_BQCurrent(void)
description:BQ76930电流测量，采样电阻按4mΩ/8计算
Parameters: None
******************************************/

 void Get_SH367309_Current(void)
 {	 
   unsigned char readCurrentbuf[2];
	 unsigned int    Currentbufval;
	 unsigned int  Currentval;
   unsigned char Currentbuf[1];
	 readCurrentbuf[1]=IIC1_read_one_byte(0X4C);
   readCurrentbuf[0]=IIC1_read_one_byte(0X4D);
//	 printf("高位=%X ", (readCurrentbuf[1]& (1 << 7)) == 0 ? 0 : 1);
   Currentbufval = ((readCurrentbuf[1]&0X7F) << 8)+readCurrentbuf[0];

//   Currentbufval = ((readCurrentbuf[1]) << 8)+readCurrentbuf[0];
//	 printf("CUR=%d\r\n",Currentbufval);
   Currentbufval =200*Currentbufval/(26837*4/3/1000);
//	 printf("电流=%d\r\n",Currentbufval);
	 Batteryval[18]=Currentbufval;
	 shang[39]=readCurrentbuf[1]& 0X80 ;
	 shang[40]=Currentbufval>>8;
	 shang[41]=Currentbufval&0XFF;
	 
	shang2[14]=shang[40];
	shang2[15]=shang[41];

	 can_buf7[3]=shang[39];
	 can_buf7[4]=shang[40];
	 can_buf7[5]=shang[41];
	 
 }
 /****************************************
fuction: void Get_BQ_1_Temp(void)
description:BQ76930 103AT温度测量
Parameters: None
******************************************/

 float  Tempval_1,Tempval_2,Tempval_3;


 void Get_SH367309_Temp1(void)
 {
   float Rt=0;
   float Rp=10000;
   float T2=273.15+25;
   float Bx=3950;
   float Ka=273.15;
   unsigned char readTempbuf[3];
	 float  TempRes;
   unsigned char Tempbuf[1];
//	 readTempbuf[2]=IIC1_read_one_byte(0X19);
//	 printf("CUR=%d\r\n",readTempbuf[2]);

	 readTempbuf[1]=IIC1_read_one_byte(0X46);
   readTempbuf[0]=IIC1_read_one_byte(0X47);

   TempRes = (readTempbuf[1] << 8 ) | readTempbuf[0];
	 TempRes =TempRes*(6.8+0.05*68)/(32768-TempRes)*1000;
//	 TempRes = (10000*(TempRes*382/1000))/(3300-(TempRes*382/1000)); 
   Tempval_1 = 1/(1/T2+(log(TempRes/Rp))/Bx)- Ka + 0.5;
	 
	 Batteryval[19] = Tempval_1*100;
//	 printf("TEMP1=%f\r\n",Tempval_1);

	 shang[42]=Batteryval[19]>>8;
	 shang[43]=Batteryval[19]&0XFF;
    shang2[16]=Tempval_1;

	 can_buf7[6]=shang[42];
	 can_buf7[7]=shang[43];

	 
 }
 
 void Get_SH367309_Temp2(void)
 {
   float Rt=0;
   float Rp=10000;
   float T2=273.15+25;
   float Bx=3950;
   float Ka=273.15;
   unsigned char readTempbuf[3];
	 float  TempRes;
   unsigned char Tempbuf[1];
//	 readTempbuf[2]=IIC1_read_one_byte(0X19);

	 readTempbuf[1]=IIC1_read_one_byte(0X48);
   readTempbuf[0]=IIC1_read_one_byte(0X49);

   TempRes = (readTempbuf[1] << 8 ) | readTempbuf[0];
	 TempRes =TempRes*(6.8+0.05*68)/(32768-TempRes)*1000;
//	 TempRes = (10000*(TempRes*382/1000))/(3300-(TempRes*382/1000)); 
   Tempval_2 = 1/(1/T2+(log(TempRes/Rp))/Bx)- Ka + 0.5;
	 
	 Batteryval[20] = Tempval_2*100;
//	 printf("TEMP2=%f\r\n",Tempval_2);

	 shang[44]=Batteryval[20]>>8;
	 shang[45]=Batteryval[20]&0XFF;

	 can_buf8[2]=shang[44];
	 can_buf8[3]=shang[45];

	 
 } 
 
  void Get_SH367309_Temp3(void)
 {
   float Rt=0;
   float Rp=10000;
   float T2=273.15+25;
   float Bx=3950;
   float Ka=273.15;
   unsigned char readTempbuf[3];
	 float  TempRes;
   unsigned char Tempbuf[1];
//	 readTempbuf[2]=IIC1_read_one_byte(0X19);

	 readTempbuf[1]=IIC1_read_one_byte(0X4A);
   readTempbuf[0]=IIC1_read_one_byte(0X4B);

   TempRes = (readTempbuf[1] << 8 ) | readTempbuf[0];
	 TempRes =TempRes*(6.8+0.05*68)/(32768-TempRes)*1000;
//	 TempRes = (10000*(TempRes*382/1000))/(3300-(TempRes*382/1000)); 
   Tempval_3 = 1/(1/T2+(log(TempRes/Rp))/Bx)- Ka + 0.5;
	 
	 Batteryval[21] = Tempval_3*100;
//	 printf("TEMP3=%f\r\n",Tempval_3);
	 shang[46]=Batteryval[21]>>8;
	 shang[47]=Batteryval[21]&0XFF;

	 can_buf8[4]=shang[46];
	 can_buf8[5]=shang[47];

	 
 }
 /****************************************
fuction: 均衡的1、2、3、4、5、6、7、8、9、10分别表示电池组上第1到10节的均衡
description:
Parameters: None
******************************************/
 unsigned char balanceL[10],balanceH[10];
void Battery1_Balance(void)
{
	 balanceL[0]|= (0x01 << 0);
   IIC1_write_one_byte_CRC(0X42,balanceL[0]);
}

void Battery2_Balance(void)
{
	 balanceL[0]|= (0x01 << 1);
   IIC1_write_one_byte_CRC(0X42,balanceL[0]);
}
void Battery3_Balance(void)
{
	 balanceL[0]|= (0x01 << 2);
   IIC1_write_one_byte_CRC(0X42,balanceL[0]);
}
void Battery4_Balance(void)
{
	 balanceL[0]|= (0x01 << 3);
   IIC1_write_one_byte_CRC(0X42,balanceL[0]);
}
void Battery5_Balance(void)
{
	 balanceL[0]|= (0x01 << 4);
   IIC1_write_one_byte_CRC(0X42,balanceL[0]);
}

void Battery6_Balance(void)
{
	 balanceL[0]|= (0x01 << 5);
   IIC1_write_one_byte_CRC(0X42,balanceL[0]);
}

void Battery7_Balance(void)
{
	 balanceL[0]|= (0x01 << 6);
   IIC1_write_one_byte_CRC(0X42,balanceL[0]);
}
void Battery8_Balance(void)
{
	 balanceL[0]|= (0x01 << 7);
   IIC1_write_one_byte_CRC(0X42,balanceL[0]);
}
void Battery9_Balance(void)
{
	 balanceH[0]|= (0x01 << 0);
   IIC1_write_one_byte_CRC(0X41,balanceH[0]);
}
void Battery10_Balance(void)
{
	 balanceH[0]|= (0x01 << 1);
   IIC1_write_one_byte_CRC(0X41,balanceH[0]);
}
void Battery11_Balance(void)
{
	 balanceH[0]|= (0x01 << 2);
   IIC1_write_one_byte_CRC(0X41,balanceH[0]);
}
void Battery12_Balance(void)
{
	 balanceH[0]|= (0x01 << 3);
   IIC1_write_one_byte_CRC(0X41,balanceH[0]);
}
void Battery13_Balance(void)
{
	 balanceH[0]|= (0x01 << 4);
   IIC1_write_one_byte_CRC(0X41,balanceH[0]);
}
void Battery14_Balance(void)
{
	 balanceH[0]|= (0x01 << 5);
   IIC1_write_one_byte_CRC(0X41,balanceH[0]);
}
void Battery15_Balance(void)
{
	 balanceH[0]|= (0x01 << 6);
   IIC1_write_one_byte_CRC(0X41,balanceH[0]);
}
void Battery16_Balance(void)
{
	 balanceH[0]|= (0x01 << 7);
   IIC1_write_one_byte_CRC(0X41,balanceH[0]);
}



void Balance_Stop(void)
{
	 IIC1_write_one_byte_CRC(0X41,0X00);
   IIC1_write_one_byte_CRC(0X42,0X00);
}

void Balance_Start(char i)
{
	if(i==0)
	{
	   Battery1_Balance();
	}
	else if(i==1)
	{
	   Battery2_Balance();
	}
	else if(i==2)
	{
	   Battery3_Balance();
	}
	else if(i==3)
	{
	   Battery4_Balance();
	}
	else if(i==4)
	{
	   Battery5_Balance();
	}
	else if(i==5)
	{
	   Battery6_Balance();
	}
		else if(i==6)
	{
	   Battery7_Balance();
	}

		else if(i==7)
	{
	   Battery8_Balance();
	}

		else if(i==8)
	{
	   Battery9_Balance();
	}

		else if(i==9)
	{
	   Battery10_Balance();
	}
		else if(i==10)
	{
	   Battery11_Balance();
	}
		else if(i==11)
	{
	   Battery12_Balance();
	}
		else if(i==12)
	{
	   Battery13_Balance();
	}
		else if(i==13)
	{
	   Battery14_Balance();
	}
		else if(i==14)
	{
	   Battery15_Balance();
	}
		else if(i==15)
	{
	   Battery16_Balance();
	}

}
 
 int imax,imin,imaxp,iminp;
void Cell_Battery_MAX_MIN(void)
{
	char i;
	imaxp=iminp=0;
	imax=imin=Batteryval[0];
	for(i=0;i<5;i++)
	{
	if(Batteryval[i]>imax)
        {
            imax=Batteryval[i];
            imaxp=i;
        }
        if(Batteryval[i]<imin)
        {
            imin=Batteryval[i];
            iminp=i;
        }
	}


}


void Cell_Balance(int Difference)
{
 Cell_Battery_MAX_MIN();
 if((imax - imin)>Difference)
 {
	  Balance_Start(imaxp);
 }
 else Balance_Stop();

}
 
 unsigned char BMS_sta,DSG_STA,CHG_STA,DSG_STA_FLAG,CHG_STA_FLAG;	
void BMS_STA(void)
	{
	 BMS_sta =READ_BSTATUS3();
	 DSG_STA =((BMS_sta& (1 << 0)) == 0 ? 0 : 1);
	 CHG_STA = ((BMS_sta& (1 << 1)) == 0 ? 0 : 1);
	 shang[48]=DSG_STA;
	 shang[49]=CHG_STA;
		
	can_buf8[6]=shang[48];
	can_buf8[7]=shang[49];
	}
 

 void Update_val(void)
{
  char NEW[50]={0};
	int n;
	  for(n=0;n<60;n++)

		{
			USART_SendData(USART1, shang[n]); //发送一个字节数据
			delay_ms(10);
			
		}
		
	  USART2_Printf( shang,20,ASCII_CODE);	
		delay_ms(200);
		USART2_Printf( shang1,20,ASCII_CODE);
		delay_ms(200);
		USART2_Printf( shang2,20,ASCII_CODE);

		
		Can_Send_Msg(can_buf1,8,0x0001);
		delay_ms(5);
		Can_Send_Msg(can_buf2,8,0x0002);
		delay_ms(5);
		Can_Send_Msg(can_buf3,8,0x0003);
		delay_ms(5);
		Can_Send_Msg(can_buf4,8,0x0004);
		delay_ms(5);
		Can_Send_Msg(can_buf5,8,0x0005);
		delay_ms(5);
		Can_Send_Msg(can_buf6,8,0x0006);
		delay_ms(5);
		Can_Send_Msg(can_buf7,8,0x0007);
    delay_ms(5);
		Can_Send_Msg(can_buf8,8,0x0008);
    delay_ms(5);

		
		
		
		
  UartSend("CLR(61);\r\n");
  delay_ms(200);
	UartSend("CLR(61);\r\n");
  delay_ms(200);
  UartSend("DIR(1);\r\n");
  delay_ms(200);
	sprintf(NEW,"DCV16(0,0,'%s%d%s',3);\r\n","第一节电压:",Batteryval[0],"mV"); 
  UartSend(NEW); 
  
	delay_ms(200); 

	sprintf(NEW,"DCV16(0,20,'%s%d%s',3);\r\n","第二节电压:",Batteryval[1],"mV"); 
  UartSend(NEW); 
		
  delay_ms(200);
  
	
	sprintf(NEW,"DCV16(0,40,'%s%d%s',3);\r\n","第三节电压:",Batteryval[2],"mV"); 
  UartSend(NEW); 
  
	delay_ms(200); 
	sprintf(NEW,"DCV16(0,60,'%s%d%s',3);\r\n","第四节电压:",Batteryval[3],"mV"); 
  UartSend(NEW); 
  
	delay_ms(200); 
	sprintf(NEW,"DCV16(0,80,'%s%d%s',3);\r\n","第五节电压:",Batteryval[4],"mV"); 
  UartSend(NEW); 
  
	delay_ms(200); 
	sprintf(NEW,"DCV16(0,100,'%s%d%s',3);\r\n","第六节电压:",Batteryval[5],"mV"); 
  UartSend(NEW); 
  	delay_ms(1000);
	UartSend("CLR(61);\r\n");
  delay_ms(200);

	delay_ms(200); 
	sprintf(NEW,"DCV16(0,00,'%s%d%s',3);\r\n","总电压:",Batteryval[16],"mV");
	
  UartSend(NEW);   
  delay_ms(200); 
	sprintf(NEW,"DCV16(0,20,'%s%d%s',3);\r\n","电池SOC为:",Batteryval[17],"%"); 
  UartSend(NEW); 
  
	delay_ms(200); 
	sprintf(NEW,"DCV16(0,40,'%s%.2f%s',3);\r\n","电池温度为:",Tempval_1,"℃"); 
  UartSend(NEW);

	delay_ms(200); 
	sprintf(NEW,"DCV16(0,60,'%s%d%s',3);\r\n","电流:",Batteryval[18],"mA"); 
  UartSend(NEW); 
  
	delay_ms(200);
	
	sprintf(NEW,"DCV24(0,20,'%s',3);\r\n",""); 
  UartSend(NEW);
	
	delay_ms(100);
	
	
	

}
 void Get_Update_Data(void)
{	  
    Get_Battery1();
    Get_Battery2();
    Get_Battery3();
    Get_Battery4();
    Get_Battery5();
    Get_Battery6(); 	
		Get_Update_ALL_Data();//总电压
	  Get_SOC();
    Get_SH367309_Temp1();
	  Get_SH367309_Temp2();
	  Get_SH367309_Temp3();
    Get_SH367309_Current();
    BMS_STA();
		Update_val();			
}
 int OT_Alarm_flag,UT_Alarm_flag;
 
 
 
 
/****************************************
fuction:void readbqstate(void)
description:读取报警信号值
Parameters: UV_Alarm_flagOV_Alarm_flag
            SCD_Alarm_flag,OCD_Alarm_flag
******************************************/

 int UV_Alarm_flag,OV_Alarm_flag,SCD_Alarm_flag,OCD_Alarm_flag;




unsigned char CRC8(unsigned char *ptr, unsigned char len,unsigned char key)
{
	unsigned char i;
	unsigned char crc=0;
	while(len--!=0)
	{
		for(i=0x80; i!=0; i/=2)
		{
			if((crc & 0x80) != 0)
			{
				crc *= 2;
				crc ^= key;
			}
			else
				crc *= 2;

			if((*ptr & i)!=0)
				crc ^= key;
		}
		ptr++;
	}
	return(crc);
}

