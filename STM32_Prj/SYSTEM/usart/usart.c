#include "sys.h"
#include "usart.h"
//C库
#include "string.h"
#include "stdlib.h"

#include "rgb.h"

#pragma import(__use_no_semihosting)
//标准库需要的支持函数
struct __FILE
{
    int handle;

};

FILE __stdout;
//定义_sys_exit()以避免使用半主机模式
_sys_exit(int x)
{
    x = x;
}
//重定义fputc函数
int fputc(int ch, FILE* f)
{
    while((USART1->SR & 0X40) == 0); //循环发送,直到发送完毕
    USART1->DR = (u8) ch;
    return ch;
}

void UART1_Config(u32 bound)
{
    //GPIO端口设置
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);	//使能USART1，GPIOA时钟

    //USART1_TX   GPIOA.9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
    GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.9

    //USART1_RX	  GPIOA.10初始化
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.10

    //Usart1 NVIC 配置
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3 ; //抢占优先级3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
    NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器

    //USART 初始化设置

    USART_InitStructure.USART_BaudRate = bound;//串口波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
    USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

    USART_Init(USART1, &USART_InitStructure); //初始化串口1
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启串口接受中断
    USART_Cmd(USART1, ENABLE);                    //使能串口1

}
uint8_t rx_buf[100];
uint8_t rx_len;
void USART1_IRQHandler(void)                	//串口1中断服务程序
{
	uint8_t dat;
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
    {
        dat = USART_ReceiveData(USART1);	//读取接收到的数据
//		USART_SendData(USART1, dat);
		if(dat == '*')	
		{
		//R123G123B213*
//			printf("%s %d", rx_buf, rx_len);
			ParseCmd(rx_buf, rx_len);
			memset(rx_buf, 0, rx_len);
			rx_len = 0;
		}
		else
		{
			rx_buf[rx_len++] = dat;
		}	
	}
}


void ParseCmd(char *rx_buf, size_t len)
{
    uint8_t R_Num, G_Num, B_Num;    
    char R_Str[20], G_Str[20], B_Str[20];
    char *R, *G, *B;

    len = strlen(rx_buf);
    R = strstr(rx_buf, "R");
    G = strstr(rx_buf, "G");
    B = strstr(rx_buf, "B");

    strncpy(R_Str, R+1, G-R-1);
    R_Str[G-R-1] = '\0';
    strncpy(G_Str, G+1, B-G-1);
    G_Str[B-G-1] = '\0';
    strncpy(B_Str, B+1, len - (B - rx_buf)-1);
    B_Str[len - (B - rx_buf)-1] = '\0';
//    printf("R:-%s-,\r\nG:-%s-,\r\nB:-%s-,\r\n", R_Str, G_Str, B_Str);

    R_Num = atoi(R_Str);
    G_Num = atoi(G_Str);
    B_Num = atoi(B_Str);
//    printf("%d %d %d", R_Num, G_Num, B_Num);

	SetDutyCycle(R_LED, R_Num);
	SetDutyCycle(G_LED, G_Num);
	SetDutyCycle(B_LED, B_Num);
}

