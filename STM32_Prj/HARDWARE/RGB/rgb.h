#ifndef __RGB_H
#define __RGB_H
#include "sys.h"

typedef enum LEDtype
{
    R_LED = 1,
    G_LED = 2,
    B_LED = 3
}LEDtype;

void RGB_LED_Init(void);

void SetDutyCycle(LEDtype LEDn, int dty);

#endif
