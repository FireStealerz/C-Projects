/* Tic-Tac-Toe Project written in C
*  Made by: Ivan Herran
*  2023-08-10 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*Check OS*/
#ifdef __WIN32
  #define OS "Windows"
  #define clear system.cls()
#elif __linux__
  #define OS "Linux" 
  #define clear system("clear")
#elif __APPLE__
  #define OS "Apple"
  #define clear system("clear")
#else
  #define OS NULL
  #define clear = NULL
#endif

/*Global Variables*/
unsigned int gameFieldTracker = 0, lengthGameField = 9;
char gameField[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
/* Prototypes */
void gameBoard(void);
void rules(void);
const char* checkOS(void);
int checkWinner(void);
void board(void);
bool checkInput(unsigned int coordinate, bool playerOneTurn);

int main(void)
{
  char selection;
  printf("Welcome to Tic-Tac-Toe written in C\n");
  printf("Game Made By: Ivan Herran\n");
  printf("Currently running program on %s\n", checkOS());
  rules();
  do{
  printf("\nPress 1 to start the game, press 2 to show the rules, press 3 to exit the game \n");
  printf("Selection: ");  
  selection = getchar();
  getchar();
  switch (selection) {
  case '1':
    clear;
    gameBoard();
  break;
  case '2':    
    rules();
  break;
  case '3':
    printf("\nThanks for playing!");
  break;
  default:
    printf("\nYou should press one of the 3 options!");
  break;  
  }      
  }while(selection != '3');  

  return EXIT_SUCCESS;
}

void rules(void){
  char selection;
  do{
    printf("\nThe game consists of a 3 by 3 board in which two players have to \n");
    printf ("match 3 consecutive slots with their respective symbols.\n");
    printf("The Symbols being \"X\" and \"o\" one for each player. \n");
    printf("Players chose which symbol starts first\n");
    printf("You have to chose the gameField of an empy spot you cant overwrite \n");
    printf("You cant overwrite spots which already have a symbol \n");
    printf("Good luck and have fun!\n");
    printf("Press any key to continue... \n");
    selection = getchar();
    getchar();
  }while(selection == '@');
}


const char* checkOS(void){
  return (OS == NULL) ? "Null" : OS;
}

void gameBoard(){
  char playerOne[20], playerTwo[20] ;
  unsigned int winner;
  unsigned int coordinate;
  bool gameState = true, playerOneTurn = true;
  printf("\nPlease enter name of player 1 - X: ");
  fgets(playerOne,  20, stdin);
  printf("\nPlease enter name of player 2 - O: ");
  fgets(playerTwo, 20, stdin);
  do{
    if (playerOneTurn == true) {
      printf("%s's Turn\n\n", playerOne ); 
      do{
      printf("Insert coordinate from 1 to 9: \n");
      scanf(" %d", &coordinate);
      getchar();  
    }while(checkInput(coordinate, playerOneTurn) == false);
      board();
      playerOneTurn = false;
    }else if (playerOneTurn == false) {
      printf("%s Turn\n\n", playerTwo);
      do{
      printf("Insert coordinate from 1 to 9: \n");
      scanf(" %d", &coordinate);
      getchar();
      }while(checkInput(coordinate, playerOneTurn) == false);
      board();
      playerOneTurn = true;
    } 
    winner = checkWinner();
    if (winner == 1 && playerOneTurn == false) {
      printf("%sWINS!\n", playerOne);
      gameState = false;
    }else if (winner == 1 && playerOneTurn == true){
      printf("%sWINS!\n", playerTwo);
      gameState = false;
    }else if (winner == 2){
      printf("Game ends in a DRAW!\n");
      gameState = false;
    }
 }while(gameState == true);

}

void board(void){

  printf("    |    |    \n");
  printf(" %c  | %c  | %c \n", gameField[0], gameField[1], gameField[2]);
  printf("    |    |    \n");
  printf("----|----|----\n");
  printf("    |    |    \n");
  printf(" %c  | %c  | %c \n", gameField[3], gameField[4], gameField[5]);
  printf("    |    |    \n");
  printf("----|----|----\n");
  printf("    |    |    \n");
  printf(" %c  | %c  | %c \n", gameField[6], gameField[7], gameField[8]);
  printf("    |    |    \n\n\n");
}


bool checkInput(unsigned int coordinate, bool playerOneTurn){
  unsigned int i ;
    if (gameField[coordinate - 1] == 'X' || gameField[coordinate - 1] == 'O'){
      printf("\nSpot already used try another one!\n");
      return false;
    }
  if (playerOneTurn == true && coordinate > 0 && coordinate <=  9){
    gameFieldTracker++;
    gameField[coordinate - 1] = 'X'; 
    return true;
  }else if(playerOneTurn == false && coordinate > 0 && coordinate < 9){
    gameFieldTracker++;
    gameField[coordinate - 1] = 'O';
    return true;
  }else {
    printf("\nInvalid coordinate, no changes to the game field!\n\n");
    return false;
  }
  return false;
}

int checkWinner(void){ 
  if (gameField[0] == gameField[1] && gameField[1] == gameField[2]) {
    return 1;
  }else if (gameField[3] == gameField[4] && gameField[4] == gameField[5]) {
    return 1;
  }else if (gameField[6] == gameField[7] && gameField[7] == gameField[8]) {
    return 1;
  }else if (gameField[0] == gameField[3] && gameField[3] == gameField[6]) {
    return 1;
  }else if (gameField[1] == gameField[4] && gameField[4] == gameField[7]) {
    return 1;
  }else if (gameField[2] == gameField[5] && gameField[5] == gameField[8]) {
    return 1;
  }else if (gameField[0] == gameField[4] && gameField[4] == gameField[8]) {
    return 1;
  }else if (gameField[6] == gameField[4] && gameField[4] == gameField[2]) {
    return 1;
  }else if (gameFieldTracker == 9){
    return 2;
  }  
  return 0; 
}
