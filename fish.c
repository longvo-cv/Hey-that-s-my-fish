#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

char grid[7][7]=
    {
        {' ','1','2','3','4','5','6'},
        {'1','1','1','1','1','1','1'},
        {'2','1','2','2','2','2','1'},
        {'3','1','2','3','3','2','1'},
        {'4','1','2','3','3','2','1'},
        {'5','1','2','2','2','2','1'},
        {'6','1','1','1','1','1','1'}
    };
//print gameboard
void print(char arr[7][7])
{
for (int i = 0; i< 7; ++i)
    {
        for (int j = 0; j < 7 ; ++j)
        {
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }
}
//Take user input and assign them to playerCoor
void playerMove(int arr[])
{
    int row;
    int col;
    printf("Player turn. Please enter coordinates: ");
    scanf("%d %d",&row,&col);
    arr[0] = row;
    arr[1] = col;
}

// check to see if there are any possible moves. playerPos here could either be human player or AI
int checkEndgameCase (int playerCoor[])
{
    int row = playerCoor[0];
    int col = playerCoor[1];
    
    //top case
    if ((row == 1) &&
      (grid[row][col+1] == '.' || grid[row][col+1] == 'A'|| grid[row][col+1] == 'P') &&
      (grid[row+1][col+1] == '.' || grid[row+1][col+1] == 'A' || grid[row+1][col+1] == 'P') &&
      (grid[row+1][col] == '.' || grid[row+1][col] == 'A'|| grid[row+1][col] == 'P') &&
      (grid[row+1][col-1] == '.' || grid[row+1][col-1] == 'A' || grid[row+1][col-1] == 'P') &&
      (grid[row][col-1] == '.' || grid[row][col-1] == 'A' || grid[row][col-1] == 'P')) 
      {
        return 0;
      }

    //bottom edge
    else if ((row == 6) &&
        (grid[row-1][col] == '.' || grid[row-1][col] == 'A'  || grid[row-1][col] == 'P') &&
        (grid[row-1][col+1] == '.' || grid[row-1][col+1] == 'A'  || grid[row-1][col+1] == 'P') &&
        (grid[row][col+1] == '.' || grid[row][col+1] == 'A' || grid[row][col+1] == 'P') &&
        (grid[row][col-1] == '.' || grid[row][col-1] == 'A'  || grid[row][col-1] == 'P') &&
        (grid[row-1][col-1] == '.' || grid[row-1][col-1] == 'A' || grid[row-1][col-1] == 'P')) 
        {
          return 0;
        }

    //right edge
    else if ((col == 1) &&
        (grid[row-1][col] == '.' || grid[row-1][col] == 'A' || grid[row-1][col] == 'P') &&
        (grid[row-1][col+1] == '.' || grid[row-1][col+1] == 'A' || grid[row-1][col+1] == 'P') &&
        (grid[row][col+1] == '.' || grid[row][col+1] == 'A' || grid[row][col+1] == 'P') &&
        (grid[row+1][col+1] == '.' || grid[row+1][col+1] == 'A' || grid[row+1][col+1] == 'P') &&
        (grid[row+1][col] == '.' || grid[row+1][col] == 'A' || grid[row+1][col] == 'P')) 
        {
          return 0;
        }
    //left edge
    else if ((col == 6) &&
        (grid[row][col-1] == '.' || grid[row][col-1] == 'A' || grid[row][col-1] == 'P') &&
        (grid[row+1][col-1] == '.' || grid[row+1][col-1] == 'A' || grid[row+1][col-1] == 'P') &&
        (grid[row-1][col] == '.' || grid[row-1][col] == 'A'  || grid[row-1][col] == 'P') &&
        (grid[row+1][col] == '.' || grid[row+1][col] == 'A' || grid[row+1][col] == 'P') &&
        (grid[row-1][col-1] == '.' || grid[row-1][col-1] == 'A' || grid[row-1][col-1] == 'P')) 
        {
          return 0;
        }

  //If anywhere else then check all 8 directions
  else if ((grid[row-1][col] == '.' || grid[row-1][col] == 'A' || grid[row-1][col] == 'P') &&
      (grid[row-1][col+1] == '.' || grid[row-1][col+1] == 'A' || grid[row-1][col+1] == 'P') &&
      (grid[row-1][col-1] == '.' || grid[row-1][col-1] == 'A' || grid[row-1][col-1] == 'P')&& 
      (grid[row+1][col] == '.' || grid[row+1][col] == 'A' || grid[row+1][col] == 'P') &&
      (grid[row+1][col-1] == '.' || grid[row+1][col-1] == 'A' || grid[row+1][col-1] == 'P') &&
      (grid[row+1][col+1] == '.' || grid[row+1][col+1] == 'A' || grid[row+1][col+1] == 'P') &&
      (grid[row][col-1] == '.' || grid[row][col-1] == 'A' || grid[row][col-1] == 'P') &&
      (grid[row][col+1] == '.' || grid[row][col+1] == 'A' || grid[row][col+1] == 'P') )
      {
        return 0;
      }
  return 1;
}

// check previous coordinates and new input. If this input is valid, return 1
int checkDir (int before[], int after[])
{   
  int row,col;
  int x,y;
  x = after[0];
  y = after[1];

  //north
  row = before[0]-1;
  col = before[1];
  while (grid[row][col] != '.' && grid[row][col] != 'A' && row > 0) 
  {
    if (row == x && col == y) 
    {
      return 1;
    }
    row--;
  }

//west
  row = before[0];
  col = before[1]-1;
  while (grid[row][col] != '.' && grid[row][col] != 'A' && col > 0) 
  {
    if (row == x && col == y) 
    {
      return 1;
    }
    col--;
  }

  // south
  row = before[0]+1;
  col = before[1];
  while (grid[row][col] != '.' && grid[row][col] != 'A' && row < 7) 
  {
    if (row == x && col == y) 
    {
      return 1;
    }
    row++;
  }
  
  //east
  row = before[0];
  col = before[1]+1;
  while (grid[row][col] != '.' && grid[row][col] != 'A' && col < 7) 
  {
    if (row == x && col == y) 
    {
      return 1;
    }
    col++;
  }

  //north-west
  row = before[0]-1;
  col = before[1]-1;
  while (grid[row][col] != '.' && grid[row][col] != 'A' && row > 0 && col > 0) 
  {
    if (row == x && col == y) 
    {
      return 1;
    }
    row--;
    col--;
  }
 

  //northeast
  row = before[0]-1;
  col = before[1]+1;
  while (grid[row][col] != '.' && grid[row][col] != 'A' && row > 0 && col < 7) 
  {
    if (row == x && col == y)
    {
      return 1;
    }
    row--;
    col++;
  }
 

  //southwest
  row = before[0]+1;
  col = before[1]-1;
  while (grid[row][col] != '.' && grid[row][col] != 'A' && row < 7 && col > 0) 
  {
    if (row == x && col == y) 
    {
     return 1;
    }
    row++;
    col--;
  }
 

  //southeast
  row = before[0]+1;
  col = before[1]+1;
  while (grid[row][col] != '.' && grid[row][col] != 'A' && row < 7 && col < 7) 
  {
    if (row == x && col == y) 
    {
      return 1;
    }
    row++;
    col++;
  }
  return 0;
}


//AI program
void AI (int aiCoor[])
{
  int row,col;
  char highestValue ='0';
  int curr[2] ;
  curr[0] = aiCoor[0];
  curr[1] = aiCoor[1];


  //north
  row = curr[0]-1;
  col = curr[1];
  while (grid[row][col] != '.' && grid[row][col] != 'P' && grid[row][col] != 'A'  && row > 0) 
  {
    if (grid[row][col] >= highestValue) 
    {
      highestValue = grid [row][col];
      aiCoor[0]=row;
      aiCoor[1]=col;
    }
    row--;
  }

  //south
  row = curr[0]+1;
  col = curr[1];
  while (grid[row][col] != '.' && grid[row][col] != 'P' && grid[row][col] != 'A' && row < 7) 
  {
    if (grid[row][col] >= highestValue) 
    {
      highestValue = grid [row][col];
      aiCoor[0]=row;
      aiCoor[1]=col;
    }
    row++;
  }
 

  //west
  row = curr[0];
  col = curr[1]-1;
  while (grid[row][col] != '.' && grid[row][col] != 'P' && grid[row][col] != 'A' && col > 0) 
  {
    if (grid[row][col] >= highestValue) 
    {
      highestValue = grid [row][col];
      aiCoor[0]=row;
      aiCoor[1]=col;
    }
    col--;
  }
 

  //east
  row = curr[0];
  col = curr[1]+1;
  while (grid[row][col] != '.' && grid[row][col] != 'P'  && grid[row][col] != 'A'&& col < 7) 
  {
    if (grid[row][col] >= highestValue) 
    {
      highestValue = grid [row][col];
      aiCoor[0]=row;
      aiCoor[1]=col;
    }
    col++;
  }
 

  //northwest
  row = curr[0]-1;
  col = curr[1]-1;
  while (grid[row][col] != '.' && grid[row][col] != 'P'&& grid[row][col] != 'A' && row > 0 && col > 0) 
  {
    if (grid[row][col] >= highestValue) 
    {
      highestValue = grid [row][col];
      aiCoor[0]=row;
      aiCoor[1]=col;
    }
    row--;
    col--;
  }
 

  //northeast
  row = curr[0]-1;
  col = curr[1]+1;
  while (grid[row][col] != '.' && grid[row][col] != 'P' && grid[row][col] != 'A' && row > 0 && col < 7) 
  {
    if (grid[row][col] >= highestValue) 
    {
     highestValue = grid [row][col];
      aiCoor[0]=row;
      aiCoor[1]=col;
    }
    row--;
    col++;
  }
 

  //southwest
  row = curr[0]+1;
  col = curr[1]-1;
  while (grid[row][col] != '.' && grid[row][col] != 'P' && grid[row][col] != 'A' && row < 7 && col > 0) 
  {
    if (grid[row][col] >= highestValue) 
    {
     highestValue = grid [row][col];
      aiCoor[0]=row;
      aiCoor[1]=col;
    }
    row++;
    col--;
  }
 

  //southeast
  row = curr[0]+1;
  col = curr[1]+1;
  while (grid[row][col] != '.' && grid[row][col] != 'P'&& grid[row][col] != 'A' && row < 7 && col < 7) 
  {
    if (grid[row][col] >= highestValue) 
    {
      highestValue = grid [row][col];
      aiCoor[0]=row;
      aiCoor[1]=col;
    }
    row++;
    col++;
  }
}



void main()
{
    int playerFirstTurn = 1;
    int aiFirstTurn = 1;
    int playerCoorBF[2];
    int playerCoorAF[2];
    int aiCoor[2];
    int first = 1;
    int gamePlacement = 1;
    int gameRunning = 1;
    int turn = 1;
    int playerEnd = 0;
    int aiEnd = 0;
    int tmp[2];
    int printOrder = 0;
    int playerPoint[36];
    int aiPoint[36];
    int pointKeeperP = 1;
    int pointKeeperAI = 1;

    //fill both point array with 0
    for (int i = 0 ; i < 36 ; ++i)
    {
        playerPoint[i] = 0;
        aiPoint[i] = 0;
    }
    print(grid);

//place P on the board
while (gamePlacement == 1)
    {
        // place player P and AI on board for the first time
    while(playerFirstTurn == 1)
        {
            playerMove(playerCoorBF);
                if(grid[playerCoorBF[0]][playerCoorBF[1]] != '1' || playerCoorBF[0] > 6 || playerCoorBF[1] > 6)
                {
                    printf("Invalid starting point. Choose a coordinate with 1 points \n");
                }
                else 
                {
                    grid[playerCoorBF[0] ][playerCoorBF[1] ] = 'P';
                    playerFirstTurn = 0;
                }     
        }
    while(aiFirstTurn == 1)
    {
       if (first == 1) 
        {
            int bool = 0;
            srand(time(NULL));
            while (bool == 0)
            {
                int row = (rand() % (6) ) + 1; 
                int col = (rand() % (6) ) + 1; 
                aiCoor[0] = row;
                aiCoor[1] = col;
                    if(grid[row][col] == '1' && grid[aiCoor[0]][aiCoor[1]] != 'P')
                        {
                        grid[row][col] = 'A';
                        bool = 1;
                        //aiPoint[0] = 1;
                        aiFirstTurn =0;
                        first = 0;
                         }
                else continue;
            }
            gamePlacement = 0;   
        }
        print(grid);
    }
 }

 while(gameRunning == 1)
 {
     if ( playerEnd == 1 && aiEnd == 1)
     {   int sumP = 1;
         int sumA = 1;
         printf("\n");
         printf("No more possible moves. We're in the endgame \n");
         printf("Player points: 1");
            for(int i = 1; i < 36;++i)
            {
                if(playerPoint[i] != 0)
                {
                sumP += playerPoint[i];
                printf(" + %i", playerPoint[i]);
                }
                if(playerPoint[i] == 0)
                {
                    printf(" = %i \n",sumP);
                    break;
                }
            }
        printf("AI points: 1");
            for(int i = 1; i < 36;++i)
            {
                if(aiPoint[i] != 0)
                {
                sumA += aiPoint[i];
                printf(" + %i", aiPoint[i]);
                }
                if(aiPoint[i] == 0)
                {
                    printf(" = %i \n",sumA);
                    break;
                }
            }
        if(sumP == sumA) 
        {
            printf("Game is a tie \n");
        }
        else if (sumP > sumA) {printf("Player wins! \n");}
        else if (sumA > sumP) {printf("AI wins! \n");}
       // (sumP > sumA) ? printf("Player wins! \n") : printf("AI wins! \n");
         gameRunning = 0;  
     }
    else  if (turn % 2 == 1) // player turn
     {
         // if player can't make anymore moves
        if (checkEndgameCase(playerCoorBF) == 0)
                {  
                    playerEnd = 1;
                    ++turn;
                    ++printOrder;
                }
        // if a move is still possible
        else if(playerEnd == 0)
         {
            playerMove(playerCoorAF);
            if(
               (playerCoorAF[0] > 6 || 
                playerCoorAF[1] > 6 ||
                grid[ playerCoorAF[0]] [playerCoorAF[1]] == grid[playerCoorBF[0]][playerCoorBF[1]] ||
                checkDir(playerCoorBF, playerCoorAF) == 0)
              )
                    {
                        printf("Invalid point. Choose another coordinate \n");
                    }
            else if( checkDir(playerCoorBF, playerCoorAF) == 1)
                    {   playerPoint[pointKeeperP] = grid[playerCoorAF[0]] [playerCoorAF[1]] - '0';
                        grid[playerCoorAF[0]][playerCoorAF[1] ] = 'P';
                        grid[playerCoorBF[0]][playerCoorBF[1] ] = '.';
                        ++pointKeeperP;
                        ++turn;
                        ++printOrder; 
                    }
        }
     }

     else if (turn % 2 == 0) // AI turn
     {  // if a move is not possible for AI
         if (checkEndgameCase(aiCoor) == 0)
                {
                    aiEnd = 1;
                    ++turn;
                    ++printOrder;
                }
         else if (aiEnd == 0)
         {
             // If a move is still possible for the AI
            if (checkEndgameCase(aiCoor) == 1)
                {
                    grid[aiCoor[0]][aiCoor[1]] = '.';
                    tmp[0] = aiCoor[0]; tmp[1] = aiCoor[1];
                    AI(aiCoor);
                    aiPoint[pointKeeperAI] = grid[aiCoor[0]][aiCoor[1]] - '0';
                    grid[aiCoor[0]][aiCoor[1]] = 'A';
                    ++pointKeeperAI;
                    ++turn;
                    ++printOrder;
                }
         }
        // printing the updated board and Where the player and AI move to
         if ( (printOrder % 2 == 0) )
         {
            print(grid);
            (aiEnd == 0) ? printf("AI moved from (%i,%i) to (%i,%i)\n",tmp[0],tmp[1],aiCoor[0],aiCoor[1]) :printf("AI has run out of moves \n");
            (playerEnd == 0) ? printf("Player moved from (%i,%i) to (%i,%i)\n",playerCoorBF[0],playerCoorBF[1],playerCoorAF[0],playerCoorAF[1]) :
                                printf("Player has run out of moves \n");
            playerCoorBF[0]=playerCoorAF[0];
            playerCoorBF[1]=playerCoorAF[1];
         }   
     }
 }
}

