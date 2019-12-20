void neoPortion(float Geoffreys, bool flag){
  ring.ClearTo(black);
  Geoffreys = 100* Geoffreys;
  
  //Calculate pulse status 
  if (flag==1){
    int timer = (millis() % (Pulse*2));
    Brightness = 10+90*(abs(timer-Pulse))/Pulse;
  }else{
    Brightness = 100;
  } 

  //Calculate transitions
  int GeoffTransition = map ((constrain(Geoffreys,0,100)), 0,100,5,32);
  //int GeoffTransition = _min(Geoffreys,100);
    //limit to 1 Geoffrey
  int RupertTransition = map ((constrain(Geoffreys,100,200)),100,200,5,32);
    //limit to 1-2 Geoffreys

  //Louis Colour
  for (int i = (GeoffTransition); i<32; i++){
  ring.SetPixelColor(i, RgbColor(0,Brightness,0));
  }
  //GeoffColour
  for (int i = 5; i<=GeoffTransition; i++){
  ring.SetPixelColor(i, RgbColor(0,0,Brightness));
  }
  //Flashing Jazz
  if (((millis() %600) >  300)||(flag==0)){
      //Marker
    ring.SetPixelColor((GeoffTransition), red); 
       //RupertColour
    for (int i = 5; i<=RupertTransition; i++){
      ring.SetPixelColor(i, RgbColor(Brightness,0,0));
    }
  }
  
  //remove requirement for 0% if statement
  ring.SetPixelColor(5, black); 
  ring.Show();
}


void progressBar(int percent, int r,int g, int b){
  ring.ClearTo(black);
  int endPixel = map(percent, 0, 100, 3, 35);
  for (int i = 3; i<=endPixel; i++){
      ring.SetPixelColor((i%32), RgbColor(r,g,b));
      } 
  ring.Show();
}

