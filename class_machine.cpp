//Petter Abrahamsen s169962

#include "class_boardGame.h"
#include "class_machine.h"
#include <stdlib.h>
#include <time.h>  
#include <iostream>

using namespace TicTac;

machine::machine(char c, int size)
{
  machine::machineChar = c;
  machine::boardSize = size;
}

void machine::move(boardGame *board)
{
  srand(time(NULL));
  int x, y;
  do{
    x = rand()%boardSize + 1;
    y = rand()%boardSize + 1;
  
  }while(!board->move(x, y, machineChar));
  board->print();
}
