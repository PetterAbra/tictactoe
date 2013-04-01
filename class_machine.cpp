//Petter Abrahamsen s169962

#include "class_boardGame.h"
#include "class_machine.h"
#include <stdlib.h>
#include <time.h>  
#include <iostream>

using namespace TicTac;

machine::machine(char c, int size) //constructor
{
  machine::machineChar = c; //sets the size and the char 
  machine::boardSize = size;
} //end of constructor

void machine::move(boardGame *board) //does a random move
{
  srand(time(NULL)); //the way to choose the right place to put was too complex with the size N*N
  int x, y;
  do{
    x = rand()%boardSize + 1; //should use a function to get some input on wich place to pick
    y = rand()%boardSize + 1; //instead of random. That's a great way to evolve this machine
  
  }while(!board->move(x, y, machineChar)); //
  board->print();
}//end of move function
