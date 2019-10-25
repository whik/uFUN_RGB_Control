#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 

void UART1_Config(u32 bound);
void ParseCmd(char *rx_buf, size_t len);


#endif


