/* Measures the speed of a ping pong ball using the distance
   between two photoresistors and millis() */

int sensor1Value;
int sensor2Value;
double startTime;
double endTime;
double time;
double timeInSeconds;
double distance;
double speed;
boolean endFlag;

void setup() {
  Serial.begin(9600);
  distance = 6;
  endFlag = false;
}

void loop() {
  sensor1Value = analogRead(A1);
  sensor2Value = analogRead(A0);

  //Serial.println(sensor1Value);       // Used for determining photoresistor thresholds
  //Serial.println(sensor2Value);

  if(sensor1Value > 800){               // If first photoresistor passes threshold, save startTime.
    endFlag = false;
    startTime = millis();
  }

  if(sensor2Value < 830 && endFlag == false){       // If second photoresistor passes threshold, save endTime.
   endTime = millis();
    time = endTime - startTime;
    timeInSeconds = time/1000;
    speed = distance/timeInSeconds;
    Serial.print("Speed: ");
    Serial.print(speed);
    Serial.print(" cm/s");
    Serial.println(" ");
    endFlag = true;
  }
}
