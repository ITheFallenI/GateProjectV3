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
      Serial.println("Command OpenGate");
      gates.OpenGates(8000, 16600, 16100, 2000);
  }else if(t_Command.equals("closegate")){   
      Serial.println("Command CloseGate");
      gates.CloseGates(8000, 16600, 16100, 2000);
  }else if(t_Command.equals("gatestate")){
      Serial.println(gates.ReturnGateState());
  }else{
      Serial.println("Invalid command");
  }
}
