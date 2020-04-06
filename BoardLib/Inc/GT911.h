#ifndef __GT911_H_
#define __GT911_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"

#define GT911_MAX_WIDTH		(uint16_t)800    	//Touchscreen pad max width
#define GT911_MAX_HEIGHT	(uint16_t)480		//Touchscreen pad max height

#define CT_CMD_WR	(uint8_t) 0XBA
#define CT_CMD_RD   (uint8_t) 0XBB

#define CT_MAX_TOUCH (uint8_t) 5

#define GT911_COMMAND_REG   		(uint16_t)0x8040
#define GT911_CONFIG_REG			(uint16_t)0x8047
#define GT911_PRODUCT_ID_REG 		(uint16_t)0x8140
#define GT911_FIRMWARE_VERSION_REG  (uint16_t)0x8144
#define GT911_READ_XY_REG 			(uint16_t)0x814E

#define GT911_RST_CLK()	__GPIOD_CLK_ENABLE()
#define GT911_RST_PORT	GPIOB
#define GT911_RST_PIN	GPIO_PIN_4

#define GT911_INT_CLK()		__GPIOD_CLK_ENABLE()
//#define GT911_INT_PORT	GPIOD
//#define GT911_INT_PIN				GPIO_PIN_7
#define GT911_INT_PORT		GPIOH
#define GT911_INT_PIN		GPIO_PIN_4

typedef struct
{
	uint8_t Touch;
	uint8_t TouchpointFlag;
	uint8_t TouchCount;
 
	uint8_t Touchkeytrackid[CT_MAX_TOUCH];
	uint16_t X[CT_MAX_TOUCH];
	uint16_t Y[CT_MAX_TOUCH];
	uint16_t S[CT_MAX_TOUCH];
}GT911_Dev;

GT911_Dev getTouch(void);

void GT911_Reset_Sequence();

	
#ifdef __cplusplus
}
#endif

#endif /*__GT911_H_*/
