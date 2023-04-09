#include "Commands.h"

void Commands::CommandLoop(){
    if(Serial.available()){     
        command = Serial.readStringUntil('\n');
        Serial.println("You sent command {" + command + "}");
        ProcessCommand(command);
    }
}

void Commands::ProcessCommand(String m_Command){
  String t_Command = m_Command;
  t_Command.toLowerCase();

  if(t_Command.equals("stop") || t_Command.equals("emergencystop")){
      gates.EmergencyStop();
  }else if(t_Command.equals("opengate")){
      //gates.OpenGates(unsigned int m_delayBetweenOpening, unsigned int m_leftGateOpeningTime, unsigned int m_rightGateOpeningTime, unsigned int m_delayForLock);
  }else if(t_Command.equals("closegate")){
    
  }else{
      Serial.println("Invalid command");
  }
}
