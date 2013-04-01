//Petter Abrahamsen s169962

#include "class_boardGame.h"
#include "class_machine.h"
#include <iostream>

using namespace TicTac;


boardGame::boardGame(int size)
{
  int gameSize = size;
  for(int i = 0; i < gameSize; i++){
      std::vector<char> b;
      
      for(int i = 0; i < gameSize; i++){
	  b.push_back(' ');
      }
      
      game.push_back(b);
  }
 
}

void boardGame::print()
{
  //prints the current view of the board
  std::cout << "\n\033[4m";
  
  for(int i = game.size()-1; i > 0; i--){
    std::cout << " " << game[i][0] << " ";
    
    for(int j = 1; j < game[i].size();j++){
      std::cout << "| " << game[i][j] << " "; 
    }
    
    std::cout << "\n";
  }
  
  std::cout << "\033[0m " << game[0][0] << " ";
  
  for(int i = 1; i < game.size(); i++){
    std::cout << "| " << game[0][i] << " ";
  }
  
  std::cout << std::endl;
  return; 
}

bool boardGame::move(int x, int y, char c)
{
  x--;
  y--;
  if( x >= game.size() || y >= game.size() || x < 0 || y < 0) 
    return false;

  if(game[y][x] == ' '){
    game[y][x] = c;
    return true;
  }

  return false;

}

bool boardGame::tied()
{
  for(int i = 0; i < game.size(); i++){

    for(int j = 0; j < game[i].size(); j++){

      if(game[i][j] == ' ')
	return false;
    }
  }
  return true;
}

char boardGame::winner()
{
  int numInRow = game.size();
  char c = ' ';
  c = boardGame::horizontalWinner();
  if(c != ' ')
    return c;
  c = boardGame::verticalWinner();
  if(c != ' ')
    return c;
  c = boardGame::diagonalWinner();
  return c;
}

char boardGame::horizontalWinner()
{
  int numInRow = game.size();
  char c;
  for(int i = 0; i<numInRow; i++){

    c = game[i][0];

    if(c != ' '){

      for(int j = 0; j < numInRow; j++){

	  if(c != game[i][j]){

	    c = ' ';
	    continue;
	  }
      }

      if( c != ' ')
	return c;
    }
  }
  return c;
}

char boardGame::verticalWinner()
{
  int numInRow = game.size();
  char c;
  for(int i = 0; i<numInRow; i++){

    c = game[0][i];
    if(c != ' '){

      for(int j = 0; j < numInRow; j++){

	if(c != game[j][i]){
	  c = ' ';
	  continue;
	}
      }

      if( c != ' ')
	return c;
    }
  }
  return c;

}

char boardGame::diagonalWinner()
{
  int numInRow = game.size();
  char c = game[0][0];
  for(int i = 1; i<numInRow; i++){
    if(c == ' ' || c != game[i][i]){
      c = ' ';
      continue;
    }
  }
  if(c == ' '){
    c = game[numInRow-1][0];
      for(int i = 1; i <numInRow; i++){
	if(c == ' ' || c != game[numInRow-(i+1)][i])
	    return ' ';
      }
  }
  return c;

}
