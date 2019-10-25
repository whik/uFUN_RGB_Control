#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "rgb.h"

int main(void)
{
    delay_init();	    	 //延时函数初始化
    UART1_Config(115200);	 	//串口初始化为9600
	RGB_LED_Init();
	
	SetDutyCycle(R_LED, 0);
	SetDutyCycle(G_LED, 0);
	SetDutyCycle(B_LED, 0);
	
	while(1)
    {
	}
}

