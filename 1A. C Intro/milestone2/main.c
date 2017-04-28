//I declare that the attached assignment is wholly my own work in accordance with
//Seneca Academic Policy. No part of this assignment has been copied manually or
//electronically from any other source (including web sites) or distributed to
//other students.
//Name : Alejandro Mesa
//Student ID : 038515151

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define LOW 4 //Boardsize (non-inclusive)
#define HIGH 15 //Boardsize (inclusive)


//PROTOTYPES
char getDisplayTile(unsigned int index, unsigned int playerPosition, char playerName);
void displayBoard(unsigned int boardSize, unsigned int playerPosition, char playerName);
int getValidInteger(int low, int high);
char getValidCharacter(char low, char high);
void initPlayer(int *playerScore, int playerPrizes[], unsigned int *prizeCount,char *playerName, int *playerPosition);
void playGame(unsigned int boardSize, int *playerScore, int playerPrizes[],unsigned int *prizeCount, char *playerName, int *playerPosition);
int getRandom(int low, int high);
unsigned int playerRoll();
void winPrize(int playerPrizes[], unsigned int *prizeCount); //
void winGrandPrize(int playerPrizes[], unsigned int *prizeCount); //
void loseItem(int playerPrizes[], unsigned int *prizeCount); //
int checkout(int *playerScore, int playerPrizes[], unsigned int *prizeCount); //
char tile(int playerPosition);

//MAIN PROGRAM
int main(){

    //Variables
    char menu_choice;
    int flag = 0;
    //srand(time(NULL));



    //Player Variables
    int playerScore;
    int playerPrizes[10];
    unsigned int prizeCount;
    int playerPosition;
    char playerName;
    unsigned int boardSize = 0;

    //Starting Program
    printf("Welcome to CHECKOUT The Game\n");
    printf("Main Menu\n");

//Do-while that runs until q is selected
do{

    //Do for error checking menu
    do{
    printf("p-(p)lay q-(q)uit r-inst(r)uctions s-HI(s)core: ");
    scanf(" %c",&menu_choice);
    if(menu_choice=='p'||menu_choice=='q'||menu_choice=='r'||menu_choice=='s')
        flag=1;
    if(flag==0)
        printf("Invalid choice\n");
    }while(flag==0);

    //If play selected start the game
    if(menu_choice=='p'){

        initPlayer(&playerScore,playerPrizes,&prizeCount,&playerName,&playerPosition); //Get playerName
        printf("Enter board size: ");
        boardSize = getValidInteger(LOW,HIGH); //Get BoardSize (non inclusive, inclusive)
        playGame(boardSize, &playerScore, playerPrizes, &prizeCount, &playerName, &playerPosition); //Initialize the game

    }
    //If High Score selected
    if(menu_choice=='s'){

        printf("__\n");
        printf("  \\_______\n");
        printf("   \\++++++|\n");
        printf("    \\=====|\n");
        printf("    0---  0\n\n");
        printf("HI SCORE: %d\tPlayer Name: %c\n",playerScore,playerName);

    }
    //If Quit selected
    if(menu_choice=='q'){
        printf("THis game is much more fun than bash...\n");
    }

}while(menu_choice!='q');

    return 0;
}


//FUNCTIONS
//Get the Tile type depending on playerPosition and index
char getDisplayTile(unsigned int index, unsigned int playerPosition, char playerName){

    char tile;

    if(index==playerPosition)
        tile=playerName;
    else if(index==0)
        tile='C';
    else if(index%7==0)
        tile='G';
    else if(index%5==0)
        tile='L';
    else if(index%3==0)
        tile='W';
    else
        tile = ' ';

    return tile;

}

//Get the tile type function to check  playerPosition letter without passing all the other arguments from the previous function
char tile(int playerPosition){

    char tile;
    if(playerPosition==0)
        tile='C';
    else if(playerPosition%7==0)
        tile='G';
    else if(playerPosition%5==0)
        tile='L';
    else if(playerPosition%3==0)
        tile='W';
    else
        tile = ' ';

    return tile;

}

//DisplayBoard - Algorithms to print the board with player position
void displayBoard(unsigned int boardSize,unsigned int playerPosition, char playerName){
     int i;



     int middle_space = boardSize-2; //this is the middle space on the row on the center

     int first_left = boardSize-1+(boardSize-1)+(boardSize-1)+(boardSize-2); //this is the first number on the left after finishing first line (left column)
     int first_right = boardSize; //this is the first number on the right after finishing top row (right column)

     int rows = boardSize-2; //this is the rows not inlcuding top row or bottom row
     int first_last_row = boardSize + (boardSize-1) + (boardSize-1); //this is the first number of the last row which will be regressive on the loop

     //If boardSize is 1
    if(boardSize==1){
        printf(" ___ ");
        printf("\n");
        printf("| %c |",getDisplayTile(0,playerPosition,playerName));

        printf("\n");

        printf("|___|");
        printf("\n");


        }
    //Sizes > 1
    else{
     ////FIRST ROW PRINTING
     //Printing top part
     for(i=0;i<boardSize;i++){

        printf(" ___ ");

     }
     printf("\n");
     //Printing mid part
     for(i=0;i<boardSize;i++){

        printf("| %c |",getDisplayTile(i,playerPosition,playerName));

     }
     printf("\n");
     //Printing bottom part
     for(i=0;i<boardSize;i++){

        printf("|___|");

     }
     printf("\n");


     ////MID ROWS PRINTING

     for(i=0;i<rows;i++){
        int y; //For the inner loops
        //Printing top part
        printf(" ___ ");
        for(y=0;y<middle_space;y++){
                printf("     ");
        }
        printf(" ___ ");
        printf("\n");
        //Printing mid part
        printf("| %c |",getDisplayTile(first_left,playerPosition,playerName));
        for(y=0;y<middle_space;y++){
                printf("     ");
        }
        printf("| %c |",getDisplayTile(first_right,playerPosition,playerName));
        printf("\n");
        //Printing bottom part
        printf("|___|");
        for(y=0;y<middle_space;y++){
                printf("     ");
        }
        printf("|___|");
        printf("\n");

        //Decresing the count of the left column and increasing the count of right column
        first_left--;
        first_right++;


     }






     ////LAST ROW PRINTING
     //Printing top part
     for(i=first_last_row-1;i>(boardSize+(boardSize-2)-1);i--){

        printf(" ___ ");

     }
     printf("\n");
     //Printing mid part
     for(i=first_last_row-1;i>(boardSize+(boardSize-2)-1);i--){

        printf("| %c |",getDisplayTile(i,playerPosition,playerName));

     }
     printf("\n");
     //Printing bottom part
     for(i=first_last_row-1;i>(boardSize+(boardSize-2)-1);i--){

        printf("|___|");

     }
     printf("\n");



     }

}

//Get a Valid Integer between limits
int getValidInteger(int low, int high){

    int choice;
    int var = 0;


    do{

       scanf(" %d",&choice);
       if ( choice > low  && choice <= high){
	   var = 1;
       }
       else{
	    printf("Invalid choice!\n");
       }

    } while( var == 0 );

    return choice;
}

//Get a Valid Character between limits
char getValidCharacter(char low, char high){

    char choice = ' ';
    int var = 0; //flag to exit the loop


    do{
       printf("Enter player ID: ");
       scanf(" %c",&choice);
       if ( choice > low  && choice <= high){
	   var = 1;
       }
       else{
	    printf("Invalid choice!\n");
       }

    } while( var == 0 );

    return choice;
}

//Initialize player
void initPlayer(int *playerScore, int playerPrizes[], unsigned int *prizeCount, char *playerName, int *playerPosition){

    //Initiliaze player stats
    *playerScore = 0;
    playerPrizes = 0;
    *prizeCount = 0;
    *playerPosition = 0;

    int players = 1;

    printf("number of players is %d\n", players);

    *playerName = getValidCharacter(33,126);
    //Values like ! " # $ % & ' ( ) * + , - . / @   ASCI Codes


}

void playGame(unsigned int boardSize, int *playerScore, int playerPrizes[], unsigned int *prizeCount, char *playerName, int *playerPosition){
              int i;
              int win = 0;
              char position;


              //flag to keep the game playing
              while(win==0){

                //Display the board including the player’s position on the board
                displayBoard(boardSize,*playerPosition,*playerName);

                //Display the player’s score, and inventory information
                printf("score: ");
                *playerScore=0;
                //Loop to count the score
                for(i=0;i<*prizeCount;i++){
                        *playerScore=*playerScore+playerPrizes[i];
                }
                printf("%d\tinventory (%d items) ",*playerScore,*prizeCount);
                //Loop to print the Prizes
                for(i=0;i<*prizeCount;i++){
                        printf("%d ",playerPrizes[i]);
                }
                printf("\n");


                //Rolling the dices and restarting values in case goes over the limit
                unsigned roll_result = playerRoll();
                *playerPosition = (*playerPosition + roll_result)%(boardSize * 4 - 4);



                //Check the tile of the player Position
                position = tile(*playerPosition);

                //Depending on the tile run each of these functions
                if(position == 'G' && *prizeCount<10){
                    winGrandPrize(playerPrizes,prizeCount);
                    *prizeCount=*prizeCount+1;
                }
                else if(position == 'W' && *prizeCount<10){
                    winPrize(playerPrizes,prizeCount);
                    *prizeCount=*prizeCount+1;
                }
                else if(position == 'L' && *prizeCount>0){
                    loseItem(playerPrizes,prizeCount);
                    *prizeCount=*prizeCount-1;
                }
                else if(position == 'C'){
                    win = checkout(playerScore,playerPrizes,prizeCount);
                }
                else{
                    printf("nothing happens, go again.\n");
                }

              }

            }

//Get a Random # between inclusive range
/*int getRandom(int low, int high)
        {
            int result=0,lower=0,higher=0;
            if(low<high)
            {
                lower=low;
                higher=high+1; // this is done to include high in output.
            }else{
                lower=high+1;// this is done to include high in output.
                higher=low;
            }

            result = (rand()%(higher-lower))+lower;
            return result;
        }*/

int getRandom(int low, int high)
        {
            int result;
            result = low + rand() % (high +1 - low);
            return result;
        }

//Roll the dice in this case 1, 2 or 3 times
unsigned int playerRoll(){
    int each_roll;
    int roll = 0;
    int i = 0;
    int var = 0;
    int sum_of_random = 0;
    char trash;
    int input = 0;

    //Let the player roll 1-3 dice.

    printf("your turn, how many dice will you roll? ");

    while(var==0){

    input = scanf("%d", &roll);


    if(input != 1)
    {
        printf("Invalid input, try again: ");
        while ((trash = getchar()) != '\n' && trash != EOF); // Flush stdin
    }
    else if(input == 1){

        if (roll>=1 && roll<=3){
           var = 1;
           }
        else{
            printf("Invalid input, try again: ");
           }
    }
    }

    printf("You rolled: ");

    //For loop for each roll
    for(i=0;i<roll;i++){

        each_roll = getRandom(1,6);
        printf("%d ",each_roll);
        sum_of_random = sum_of_random + each_roll;

    }
    //Displaying the total amount of spaces
    printf("\nAdvancing %d spaces\n",sum_of_random);

    return sum_of_random;

}

//Getting a prize between 1 and 10 while the prizeCount is less than 10
void winPrize(int playerPrizes[], unsigned int *prizeCount){

    int prize = 0;
    prize = getRandom(10,100);
    playerPrizes[*prizeCount] = prize;
    printf("you won a prize of %d\n",playerPrizes[*prizeCount]);

}

//Getting a prize between 100 and 200 while the prizeCount is less than 10
void winGrandPrize(int playerPrizes[], unsigned int *prizeCount){

    int prize = 0;
    prize = getRandom(100,200);
    playerPrizes[*prizeCount] = prize;
    printf("you won a grand prize of %d\n",playerPrizes[*prizeCount]);


}

//Lose Item function
void loseItem(int playerPrizes[], unsigned int *prizeCount){
    int random_delete = 0;
    random_delete = getRandom(0,*prizeCount-1);
    int next = random_delete + 1;

    printf("randomly removing one prize\n");
    printf("price #%d removed\n",random_delete+1);

    //Run a loop that will push everything to the left
    for(;random_delete<*prizeCount;random_delete++){

        playerPrizes[random_delete]=playerPrizes[next];

    }



}

//Checkout function
int checkout(int *playerScore, int playerPrizes[], unsigned int *prizeCount){

    int win = 0; //false

    //If the player lands in C and the Score is >200 will win the game and return true which is 1
    if(*playerScore>=200){
        win = 1; //true
        printf("Your score was %d\n",*playerScore);
        printf("You won the game!\n");
        //Restarting prizes
        *prizeCount = 0;
        playerPrizes = 0;

    }


    return win;

}
