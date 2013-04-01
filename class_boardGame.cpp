//Petter Abrahamsen s169962

#include "class_boardGame.h"
#include "class_machine.h"
#include <iostream>

using namespace TicTac;


boardGame::boardGame(int size) //constructor recieves a size and uses it to create the board
{
  int gameSize = size;
  for(int i = 0; i < gameSize; i++){
    std::vector<char> b; //this for loop will create N*N places to have chars
      
    for(int i = 0; i < gameSize; i++){
      b.push_back(' ');
    }
    
    game.push_back(b);
  }
} //end of constructor

void boardGame::print()
{
  //prints the current view of the board
  std::cout << "\n\033[4m"; //starts underlining
  
  for(int i = game.size()-1; i > 0; i--){ //starts at the last place in the vector
    std::cout << " " << game[i][0] << " ";  //prints the first char in the vector
    
    for(int j = 1; j < game[i].size();j++){
      std::cout << "| " << game[i][j] << " ";  //prints the rest of the chars wiuth | in between
    }
    
    std::cout << "\n";
  }
  
  std::cout << "\033[0m " << game[0][0] << " ";
  
  for(int i = 1; i < game.size(); i++){  //prints the last line so you get the usual TicTacToe look
    std::cout << "| " << game[0][i] << " ";
  }
  
  std::cout << std::endl;
  return; 
} //end of print function

bool boardGame::move(int x, int y, char c)
{
  //sets the char c in the place x and y, where 1,1 is the bottom left place
  x--;  
  y--;
  if( x >= game.size() || y >= game.size() || x < 0 || y < 0) 
    return false; //in case something is wrong with the numbers false is returned

  if(game[y][x] == ' '){ //checks if the place is open
    game[y][x] = c;
    return true;
  }

  return false;
}//end of move function

bool boardGame::tied() //checks if it's a tie
{
  for(int i = 0; i < game.size(); i++){ //loops through all the chars in the vectors

    for(int j = 0; j < game[i].size(); j++){

      if(game[i][j] == ' ')   //if any char is ' ' the board is not full and it's not a tie.
	return false;
    }
  }
  return true;
}// end of tied function

char boardGame::winner() //function to check for a winner
{
  int numInRow = game.size(); //calls the other winner functions
  char c = ' ';
  c = boardGame::horizontalWinner();
  if(c != ' ')
    return c;
  c = boardGame::verticalWinner();
  if(c != ' ')
    return c;
  c = boardGame::diagonalWinner();
  return c;
}//end of winner function

char boardGame::horizontalWinner() //function to check if someone has won with a horizontal line
{
  int numInRow = game.size();
  char c;
  for(int i = 0; i<numInRow; i++){

    c = game[i][0];
    if(c != ' '){     //checks if the first in the line is ' ' then it can't be that line

      for(int j = 0; j < numInRow; j++){

	if(c != game[i][j]){  //checks to see if the same char is all the way

	  c = ' ';
	  continue; //jumps out if it's not
	}
      }

      if( c != ' ')
	return c;
    }
  }
  return c;  //returns the char of the winner
}//end of horizontalWinner function

char boardGame::verticalWinner() //checks if someone has won with a vertical line
{
  int numInRow = game.size();
  char c;
  for(int i = 0; i<numInRow; i++){
    
    c = game[0][i]; //checks every bottom char and matches up the line
    if(c != ' '){

      for(int j = 0; j < numInRow; j++){

	if(c != game[j][i]){ //if it's not the same it jumps out
	  c = ' ';
	  continue;
	}
      }

      if( c != ' ')
	return c;
    }
  }
  return c; //returns the char of the winner or ' ' if no one has won yet
} //end of verticalWinner function

char boardGame::diagonalWinner() //checks if someone has won with a diagonal line
{
  int numInRow = game.size();
  char c = game[0][0];
  for(int i = 1; i<numInRow; i++){ //checks if someone has won with 1,1 2,2, 3,3, and so on
    if(c == ' ' || c != game[i][i]){
      c = ' ';
      continue;
    }
  }
  if(c == ' '){
    c = game[numInRow-1][0];
      for(int i = 1; i <numInRow; i++){
	if(c == ' ' || c != game[numInRow-(i+1)][i]) //here it checks from top left to down right
	    return ' ';
      }
  }
  return c;

} //end of diagonalWinner function
