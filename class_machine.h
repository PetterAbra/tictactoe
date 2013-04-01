//Petter Abrahamsen s169962

#ifndef CLASS_MACHINE_H
#define CLASS_MACHINE_H

#include "class_boardGame.h"

namespace TicTac
{
  class machine //creates the class machine with the char and size of the board
  {
    char machineChar;
    int boardSize;
  public: //public functions
    machine(char c, int size);
    void move(boardGame *board);
  };
}

#endif
