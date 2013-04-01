//Petter Abrahamsen s169962

#include "class_TicTacToe.h"
#include <iostream>
#include "class_boardGame.h"
#include "class_machine.h"
#include <stdlib.h>
#include <time.h>  

using namespace TicTac;

ticTacToe::ticTacToe() //starts a game of TicTacToe 
{
  char play;
  std::cout << "Do you want to play TicTacToe? (y or n) "; //if something else than y it jumps out
  std::cin >> play;

  while(play == 'y'){ //loops untill not yes

    std::cout << "How many in a row do you want to play with? ";
    int size;
    std::cin >> size; //gets the size of the board from the user
    while(std::cin.fail()){ //in case he tries something other than numbers

      while(std::cin.get() != '\n')
	std::cin.clear();

      std::cout << "Please use a whole number: \n";
      std::cin >> size; //loops untill a number is given
    }

    if(size < 3){ //sets size to 3 if it's smaller than that
      std::cout << "The number given was too small to use.\nThe standard is set to 3\n\n";
      size = 3;
    }

    else if(size > 50){ //sets size to 25 if it's bigger than 50
      std::cout << "Currently not axcepting numbers above 50.\nBecause of space issues when printing to screen\nSize is set to 25\n\n";
      size = 25;
    }

    boardGame board(size); //creates a board;
    std::cout << "This board uses coordinates.\nX is from left to right where 1 is all the way to the left.\nY is from bottom to top where 1 is at the bottom";
    board.print(); //prints the board
    machine p('O', size); //creates a machine to play
    player2 = &p;
    srand(time(NULL)); //random start
    int x = rand()%2;
    if(x == 1)
      player2->move(&board);

    while(ticTacToe::playRound(&board)); //starts playround untill the game is finished
    std::cout << "Do you want to play another round of TicTacToe? (y or n) ";
    std::cin >> play;
  } //jumps out if the answer is something else than y
  std::cout << "\nThank you for playing TicTacToe, have a nice day\n";
} //end of constructor

bool ticTacToe::playRound(boardGame *board) //starts to play a round
{
  if(board->tied()){ //checks for tie
    std::cout << "It's a tie, no one won.\n";
    return false;
  }
  
  std::cout << "Player 1, it's your turn:\nWhere do you want to place your X?\n";
  getCoordinates('X', board); //gets coordinates from the user
  char c = board->winner(); //checks if he has won
  
  if( c == 'X'){
      std::cout << "We have a winner! Congratulations player 1\n";
      return false;
  }

  if(board->tied()){ //checks if it's tied and jumps out if it is
    std::cout << "It's a tie, no one won.\n";
    return false;
  }
  player2->move(board); //lets the machine choose a place
  c = board->winner();
  if( c == 'O'){ //checks if the computer has won
    std::cout << "The computer won!\n";
    return false;
  }

  return true;
} //end of playRound function

void ticTacToe::getCoordinates(char c, boardGame *board) //gets coordinates from user
{
  int x, y; 
  bool move;
  do{
    while(std::cin.get() != '\n') //in case someone input something else than a number
      std::cin.clear();
    std::cout << "X-coordinate: ";
    std::cin >> x;
    if(std::cin.fail()){
      while(std::cin.get() != '\n')
	std::cin.clear();
    }
    std::cout << "Y-coordinate: ";
    std::cin >> y;
    move = board->move(x,y,c); //sends the char given and the coordinates to the board

    if(!move)
      std::cout << "\nPlease use a number between 1 and the size you chose.\n"; //if the numer is used this will come up
  }while(!move); //loops untill a place wich is free is chosen
  board->print(); //prints the board
} //end of getCoordinates function
