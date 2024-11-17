#ifndef __SH367309_H
#define __SH367309_H

#include "stm32f10x.h"

#define CONF     0X40
#define BALANCEH 0X41
#define BALANCEL 0X42
#define BSTATUS1 0X43
#define BSTATUS2 0X44
#define BSTATUS3 0X45
#define TEMP1H   0X46
#define TEMP1L   0X47
#define TEMP2H   0X48
#define TEMP2L   0X49
#define TEMP3H   0X4A
#define TEMP3L   0X4B
#define CURH     0X4C
#define CURL     0X4D
#define CELL1H   0X4E
#define CELL1L   0X4F
#define CELL2H   0X50
#define CELL2L   0X51
#define CELL3H   0X52
#define CELL3L   0X53
#define CELL4H   0X54
#define CELL4L   0X55
#define CELL5H   0X56
#define CELL5L   0X57
#define CELL6H   0X58
#define CELL6L   0X59
#define CELL7H   0X5A
#define CELL7L   0X5B
#define CELL8H   0X5C
#define CELL8L   0X5D
#define CELL9H   0X5E
#define CELL9L   0X5F
#define CELL10H  0X60
#define CELL10L  0X61
#define CELL11H  0X62
#define CELL11L  0X63
#define CELL12H  0X64
#define CELL12L  0X65
#define CELL13H  0X66
#define CELL13L  0X67
#define CELL14H  0X68
#define CELL14L  0X69
#define CELL15H  0X6A
#define CELL15L  0X6B
#define CELL16H  0X6C
#define CELL16L  0X6D

#define CADCDH   0X6E
#define CADCDL   0X6F


#define BFLAG1    0X70
#define BFLAG2    0X71
#define RSTSTAT   0X72

#define OVPThreshold     4500  // 3150-4700
#define OV_Re_Threshold  4450

#define UVPThreshold  2400 //  1580-3100
#define UV_Re_Threshold  2500

#define OTPThreshold  60 
#define UTPThreshold  -20 
#define TempPThreshold -50


#define LOW_BYTE(Data)			(unsigned char)(0xff & Data)
#define HIGH_BYTE(Data)			(unsigned char)(0xff & (Data >> 8))

void SYS_CONF(void);
u8 READ_BSTATUS1(void);
u8 READ_BSTATUS2(void);
u8 READ_BSTATUS3(void);
u8 READ_BFLAG1(void);
u8 READ_BFLAG2(void);



void Get_offset(void);
void Get_Battery1(void);
void Get_Battery2(void);
void Get_Battery3(void);
void Get_Battery4(void);
void Get_Battery5(void);
void Get_Battery6(void);
void Get_Battery7(void);
void Get_Battery8(void);
void Get_Battery9(void);
void Get_Battery10(void);
void Get_Update_Data(void);
void OV_UV_1_PROTECT(void);
void BQ_1_config(void);
void SHIP_1_BQ769(void);
void ALERT_1_Recognition(void );
void Temp_ALERT(void);
void Get_SH367309_Current(void);
void Get_SH367309_Temp1(void);
void Get_SH367309_Temp2(void);
void Get_SH367309_Temp3(void);
unsigned char CRC8(unsigned char *ptr, unsigned char len,unsigned char key);


void OV_UV_2_PROTECT(void);
void ALERT_2_Recognition(void );
void BQ76930_config(void);
void Get_Update_ALL_BAT(void);
void BQ_1_2_config(void);
void OV_UV_1_2_PROTECT(void);
void WAKE_ALL_DEVICE(void);
void Only_Open_CHG(void);
void Only_Close_CHG(void);
void Only_Open_DSG(void);
void Only_Close_DSG(void);
void Open_DSG_CHG(void);
void Close_DSG_CHG(void);
void OCD_SCD_PROTECT(void);
void SHIP_ALL_DEVICE(void);
void Led_Alarm(void);
void Get_SOC(void);
void Cell_Balance(int Difference);
#endif
