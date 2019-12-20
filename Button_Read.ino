int button1_capture(){
  for (int i=0; i<(debounce-1);i++){
    Button1[i]=Button1[i+1];
  }
  Button1[4] = (touchRead(T2));
  long Button1_smooth = Button1_total/1000;
  int current = MaxArray(Button1);
  if (current < (0.8*Button1_smooth)){
    return 1;
  }else{
    Button1_total = Button1_total -Button1_smooth +Button1[0];
  }
  return 0;
}

int MaxArray(int MaxMe[]){
  int mxm = MaxMe[0];
  int mnm = MaxMe[0];
  for (int i=0; i<debounce; i++) {
    if (MaxMe[i]>mxm) {
      mxm = MaxMe[i];
    }
  }
return mxm;
}

void checkSave(){
  Serial.println("want to save?");
  save_me();
  long waitTime = millis()+5000;
  while (millis()<waitTime){
    //ePaper save? with timer
    if (button1_capture()==1){
      waitTime=millis();
      Serial.println("saving");
      message("","SAVING...","");
      Louis = Drunkness;
    }
  }


  //debounce
  while (button1_capture()==1){
    delay(50);
  }
  delay(200);
}

