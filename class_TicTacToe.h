//Petter Abrahamsen s169962

#ifndef CLASS_TICTACTOE_H
#define CLASS_TICTACTOE_H


#include "class_boardGame.h"
#include "class_machine.h"

namespace TicTac
{

  class ticTacToe //creates a machine and a way for the user to play
  {
    machine *player2;
 public:
  //funksjoner
    ticTacToe();
    bool playRound(boardGame *board);
    void getCoordinates(char c, boardGame *board);
  };
}

#endif
