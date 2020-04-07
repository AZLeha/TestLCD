/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN1VIEWBASE_HPP
#define SCREEN1VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/containers/Slider.hpp>
#include <touchgfx/containers/clock/AnalogClock.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class Screen1ViewBase : public touchgfx::View<Screen1Presenter>
{
public:
    Screen1ViewBase();
    virtual ~Screen1ViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void sliderChanged(int value)
    {
        // Override and implement this function in Screen1
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box box1;
    touchgfx::SwipeContainer swipeContainer1;
    touchgfx::Container swipeContainer1Page1;
    touchgfx::Image image1;
    touchgfx::Container swipeContainer1Page2;
    touchgfx::Box box_Right;
    touchgfx::Box box_Buttom;
    touchgfx::Box box_Top;
    touchgfx::Box box_Left;
    touchgfx::Slider slider1;
    touchgfx::Container swipeContainer1Page3;
    touchgfx::AnalogClock analogClock1;
    touchgfx::TextArea textArea2;
    touchgfx::TextArea textArea1;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen1ViewBase, const touchgfx::Slider&, int> sliderValueChangedCallback;

    /*
     * Callback Handler Declarations
     */
    void sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value);

};

#endif // SCREEN1VIEWBASE_HPP
