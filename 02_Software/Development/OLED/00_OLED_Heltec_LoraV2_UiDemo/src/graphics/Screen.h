#pragma once

#include <SSD1306Wire.h>
#include <OLEDDisplayUi.h>

namespace graphics
{
    class Screen 
    {
        public:
            Screen(uint8_t address, int sda = -1, int scl = -1);

            void setup();
            void draw();

        private:
            SSD1306Wire dispdev;
            OLEDDisplayUi ui;

    };

} // namespace graphics

