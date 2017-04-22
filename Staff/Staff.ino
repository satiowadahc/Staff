//Cosplay staff
//Currently this code is designed to make the lights change colour every button press
//review lines 15, 24


#include "FastLED.h"

#define NUM_LEDS 54 //not sure about this notation
#define DATA_PIN 5
#define BRIGHTNESS  255

CRGB leds[NUM_LEDS];

//used to this style personally
int buttonA = 13; //Adjust as needed
int readPin = 0;
CRGB PriorityColour;
CRGB ColourRed;
CRGB ColourGreen;


void setup() {

     delay(2000); //Why so high, I think this is unnessecary
     FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
     ColourRed = CRGB(255,10,10);
     ColourGreen = CRGB(30,205,25);
     PriorityColour = ColourRed;

} //End SetUp



void loop() {  

//loops make the world go round
  for(int i=0;i<=NUM_LEDS;i++){
    leds[i] = ColourRed; 
  }
  
  FastLED.show();

  readPin = digitalRead(buttonA);
  
  if(readPin == HIGH){

    if(PriorityColour == ColourGreen){
      PriorityColour = ColourRed;
    }
    else if(PriorityColour == ColourRed){
      PriorityColour = ColourGreen;
    }
    else{
      PriorityColour = CRGB::White; //Problem
    }
  
  }//End Debounce 
  delay(1000);//This might be high,maybe 100

}//End Loop

