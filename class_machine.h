//Petter Abrahamsen s169962

#ifndef CLASS_MACHINE_H
#define CLASS_MACHINE_H

#include "class_boardGame.h"

namespace TicTac
{
  class machine
  {
    char machineChar;
    int boardSize;
  public:
    machine(char c, int size);
    void move(boardGame *board);
  };
}

#endif
