#include <Arduino.h>
#include <Wire.h>
#include "configuration.h"
#include "graphics/Screen.h"

graphics::Screen *screen;

void setup() {
Wire.begin(I2C_SDA, I2C_SCL);
screen = new graphics::Screen(SSD1306_ADDRESS);

#ifdef RESET_OLED
    pinMode(RESET_OLED, OUTPUT);
    digitalWrite(RESET_OLED, HIGH);
#endif

#ifdef LED_PIN
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH); // turn on for now
#endif

  screen->setup();

}

void loop() {
  // put your main code here, to run repeatedly:
  screen->draw();
}