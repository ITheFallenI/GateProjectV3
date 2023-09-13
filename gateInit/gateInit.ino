#include "Timer.h"
#include "RF_keys.h"
#include "Pins.h"
#include "Gates.h"
#include "Commands.h"

Pins pins;
Gates gates;
Commands commands;

void setup() {
  
  Serial.begin(9600);
  delay(100);
  Serial.flush();
  Serial.println("");
  Serial.println("---------------------------------");
  Serial.println("Setup init.");
  pins.Setup();
  Serial.println("---------------------------------");
  //OpenGates(8000, 16600, 16100, 2000);
  //OpenTimer.reset();
}

void loop() {
 
  commands.CommandLoop();
  gates.InputLoop();

}
