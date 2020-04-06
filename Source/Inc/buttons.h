
#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "stm32f4xx_hal.h"
#include <stdbool.h>

typedef enum
{
	ButtenDowen,
	ButtenUp

}buttnState;

typedef struct
{
	buttnState leftButton;
	buttnState rightButton;
	buttnState topButton;
	buttnState buttomButton;
	buttnState centreButton;
}Joystick;



bool getJoystickState(Joystick *outPtr);

#ifdef __cplusplus
}
#endif

#endif /* INC_BUTTONS_H_ */
