//Petter Abrahamsen s169962

#ifndef CLASS_BOARDGAME_H
#define CLASS_BOARDGAME_H

#include <vector>

namespace TicTac
{
  class boardGame
  {  //using a vector of vectors of chars to represent the board. 
    std::vector<std::vector<char> > game;
   public:
    boardGame(int size);  //constructor
    void print();   //prints the board
    bool move(int x, int y, char c);  //adds a char on place x and y
    bool tied();   //checks if the board is full
    char winner();  //checks if someone has won the game
    char horizontalWinner();  //checks if someone has won horizontal 
    char verticalWinner();   //checks if someone has won vertical
    char diagonalWinner();   //checks if someone has won diagonal
  };           //used multiple functions to determine if someone had won
}              //the reason was that it was easier to get everything right in steps

#endif
