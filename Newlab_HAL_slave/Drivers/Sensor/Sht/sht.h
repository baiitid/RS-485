
#ifndef _SHT_T_
#define _SHT_T_

#include <stdint.h>

/*******************************************************************
*函数：void SHT_Init(void)
*功能：温湿度传感器初始化
*输入：无
*输出：无
*返回：无
*特殊说明：无
*******************************************************************/
void SHT_Init(void);

/*******************************************************************
*函数：uint8_t ChkSum(uint8_t *buf, uint8_t len)
*功能：采集传感器数据：温度、湿度
*输入：无
*输出：
*       int8_t *tem, 温度
*       uint8_t *hum, 湿度
*返回：无
*特殊说明：无
*******************************************************************/
void SHT_SmpSnValue(int8_t *tem, uint8_t *hum);

#endif
