#include <NeoPixelBus.h>
#include "Variables.h"

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> ring(PixelCount, PixelPin);

void setup()
{
    display.init();
    display.setRotation(1);
    display.setTextColor(GxEPD_BLACK);
    display.setFont(&FreeMonoBold18pt7b);
    ring.Begin();
    ring.Show();
    Serial.begin(115200);
    Button1_total = smoothing*touchRead(T2);
    message(""," WARMING UP","");
    display.update();
    //message("","   READY!","");
    message("   GEOFF","    -O-","   METER");
}


void loop()
{
  if (button1_capture()==1){
    Serial.println("button pressed");
    if (millis()>next_capture){
      
      Drunkness = 0.01*capture();
      if (ring.CanShow()){neoPortion(Drunkness,0);}
      checkSave();
    }else{
      while(millis()<next_capture){
          message(" BUTTON"," PRESSED"," TOO SOON");
          delay(1000);
      }
    }
  idle();
  }
  sensor_smoothing();
  Serial.print("sensor pin ");
  Serial.println(smooth[49]);
  if (ring.CanShow()){neoPortion(Louis,1);}
}


