#ifndef __PROTOCOL_H
#define __PROTOCOL_H
#include "sys.h"
#include "..\..\drivers\485\max485.h"
#include "mcheck.h"
#include "inputregister_m.h"
#include "holdregister_m.h"
#include "funcdisc_m.h"

//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////

//#define  SLAVE_ADDRESS  0x02

//#define  SLAVE_ADDRESS  0x01


#define M_MAX_FRAME_LENGTH	64		//最大帧长度为261字节 地址+功能+帧号+数据长度+数据+CRC(CRC16有2字节)
#define M_MIN_FRAME_LENGTH	5		//最小帧长度为5字节 地址+功能+帧号+数据长度+CRC8/XOR/SUM



//校验方式宏定义
#define M_FRAME_CHECK_SUM	0		//校验和
#define M_FRAME_CHECK_XOR	1		//异或校验
#define M_FRAME_CHECK_CRC8	2		//CRC8校验
#define M_FRAME_CHECK_CRC16	3		//CRC16校验


//返回结果：错误类型定义
typedef enum {
    MR_OK=0,						//正常
    MR_FRAME_FORMAT_ERR = 1,		//帧格式错误
    MR_FRAME_CHECK_ERR = 2,			//校验值错位
    MR_FRAME_SLAVE_ADDRESS=3,       //帧地址错误
    MR_FRANE_ILLEGAL_FUNCTION =4,   //功能码错误
    MR_FRAME_ILLEGAL_DATA=5,        //帧数据错误
    MR_MEMORY_ERR = 6,				//内存错误
} m_result;

//类modbus 接收帧定义
__packed typedef struct {

    u8 address;						//设备地址：0，广播地址；1~255，设备地址。
    u8 function;					//帧功能，0~255
    u8 count;						//帧编号
    u8 datalen;					//有效数据长度
    u8 *data;						//数据存储区
    u16 chkval;						//校验值
} m_rev_frame_typedef;


//类modbus 发送帧定义
__packed typedef struct {

    u8 address;						//设备地址：0，广播地址；1~255，设备地址。
    u8 function;					//帧功能，0~255
    u16 reg_add;				    //地址编号
    u16 reg_cnt_value;				//reg cnt 或者 value
    u16 chkval;						//校验值
} m_send_frame_typedef;

//类modbus协议管理器
typedef  struct {
    u8* rxbuf;						//接收缓存区
    u16 rxlen;						//接收数据的长度
    u8  frameok;					//一帧数据接收完成标记：0，还没完成；1，完成了一帧数据的接收

    u8 checkmode;					//校验模式：0,校验和;1,异或;2,CRC8;3,CRC16
} m_protocol_dev_typedef;

extern m_protocol_dev_typedef   m_ctrl_dev;			//定义modbus控制器
extern m_send_frame_typedef     m_send_frame;
extern m_rev_frame_typedef      m_rev_frame;

m_result mb_unpack_frame(m_send_frame_typedef *tx,m_rev_frame_typedef *rx);
//void mb_packsend_frame(m_rev_frame_typedef *fx);		//打包一帧数据，并发送

m_result mb_init(u8 checkmode);						//初始化MODBUS,申请内存

void mb_destroy(void);								//结束MODBUS,释放内存

#endif













