// Generated by imageconverter. Please, do not edit!

#ifndef BITMAPDATABASE_HPP
#define BITMAPDATABASE_HPP

#include <touchgfx/hal/Types.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <touchgfx/Bitmap.hpp>

const uint16_t BITMAP_BLUE_CLOCKS_BACKGROUNDS_CLOCK_STANDARD_BACKGROUND_ID = 0;
const uint16_t BITMAP_BLUE_CLOCKS_HANDS_CLOCK_STANDARD_HOUR_HAND_ID = 1;
const uint16_t BITMAP_BLUE_CLOCKS_HANDS_CLOCK_STANDARD_MINUTE_HAND_ID = 2;
const uint16_t BITMAP_BLUE_CLOCKS_HANDS_CLOCK_STANDARD_SECOND_HAND_ID = 3;
const uint16_t BITMAP_BLUE_PAGEINDICATOR_DOT_INDICATOR_SMALL_HIGHLIGHT_ID = 4;
const uint16_t BITMAP_BLUE_PAGEINDICATOR_DOT_INDICATOR_SMALL_NORMAL_ID = 5;
const uint16_t BITMAP_BLUE_SLIDER_VERTICAL_MEDIUM_INDICATORS_SLIDER3_VERTICAL_ROUND_NOB_ID = 6;
const uint16_t BITMAP_BLUE_SLIDER_VERTICAL_MEDIUM_SLIDER3_VERTICAL_ROUND_BACK_ID = 7;
const uint16_t BITMAP_BLUE_SLIDER_VERTICAL_MEDIUM_SLIDER3_VERTICAL_ROUND_FILL_ID = 8;

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance();
uint16_t getInstanceSize();
}

#endif
