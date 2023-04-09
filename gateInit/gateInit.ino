#include "Timer.h"
#include "RF_keys.h"
#include "Pins.h"
#include "Gates.h"

Pins pins;
Gates gates;
RF_keys rf_keys;

void setup() {
  
  Serial.begin(9600);
  delay(100);
  Serial.println("---------------------------------");
  Serial.println("Setup init.");
  pins.Setup();
  Serial.println("---------------------------------");
  //OpenGates(8000, 16600, 16100, 2000);
  //OpenTimer.reset();
}

void loop() {
  
  if(rf_keys.getKeyDown(rf_keys.KEY_C())){
      Serial.println(rf_keys.ReturnKeyPressCount());
      if(gates.gateState == GateClosed){
        gates.OpenGates(8000, 16600, 16100, 2000);
      }
  }

  if(rf_keys.getKeyDown(pins.STOPBUTTON())){
      gates.EmergencyStop();
  }


}
