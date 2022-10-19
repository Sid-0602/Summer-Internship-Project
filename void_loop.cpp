//looping conditon for checking status of system.
void loop()
{
 
  digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
    //Ultrasonic sensor
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);

    duration = pulseIn(echoPin1, HIGH);
    dist1 = Speed*duration/2;

    if(dist1<200)
    {
      digitalWrite(led1,HIGH);
    }
    else
    {
      digitalWrite(led1, LOW);
    }

    digitalWrite(trigPin2, LOW);
    delayMicroseconds(200);

    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(300);
    digitalWrite(trigPin2, LOW);

    duration = pulseIn(echoPin2, HIGH);
    dist2 = Speed*duration/2;

    if(dist2<10)
    {
      digitalWrite(led2,HIGH);
    }
    else
    {
      digitalWrite(led2, LOW);
    }
   
    //IR Sensor Code
    int statusSensor = digitalRead (IRSensor);
 
    if(statusSensor == 1)
    {
        digitalWrite(led3,HIGH);
        delay(100);               //Setting the delay time, 1 sec
        digitalWrite(led3,LOW);  
        delay(100);               //Setting the delay time, 1 sec
    }
 
    else
    {
      digitalWrite(led3,LOW);
    }

  //Water Sensor
  waterVal= analogRead(waterSens);

  if(waterVal<=600)
  {
   
        digitalWrite(led4,HIGH);
        delay(100);               //Setting the delay time, 1 sec
        digitalWrite(led4,LOW);  
        delay(100);               //Setting the delay time, 1 sec
  }
  else
  {
        digitalWrite(led4,LOW);
  }

  //PIR Sensor
  val = digitalRead(PIRsensor);   // read sensor value
  if (val == HIGH)
  {           // check if the sensor is HIGH
    digitalWrite(led5, HIGH);   // turn LED5 ON
    delay(500);                // delay 100 milliseconds
   
    if (state == LOW) {
      Serial.println("Motion detected!");
      state = HIGH;       // update variable state to HIGH
    }
  }
  else {
      digitalWrite(led5, LOW); // turn LED5 OFF
      delay(500);             // delay 200 milliseconds
     
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }  
 
} 
