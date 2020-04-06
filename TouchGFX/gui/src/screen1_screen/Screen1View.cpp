#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp>

#include "buttons.h"
#include "cmsis_os.h"
extern "C" {
	extern QueueHandle_t xJosticQueue;
	extern QueueHandle_t xPWMQueue;
}

#define DEFAULT_BOX_COLOR 	touchgfx::Color::getColorFrom24BitRGB(255, 255, 255)
#define SET_BOX_COLOR 		touchgfx::Color::getColorFrom24BitRGB(213, 35, 0)
Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
void Screen1View::sliderChanged(int value)
{
	xQueueSend(xPWMQueue,&value,0);
}


void Screen1View::update(void)
{

	updateJostic();
}


void Screen1View::updateJostic(void)
{
	Joystick currentState;

	if(xQueueReceive(xJosticQueue,&currentState,0) == pdPASS)
	{
		(currentState.topButton 	== 		ButtenUp) ? box_Top.setColor(SET_BOX_COLOR) : 	box_Top.setColor(DEFAULT_BOX_COLOR);
		(currentState.rightButton == 	ButtenUp) ? box_Right.setColor(SET_BOX_COLOR) : 	box_Right.setColor(DEFAULT_BOX_COLOR);
		(currentState.buttomButton == 	ButtenUp) ? box_Buttom.setColor(SET_BOX_COLOR) : box_Buttom.setColor(DEFAULT_BOX_COLOR);
		(currentState.leftButton == 		ButtenUp) ? box_Left.setColor(SET_BOX_COLOR) : 	box_Left.setColor(DEFAULT_BOX_COLOR);
		box_Top.invalidate();
		box_Right.invalidate();
		box_Buttom.invalidate();
		box_Left.invalidate();

	}

}
