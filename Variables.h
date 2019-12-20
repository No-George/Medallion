//Ring Jazz
const uint16_t PixelCount = 32; // this example assumes 4 pixels, making it smaller will cause a failure
const uint8_t PixelPin = 19;  // make sure to set this to the correct pin, ignored for Esp8266

int colorSaturation = 10;
int Brightness = 50;
int Pulse = 1600; //Half the time between pulsations

RgbColor red(colorSaturation, 0, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor white(colorSaturation); 
RgbColor black(0);

//Button Jazz
long Button1_total = 0;
int smoothing = 1000;
const int debounce = 5;
int Button1[debounce];

//Alcohol
float Drunkness = 0;
float Louis = 0;
long reading = 0;
int rawreading = 0;
const int sensorPin = 15;
long next_capture = 0;
int min_interval = 30000;
int sensor_max = 1500;
int sensor_min = 1200;
const int smooth_count = 50;
int smooth[smooth_count];

//ePaper stuff
#include <GxEPD.h>
#include <GxGDE0213B1/GxGDE0213B1.cpp>      // 2.13" b/w
#include GxEPD_BitmapExamples
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>
GxIO_Class io(SPI, SS, 17, 16); // arbitrary selection of 17, 16
GxEPD_Class display(io, 16, 4); // arbitrary selection of (16), 4
