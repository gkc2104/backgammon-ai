Kamal Gurala  201201127
J.V Ashrith   201202126

The folder contains the C program backgammon.c that simulates the bot.

The program first generates all possible legal moves using th getStates() function.

After all the states are generated, a utility value is assigned to all the states based on how good they are.
The utility function is a weighted function of the no_of kills achieved in that move, the number of extra additional singles on the borad. It prefers moves wherein more doubles are formed in the upper half of the board.


