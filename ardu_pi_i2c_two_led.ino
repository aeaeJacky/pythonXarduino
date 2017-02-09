#include <Adafruit_NeoPixel.h>         // Include Adafruit NeoPixel library
#define PIN            13               // LED on digital pin 13
#define NUMLEDS        2               // Use total of 2 LED

Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

int wait = 5;                         // Standard wait delay of 5 milliseconds 

int SLAVE_ADDRESS = 33;
//int ledPin = 11;
int analogPin = A0;

boolean ledOn = false;



void setup(){
  Serial.begin(9600);
  Serial.println("hw");  
  leds.begin();                       // Initialize 'leds' object

    //Make sure LED is off to demonstrate start of sketch
    for (int num_led = 0; num_led < NUMLEDS; num_led++){
      leds.setPixelColor(num_led, leds.Color(0, 0, 0));  // Turn off LED
    }
    leds.show();                        // Set new value
    delay(500);
  
    //pinMode(ledPin, OUTPUT);
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(processMessage);
    //Wire.onRequest(sendAnalogReading);

}

void loop(){
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}

void processMessage(int n)
{
  Serial.println("helloworld");
  int receiveByte = 0; //set index to 0
  char command[4]; // expect 3 char + 1 end byte
  String LED0_value = "";
  String LED1_value = "";
  
  while (Wire.available())
  {
    command[receiveByte] = Wire.read();
    receiveByte++;
  }
  
  LED0_value = String(command[1]) + String(command[2]) + String(command[3]);
  LED1_value = String(command[1]) + String(command[2]) + String(command[3]);
  
  Serial.println("LED0_value:");
  Serial.println(LED0_value);
  Serial.println("LED1_value:");
  Serial.println(LED1_value);
  
  int LED0_realvalue = LED0_value.toInt();
  int LED1_realvalue = LED1_value.toInt();
  
  if (String(command[0]) == "F") {
  leds.setPixelColor(0, leds.Color(LED0_realvalue, 0, 0));  // Color mix for LED
  }
  if (String(command[0]) == "S") {
  leds.setPixelColor(1, leds.Color(0, LED1_realvalue, 0));  // Color mix for LED
  }
  leds.show();                        // Set the LED
}

