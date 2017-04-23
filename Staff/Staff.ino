//Cosplay staff
//Currently this code is designed to make the lights change colour every button press
//review lines 17,36, 54, 61,68


#include "FastLED.h"

#define NUM_LEDS 54 //not sure about this notation
#define DATA_PIN 5
#define BRIGHTNESS  255

CRGB leds[NUM_LEDS];

//used to this style personally, I think in arduino int and define are similar
int buttonA = 2; //Adjust as needed
int ledPin = 13; //debugging ----------------------
int readPin = 0;
CRGB CurrentColour;
CRGB ColourRed;
CRGB ColourGreen;


void setup() {

     delay(500); 
     
     FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
     ColourRed = CRGB(255,10,10);
     ColourGreen = CRGB(30,205,25);
     CurrentColour = ColourRed;

     pinMode(buttonA, INPUT);
     pinMode(ledPin,OUTPUT); //debugging --------------------------------
} //End SetUp



void loop() {  

//loops make the world go round
  for(int i=0;i<=NUM_LEDS;i++){
    leds[i] = CurrentColour; 
  }
  
  FastLED.show();

  readPin = digitalRead(buttonA);
  
  if(readPin == HIGH){
  digitalWrite(ledPin, HIGH); //debugging --------------------
    if(CurrentColour == ColourGreen){
      CurrentColour = ColourRed;
    }
    else{
      CurrentColour = ColourGreen;
    }
  }
  delay(100);
  digitalWrite(ledPin,LOW);
}//End Loop

