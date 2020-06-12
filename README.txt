Project1 involves making "Hey! That's my fish" game 
The void main() method consists of declaring variables, placing player and AI on the board, and the 
actual gameplay. The user input is "row col."
There is only 1 global variable, which is the gameboard formatted as a 2D array.
*** Gameplay:
- The player gets to go first at any 1-point coordinates on the board. The AI does the same and then 
prints out the board.
- Then the main component of void main() runs. While playerEnd and aiEnd is false (0), the game keeps running.
- The player plays first. If the player can still make a move, then checkEndgameCase will return 1 and the player can play.
playerMove will take an array argument,take the user input and returns it.
- Edge cases such as an input outside of the board coodinate or a coordinate where AI has played will return :"Invalid point."
- Then it checks if that move is valid by checkDir which takes the old and new coordinate array and return 1 if 
there is no 'A' or '.' at that point or any point in between.
- I kept track of points using playerPoint and aiPoint. player point is put into playerPoint array before that point
switches to P.

- Then it is AI turn. checkEndgameCase is also used with AI, if it returns 1 then the game continues.
- AI is the AI main algorithm. This function traverses all 8 directions, keep track of the highestValue and if that point is the 
highest then aiCoor is returned with that coordinate.
- That coordinates is then put into the grid/board after it point is put into aiPoint.
- After both player and AI has played their turn, the program prints the updated board and print both the player and AI old
and new coordinate.

- If the player runs out of move first, playerEnd is true, then only the AI plays and vice versa.
- If both are unable to move then the game is over. The program prints both the player and AI points with for loops and calculate sum
at the same time. It then compare points and decide the winner.

***Methods:
- void playerMove(int arr[])
    + Take array as argument and scan user input to get new coordinate for player
- checkEndgameCase(intPlayerPos[])
    + Take the position array argument and check if the surrounding eight directions are '.', 'P', or 'A'. If it does then it returns 0.
    + Also take into account if the position is on the edge.
- checkDir(int before[], int after[])
    + Take the position array before and check every direction. If it reaches '.' or 'A' then return 0, otherwise it checks to see
    if the new coordinate is valid in that direction. In other words, making sure the new coordinate is in a straight line and there 
    is nothing between the 2 points
- void AI(int aiCoor[])
    + Takes the current AI coordinate and search all 8 directions for one with the highest point value then assign that coordinate to aiCoor.








