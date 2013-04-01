//Petter Abrahamsen s169962

#include "class_TicTacToe.h"
#include <iostream>
#include "class_boardGame.h"
#include "class_machine.h"
#include <stdlib.h>
#include <time.h>  

using namespace TicTac;

ticTacToe::ticTacToe()
{
  char play;
  std::cout << "Do you want to play TicTacToe? (y or n) ";
  std::cin >> play;

  while(play == 'y'){

    std::cout << "How many in a row do you want to play with? ";
    int size;
    std::cin >> size;
    while(std::cin.fail()){

      while(std::cin.get() != '\n')
	std::cin.clear();

      std::cout << "Please use a whole number: \n";
      std::cin >> size;
    }

    if(size < 3){
      std::cout << "The number given was too small to use.\nThe standard is set to 3\n\n";
      size = 3;
    }

    else if(size > 50){
      std::cout << "Currently not axcepting numbers above 50.\nBecause of space issues when printing to screen\nSize is set to 25\n\n";
      size = 25;
    }

    boardGame board(size);
    std::cout << "This board uses coordinates.\nX is from left to right where 1 is all the way to the left.\nY is from bottom to top where 1 is at the bottom";
    board.print();
    machine p('O', size);
    player2 = &p;
    srand(time(NULL));
    int x = rand()%2;

    if(x == 1)
      player2->move(&board);

    while(ticTacToe::playRound(&board));
    std::cout << "Do you want to play another round of TicTacToe? (y or n) ";
    std::cin >> play;
  }
  std::cout << "\nThank you for playing TicTacToe, have a nice day\n";
}

bool ticTacToe::playRound(boardGame *board)
{
  if(board->tied()){
    std::cout << "It's a tie, no one won.\n";
    return false;
  }
  
  std::cout << "Player 1, it's your turn:\nWhere do you want to place your X?\n";
  getCoordinates('X', board);
  char c = board->winner();
  
  if( c == 'X'){
      std::cout << "We have a winner! Congratulations player 1\n";
      return false;
  }

  if(board->tied()){
    std::cout << "It's a tie, no one won.\n";
    return false;
  }
  player2->move(board);
  c = board->winner();
  if( c == 'O'){
    std::cout << "The computer won!\n";
    return false;
  }

  return true;
}

void ticTacToe::getCoordinates(char c, boardGame *board)
{
  int x, y;
  bool move;
  do{
    while(std::cin.get() != '\n')
      std::cin.clear();
    std::cout << "X-coordinate: ";
    std::cin >> x;
    if(std::cin.fail()){
      while(std::cin.get() != '\n')
	std::cin.clear();
    }
    std::cout << "Y-coordinate: ";
    std::cin >> y;
    move = board->move(x,y,c);

    if(!move)
      std::cout << "\nPlease use a number between 1 and the size you chose.\n";
  }while(!move);
  board->print();
}
