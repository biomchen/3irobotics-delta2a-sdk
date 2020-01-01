#ifndef BSP_UART_H
#define BSP_UART_H

#include "stm32f10x.h"
#include <stdio.h>

/*******************************************************************************************/
//Buff长度定义
/*******************************************************************************************/
#define	RX_BUFFER_LEN				256
#define TX_BUFFER_LEN               2048
#define TX_BUFF_MASK                0x7FF

/*******************************************************************************************/
//发送缓存结构定义
/*******************************************************************************************/
typedef struct
{
	uint64_t RIndex;
	uint64_t WIndex;
	u8 Buff[TX_BUFFER_LEN];
}T_TX_BUFF;

/*******************************************************************************************/
//接收缓存结构定义
/*******************************************************************************************/
typedef struct
{
	u8 Rdy;
	u16 Len;
	u8 Buff[RX_BUFFER_LEN + 20];
}T_RX_BUFF;

/*******************************************************************************************/
//外部变量声明
/*******************************************************************************************/
extern T_TX_BUFF TxBuffer;
extern T_RX_BUFF RxBuffer;
/*******************************************************************************************/

void USART1_Init(int baud);
/*******************************************************************************************/
void ProcessUartRxData(void);
/*******************************************************************************************/
#endif
