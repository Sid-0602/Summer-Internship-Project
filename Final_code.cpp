//The complete code for SIP project:

// definition of digital pins as pin to control the LED
int led1 = 13; // output of Ultrasonic 01
int led2 = 12; // output of Ultrasonic 02
int led3 = 11; // output of IR Sensor
int led4 = 10;
  //output of Water Sensor
    int led5 = 7;
  //output of PIR

    // connect Ultrasonic sensor to arduino pins
    int trigPin1 = 1;
int echoPin1 = 2;
int trigPin2 = 3;
int echoPin2 = 4;
float Speed = 0.0343; // sound speed in cm/us
long duration, dist1, dist2;

// connect ir sensor to arduino pin 9
int IRSensor = 9;

// connects Water Sensor to aurdino pins

int waterSens = A5;
int waterVal;

// connects PIR sensor
int PIRsensor = 5;
              // the pin that the PIR sensor is atteched to
    int state = LOW;
            // by default, no motion detected
    int val = 0;
                // variable to store the sensor status (value)
             

    void
    setup()
{
      Serial.begin(9600);
      pinMode(trigPin1, OUTPUT);
      pinMode(echoPin1, INPUT); // Ultrasonic1 sensor pin INPUT
      pinMode(trigPin2, OUTPUT);
      pinMode(echoPin2, INPUT); // Ultrasonic2 sensor pin INPUT

      pinMode(IRSensor, INPUT); // IR sensor pin INPUT

      //led Output
  pinMode(led1, OUTPUT);
     
  pinMode(led2, OUTPUT);
     
  pinMode(led3, OUTPUT);
     
  pinMode(led4, OUTPUT);
     
  pinMode(led5, OUTPUT);

     

  pinMode(waterSens, INPUT); // Water sensor Input

      pinMode(PIRsensor, INPUT);
        // initialize PIRsensor as an input
 
}

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
        dist1 = Speed * duration / 2;

        if (dist1 < 200)
   
    {
              digitalWrite(led1, HIGH);
           
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
        dist2 = Speed * duration / 2;

        if (dist2 < 10)
   
    {
              digitalWrite(led2, HIGH);
           
    }
        else    
    {
              digitalWrite(led2, LOW);
           
    }
       
    //IR Sensor Code
    int statusSensor = digitalRead(IRSensor);
     
    if (statusSensor == 1)
   
    {
                digitalWrite(led3, HIGH);
                delay(100);
                      //Setting the delay time, 1 sec
        digitalWrite(led3, LOW);
         
        delay(100);
                      //Setting the delay time, 1 sec
   
    }
     
    else    
    {
              digitalWrite(led3, LOW);
           
    }

      //Water Sensor
  waterVal = analogRead(waterSens);

      if (waterVal <= 600)
 
    {
           
        digitalWrite(led4, HIGH);
                delay(100);
                      //Setting the delay time, 1 sec
        digitalWrite(led4, LOW);
         
        delay(100);
                      //Setting the delay time, 1 sec
 
    }
      else  
    {
                digitalWrite(led4, LOW);
         
    }

      //PIR Sensor
  val = digitalRead(PIRsensor);
      // read sensor value
  if (val == HIGH)
 
    {
                  // check if the sensor is HIGH
    digitalWrite(led5, HIGH);
          // turn LED5 ON
    delay(500);
                        // delay 100 milliseconds
   
    if (state == LOW)
        {
                  Serial.println("Motion detected!");
                  state = HIGH;
                  // update variable state to HIGH
   
        }
         
    }
      else
    {
              digitalWrite(led5, LOW); // turn LED5 OFF
              delay(500);
                    // delay 200 milliseconds
     
      if (state == HIGH)
        {
                    Serial.println("Motion stopped!");
                    state = LOW;
                  // update variable state to LOW
   
        }
         
    }
     
 
}
 
