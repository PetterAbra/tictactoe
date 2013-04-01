#TicTacToe

*This report is to help someone get into my code.

###Classes:
 - machine: This is for the computer to choose where it should place it's char
 - boardgame: This simulates the board with N*N squares
 - tictactoe: This is keeping track of what is happening and lets the program run as long as the user wants to
 - tictac: This is just the main function and starts the program.

If you want to implement this program it's just to copy the .cpp and .h files except tictac and use your own main. This will let you easily have more games with different setups. I have chose to try to get the program to never get any faults instead of implementing a great AI player. The AI player is about as simple as you can get it, since the way to choose a place to put your char when you have N*N places is a really big task. The code is commented as much as possible. There is a lot of for functions to loop through the vector. I used a vector of vectors of chars to represent the board, since I needed to change the size of it after the program had started. Therefor a char[][] was impossible. This program is basic in c++ and AI, and I recommend to play human vs human, that's the most fun. I have used very few classes since I didn't see any reason to add more classes and what to add. Maybe that was a bad call, but for me it was quite easy to keep track of the board in one class and the input from the user in one class and the machine input in a third class. It should be easy to add more than 1 player, because of the vector of chars.

*Summary:
 - The machine class is the computer in the game, this is not a very smart computer, it choses at random.
 - The board is the class boardGame's vector of vectors of chars and lets more than 2 players play 
 - Tictactoe is input from user.