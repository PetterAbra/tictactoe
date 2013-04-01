//Petter Abrahamsen s169962

#ifndef CLASS_BOARDGAME_H
#define CLASS_BOARDGAME_H

#include <vector>

namespace TicTac
{
  class boardGame
  {
    std::vector<std::vector<char> > game;
   public:
    boardGame(int size);
    void print();
    bool move(int x, int y, char c);
    bool tied();
    char winner();
    char horizontalWinner();
    char verticalWinner();
    char diagonalWinner();
  };
}

#endif
