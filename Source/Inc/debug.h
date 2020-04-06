#ifndef INC_DEBUG_H_
#define INC_DEBUG_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>


void DebugPrintf(const char *str, ...) ;


#ifdef __cplusplus
}
#endif

#endif /* INC_DEBUG_H_ */
