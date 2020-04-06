
#include "debug.h"

extern UART_HandleTypeDef huart1;

void UARTprint(const char *str, va_list argp)
{
    char string[200];
    if(0 < vsprintf(string,str,argp))
    {
        HAL_UART_Transmit(&huart1, (uint8_t*)string, strlen(string), 0xffffff);
    }
}

void DebugPrintf(const char *str, ...)
{
    va_list argp;
    va_start(argp, str);
    UARTprint(str, argp);
    va_end(argp);
}
