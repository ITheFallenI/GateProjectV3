#ifndef COMMANDS_H
#define COMMANDS_H
#include <Arduino.h>
#include "Gates.h"

class Commands{
  private:
    Gates gates;
    String command;
    void ProcessCommand(String m_Command);

  public:
    void CommandLoop();
};

#endif