

// set pin numbers:
const int ledPin =  13;      // the number of the LED pin

long previousMillis = 0;

long interval = 1000 - 1; //wait milliseconds 1000

int hours, minutes, seconds = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Damn!"); //Prompt User for Input
    while(Serial.available()==0) { // Wait for User to Input Data  
  }
  hours=Serial.parseInt();  //Read the data the user has input
  Serial.println("Damn Twice!"); //Prompt User for Input
    while(Serial.available()==0) { // Wait for User to Input Data  
  }
  minutes=Serial.parseInt();  //Read the data the user has input
  Serial.println("Damn Third!"); //Prompt User for Input
    while(Serial.available()==0) { // Wait for User to Input Data  
  }
  seconds=Serial.parseInt();  //Read the data the user has input
}

void loop() {
     
  
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis > interval) {
     previousMillis = currentMillis;

      if (seconds < 60) {
        seconds++;
        if (seconds == 60) {
          seconds = 0;
          minutes++; 
          if (minutes == 60) {
            minutes = 0;
            hours++;
            if (hours == 24) {
              hours = 0;
            }
          }
        }
      }

    Serial.print(hours);
    Serial.print(":");
    Serial.print(minutes);
    Serial.print(":");
    Serial.println(seconds);
    //Serial.print(":");
    //Serial.println(currentMillis);
    }
}
