/*Youtube link :: 

************************************Next World******************************************
        *************************Gokarna Baskota*******************************    

            ############### SOIL MONITORING SYSTEM #####################
*/

int sensorPin = A4;         // Sensor Pin

int sensorVal = 0;          // initialize sensor Reading value

int percentVal;             // store percentage sensor value

int buzzPin = 8;            // buzzer pin

void setup()
{
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);

}

void loop()
{

  sensorVal = analogRead(sensorPin);   // read the Sensor value
  
  // calculate the percentage
                                                //map(sensorVal,lowestSensorValue,highestSensorValue,lowermappedValue,uppermappedValue);
  percentVal = map(sensorVal, 1023, 0, 0, 100); // convert the sensor reading into percentage

  // Display Moisture percentage
  Serial.print("Moisture Percent:   ");
  Serial.print(percentVal);
  Serial.println(" % ");

  // check the condition of soil
  if (percentVal >= 63)
  {
    Serial.println("Totally wet !!!");
    Serial.println("********************************************************************************");

    // Give the signal to user
    digitalWrite(buzzPin, HIGH);
    delay(250);
    digitalWrite(buzzPin, LOW);
    
  }

  else if (percentVal >= 36 && percentVal < 63)
  {
    Serial.println("Partially wet !!!");
    Serial.println("################################################################################");
  }

  else if (percentVal < 36)
  {
    Serial.println("Dry dry dry !!!");
    Serial.println("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
  }

  Serial.println(" ");
  Serial.println(" ");


}
