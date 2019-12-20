int readSensor(){
  int samples = 10;
  rawreading = 0;
  for(int i = 0; i<samples; i++){
    rawreading += analogRead(sensorPin);
  }
  rawreading = rawreading/samples;
  reading = map(constrain(rawreading,sensor_min,sensor_max),sensor_min,sensor_max,0,200);
  return reading;
}


int capture(){
  reading = 0;
  Serial.println("blow me");
  message("","  BLOW ME","");
  for (int i =0; i<100; i++){
    int currentReading = readSensor();
    if (currentReading>reading){
      reading = currentReading;
      }
    if (ring.CanShow()){progressBar(i, 0,0, 50);}
    delay(50);
  }
  Serial.println("Calculating");
  message("","CALCULATING","");
  for (int i =0; i<100; i++){
    int currentReading = readSensor();
    if (currentReading>reading){
      reading = currentReading;
      }
    if (ring.CanShow()){progressBar(i, 0,50, 0);}
    delay(50);
  }
  next_capture = millis()+min_interval;
  Serial.print("reading = "); Serial.println(reading);
  return reading;  
}

void sensor_smoothing(){
  smooth[49]=analogRead(sensorPin);
  sensor_min = smooth[49];
  for (int i = 0; i<(smooth_count-1); i++){
    smooth[i] = smooth[i+1]; 
    sensor_min+=smooth[i+1];   
  }
  sensor_min = sensor_min/smooth_count;
  sensor_max = sensor_min + 200;
}

