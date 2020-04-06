#include "buttons.h"

#define JOYSTIC_PORT ((GPIO_TypeDef *)  GPIOG)

#define A_PIN		GPIO_IDR_ID2
#define B_PIN 		GPIO_IDR_ID3
#define C_PIN 		GPIO_IDR_ID9
#define D_PIN 		GPIO_IDR_ID10
#define PRES_PIN 	GPIO_IDR_ID13


static Joystick oldJoystick = {0};


void readingJoystickState(Joystick *outPtr);

bool getJoystickState(Joystick *outPtr)
{
	bool currentChange = false;

	readingJoystickState(outPtr);
	if(	(outPtr->topButton 		!= oldJoystick.topButton)|
		(outPtr->rightButton	!= oldJoystick.rightButton)|
		(outPtr->buttomButton 	!= oldJoystick.buttomButton)|
		(outPtr->leftButton 	!= oldJoystick.leftButton)|
		(outPtr->centreButton	!= oldJoystick.centreButton))
		currentChange = true;

	oldJoystick = *outPtr;

	return currentChange;
}

void readingJoystickState(Joystick *outPtr)
{
	outPtr->topButton= 		JOYSTIC_PORT->IDR&A_PIN ? ButtenDowen: ButtenUp;
	outPtr->rightButton = 	JOYSTIC_PORT->IDR&B_PIN ? ButtenDowen: ButtenUp;
	outPtr->leftButton = 	JOYSTIC_PORT->IDR&C_PIN ? ButtenDowen: ButtenUp;
	outPtr->buttomButton = 	JOYSTIC_PORT->IDR&D_PIN ? ButtenDowen: ButtenUp;
	outPtr->centreButton = 	JOYSTIC_PORT->IDR&PRES_PIN ? ButtenDowen: ButtenUp;
}
