void message(const char P1[],const char P2[],const char P3[]){
  display.fillScreen(GxEPD_WHITE);
  display.setCursor(7, 35);
  //display.println();
  display.print(P1);
  display.setCursor(7, 65);
  display.print(P2);
  display.setCursor(7, 95);
  display.print(P3);
  display.updateWindow(0, 0, 250, 122, true);
}

void idle(){
  display.fillScreen(GxEPD_WHITE);
  
    if (Louis<1.97){
      display.setFont(&FreeMonoBold24pt7b);
      display.setCursor(80, 50);
      display.print(String(Louis,1));
      display.setFont(&FreeMonoBold18pt7b);
      display.setCursor(35, 90);
      display.print("GEOFFREYS");
    } else {
      display.setFont(&FreeMonoBold24pt7b);
      display.setCursor(7, 45);
      display.print("  FULL");
      display.setCursor(7, 85);
      display.print(" RUPERT!");
      display.setFont(&FreeMonoBold18pt7b);
    }
  display.update();
}

void save_me(){
  display.fillScreen(GxEPD_WHITE);
  display.setCursor(85, 35);
  display.print(String(Drunkness,1));
  display.setCursor(7, 65);
  display.println(" GEOFFREYS");
  display.setCursor(7, 95);
  display.println("   SAVE?");
  display.updateWindow(0, 0, 250, 122, true);
}
