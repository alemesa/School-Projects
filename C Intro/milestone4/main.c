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

#define LOW 5 //Boardsize (inclusive)
#define HIGH 15 //Boardsize (inclusive)

//Structure Player

struct Player{

    char playerName;
    int playerScore;
    int prizeCount;
    int playerPosition;
    int playerPrizes[10];
    char name[35];

};

//PROTOTYPES
char getTileType(unsigned int index, struct Player players[], unsigned int playerCount, unsigned int totalPlayers);
void displayBoard(unsigned int boardSize, struct Player players[], unsigned int playerCount, unsigned int totalPlayers);
void initPlayer(struct Player *player);
void playGame(unsigned int boardSize, struct Player players[], unsigned int totalPlayers);

void winPrize(struct Player *player); //
void winGrandPrize(struct Player *player); //
int loseItem(struct Player *player); //
int checkout(struct Player *player); //

int getValidInteger(int low, int high);
char getValidCharacter(char low, char high);
int getRandom(int low, int high);
unsigned int playerRoll();

//MILESTONE4 PROTOTYPES
void displayInstructions(void);
void addToLeaderboard (int game, struct Player* winner);
void displayHighestScore (void);

char tile(struct Player players[],unsigned int playerCount);

//MAIN PROGRAM
int main(){


    struct Player players[7]; //array of struct 8 players
    //Variables
    char menu_choice;
    int flag = 0;

    //srand(time(NULL)); //Rand

    unsigned int totalPlayers = 0;
    unsigned int boardSize = 0;

    int i;

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


        printf("Enter number of players (1-8): ");
        totalPlayers = getValidInteger(1,8); //Get #s players

        //Get playerName(s) and initialize each player
        for(i=0;i<totalPlayers;i++){


            initPlayer(&players[i]);


        }

        printf("Enter board size: ");
        boardSize = getValidInteger(LOW,HIGH); //Get BoardSize
        playGame(boardSize, players, totalPlayers); //Initialize the game

    }
    //If High Score selected

    if(menu_choice=='s'){


    int player_number = 0;
    int high_score = 0;
    char high_player = ' ';


    printf("__\n");
    printf("  \\_______\n");
    printf("   \\++++++|\n");
    printf("    \\=====|\n");
    printf("    0---  0\n\n");



    for(i=0;i<totalPlayers;i++){


        if(players[i].playerScore > high_score){

            high_score = players[i].playerScore;
            high_player = players[i].playerName;
            player_number = i;

        }

    }

        printf("HI SCORE: %d\tPlayer Name: %c\n",high_score,high_player);



        addToLeaderboard(1,&players[player_number]);
        displayHighestScore();



    }
    //If Instructions selected
    if(menu_choice=='r'){

        displayInstructions();

    }
    //If Quit selected
    if(menu_choice=='q'){
        printf("This game is much more fun than bash...\n");
    }

}while(menu_choice!='q');

    return 0;

}

//FUNCTIONS
//Get the Tile type depending on playerPosition and index


char getTileType(unsigned int index, struct Player players[], unsigned int playerCount, unsigned int total_players){
    char tile;
    int z;



    if(index==0)
        tile='C';
    else if(index%7==0)
        tile='G';
    else if(index%5==0)
        tile='L';
    else if(index%3==0)
        tile='W';
    else
        tile = ' ';

    for(z=0;z<total_players;z++){
        if(index==players[z].playerPosition){
        tile=players[z].playerName;
    }
    }

    if(index==players[playerCount].playerPosition){
        tile=players[playerCount].playerName;
    }
    return tile;

}

//Get the tile type function to check  playerPosition letter without passing all the other arguments from the previous function
char tile(struct Player players[],unsigned int playerCount){

    char tile;
    if(players[playerCount].playerPosition==0)
        tile='C';
    else if(players[playerCount].playerPosition%7==0)
        tile='G';
    else if(players[playerCount].playerPosition%5==0)
        tile='L';
    else if(players[playerCount].playerPosition%3==0)
        tile='W';
    else
        tile = ' ';

    return tile;

}

//FUNCTIONS USING STRUCT
//======================
//DisplayBoard - Algorithms to print the board with player position
void displayBoard(unsigned int boardSize, struct Player players[], unsigned int playerCount, unsigned int total_players){
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
        printf("| %c |",getTileType(0,players,playerCount,total_players));

        printf("\n");

        printf("|___|");
        printf("\n");


        }//Sizes > 1
    else{
     ////FIRST ROW PRINTING
     //Printing top part
     for(i=0;i<boardSize;i++){

        printf(" ___ ");

     }
     printf("\n");
     //Printing mid part
     for(i=0;i<boardSize;i++){

        printf("| %c |",getTileType(i,players,playerCount,total_players));

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
        printf("| %c |",getTileType(first_left,players,playerCount,total_players));
        for(y=0;y<middle_space;y++){
                printf("     ");
        }
        printf("| %c |",getTileType(first_right,players,playerCount,total_players));
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

        printf("| %c |",getTileType(i,players,playerCount,total_players));

     }
     printf("\n");
     //Printing bottom part
     for(i=first_last_row-1;i>(boardSize+(boardSize-2)-1);i--){

        printf("|___|");

     }
     printf("\n");



     }

}

//Initialize player
void initPlayer(struct Player* player){

    //Initiliaze player stats
    player->playerScore = 0;
    player->playerPrizes[7] = 0;
    player->prizeCount = 0;
    player->playerPosition = -1;



    player->playerName = getValidCharacter(33,126);
    printf("Enter player name: ");
    scanf("%s",player->name);

    //Values like ! " # $ % & ' ( ) * + , - . / @   ASCI Codes


}

//Play Game
void playGame(unsigned int boardSize, struct Player players[], unsigned int totalPlayers){

            int iterate; //player rotation
            int z = 0;
            int win = 0; //this will end the game
            char position;
            int current_position;
            int trick=0;

            //Iterate through every player
            for(iterate=0;iterate<totalPlayers && win==0;){

                //Trick to avoid error at the beginning when every player is on position 0
                //I Initialized everything first as -1 , and then start as 0 as the numbers enter the PlayGame
                if(trick<totalPlayers){

                    players[iterate].playerPosition = 0;

                    trick++;

                }

                //Display the board including the player’s position on the board
                displayBoard(boardSize,players,iterate,totalPlayers);

                //Rolling the dices
                printf("%s's (%c)'s turn ",players[iterate].name,players[iterate].playerName);
                //Player get a new position
                players[iterate].playerPosition = (players[iterate].playerPosition + playerRoll()) % (boardSize * 4 - 4);



                //Check if someone else is in that position
                int count;

                //Do-While
                do{

                count = 0;
                current_position = iterate; //the actual number
                z = iterate; //the number that will rotate to check every element

                //This part of the game is tricky
                //I'm running a loop that grabs the iteration player as the starting point and then loop to the end and back
                //until it reaches the same spot
                //Why? To check if any other player is
                for(; z<=(totalPlayers-1) && count<totalPlayers-1; z++){
                    count++;
                    //Restart count when it reaches the end
                    if(z==totalPlayers-1){
                        z=-1;
                    }


                    int next_position = z + 1;

                    //Next position will be z and it will compare with every player in the array of players
                    //If two players ont he same spot it could be steal or just go back
                    if(players[current_position].playerPosition == players[next_position].playerPosition){

                        //Run steal a price
                        //Not able to steal when the prizeCount is full or when the enemy doesn't have prizes
                        if(players[next_position].prizeCount == 0 || players[current_position].prizeCount == 10){
                            printf("You were unable to steal from %c!\n",players[next_position].playerName);

                            //Going back one step
                            players[current_position].playerPosition = players[current_position].playerPosition - 1;

                            //In case the position goes beyond the boardsize (amount of tiles)
                            if(players[current_position].playerPosition<0){
                                players[current_position].playerPosition=players[current_position].playerPosition+(4*boardSize)-4;
                            }

                            //This will make exit the if looop and go back to the while to check if another player is on your new position
                            count = totalPlayers;

                        }//Steal if the price count is bigger than 0
                        else if(players[next_position].prizeCount > 0){
                            //Get the # of the prize to steal
                            int number_to_steal = 0;
                            int prize_to_steal = 0;
                            number_to_steal = getRandom(0,players[next_position].prizeCount-1);
                            //Getting the amount of the prize
                            prize_to_steal = players[next_position].playerPrizes[number_to_steal];
                            //Adding the prize to the current player
                            players[current_position].playerPrizes[players[current_position].prizeCount] = prize_to_steal;

                            //Moving every prize to the left
                            int next = number_to_steal + 1;

                            for(;number_to_steal<(players[next_position].prizeCount);number_to_steal++){

                                players[next_position].playerPrizes[number_to_steal]=players[next_position].playerPrizes[next];

                            }

                            //Increasing and decresing #s for both
                            players[next_position].prizeCount = players[next_position].prizeCount - 1;
                            players[current_position].prizeCount = players[current_position].prizeCount + 1;

                            printf("You stole a prize from %c!\n",players[next_position].playerName);
                            //Going back 1 step


                            players[current_position].playerPosition = players[current_position].playerPosition - 1;

                            if(players[current_position].playerPosition<0){
                                players[current_position].playerPosition=players[current_position].playerPosition+( 4 * boardSize) - 4;
                            }

                            count = totalPlayers;

                        }

                    }
                }

                }while(count!=totalPlayers-1);

                //The tile is empty so let's check what's there and execute every funciton

                        //Check the tile of the player Position
                        position = tile(players,iterate);

                        //Depending on the tile run each of these functions
                        if(position == 'G' && (players[iterate].prizeCount)<10){
                            winGrandPrize(&players[iterate]);
                            players[iterate].prizeCount=players[iterate].prizeCount + 1;
                        }
                        else if(position == 'W' && (players[iterate].prizeCount)<10){
                            winPrize(&players[iterate]);
                            players[iterate].prizeCount=players[iterate].prizeCount + 1;
                        }
                        else if(position == 'L' && (players[iterate].prizeCount)>0){
                            loseItem(&players[iterate]);
                            players[iterate].prizeCount=players[iterate].prizeCount - 1;
                        }
                        else if(position == 'L' && (players[iterate].prizeCount)==0){
                            printf("You got nothing to lose\n");
                        }
                        else if(position == 'C'){
                            win = checkout(&players[iterate]);

                        }
                        else{
                            printf("You do nothing.\n");
                        }


                    iterate++;

                //Keep the players rotation over and over
                if(iterate==totalPlayers){
                    iterate=0;
                }

        }

}

//Getting a prize between 1 and 10 while the prizeCount is less than 10
void winPrize(struct Player* player){

    int prize = 0;
    prize = getRandom(10,100);
    player->playerPrizes[player->prizeCount] = prize;
    printf("you won a prize of %d\n",player->playerPrizes[player->prizeCount]);

}

//Getting a prize between 100 and 200 while the prizeCount is less than 10
void winGrandPrize(struct Player* player){

    int prize = 0;
    prize = getRandom(100,200);
    player->playerPrizes[player->prizeCount] = prize;
    printf("you won a grand prize of %d\n",player->playerPrizes[player->prizeCount]);

}

//Lose Item function
int loseItem(struct Player* player){
    int random_delete = 0;
    random_delete = getRandom(0,(player->prizeCount)-1);
    int next = random_delete + 1;

    //Randomly select a position on the array to be eliminated
    printf("randomly removing one prize\n");
    printf("price #%d removed\n",random_delete+1);

    //Run a loop that will push everything to the left
    for(;random_delete<(player->prizeCount);random_delete++){

        player->playerPrizes[random_delete]=player->playerPrizes[next];

    }


    return 0;
}

//Checkout function
int checkout(struct Player* player){
    int i = 0;
    int win; //false
    player->playerScore=0;

    //Loop to count the score
    for(i=0;i<player->prizeCount;i++){
        player->playerScore=player->playerScore+player->playerPrizes[i];
    }

    //If the player lands in C and the Score is >200 will win the game and return true which is 1
    if(player->playerScore>=200){
        win = 1; //true
        printf("Your score was %d\n",(player->playerScore));
        printf("You won the game!\n");


    }
    else{
        printf("You checkedout for %d\n",(player->playerScore));
        win = 0;
    }
        //Restarting prizes
        player->prizeCount = 0;
        //player->playerPrizes[10] = 0;
        for (i = 0; i < 10; ++i)
            player->playerPrizes[i] = 0;

    return win;

}


//OTHER FUNCTIONS
//===============
//Get a Valid Integer between limits
int getValidInteger(int low, int high){

    int choice;
    int var = 0;


    do{

       scanf(" %d",&choice);
       if ( choice >= low  && choice <= high ){
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
       if (choice > low  && choice <= high){
	   var = 1;
       }
       else{
	    printf("Invalid choice!\n");
       }

    } while( var == 0 );

    return choice;
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

    printf(", how many dice will you roll? ");

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
    printf("\n");

    return sum_of_random;

}

//Get a Random # between inclusive range
int getRandom(int low, int high){

    int result;
    result = low + rand() % (high +1 - low);
    return result;

}



//Milestone 4 Functions
void displayInstructions(void){
    printf("*******************\n");
    printf("* Full Game Rules *\n");
    printf("*******************\n");
    printf("Up to 8 players compete to be the first to obtain $500\n");
    printf("Game takes place on a square board with 5 tile types\n");
    printf("->Empty Tile: No effect\n");
    printf("->Win Tile (W): Win a random prize\n");
    printf("->Lose Tile (L): Lose a random prize\n");
    printf("->Grand Prize Tile (G): Win a grand prize\n");
    printf("->Checkout Tile (C): Sells all your prizes for cash\n");
    printf("Players can roll 1 - 3 dice to determine how many tiles they move each turn\n");
    printf("If a player lands on the same tile as another player, that player steals a prize and moves 1 tile back\n\n");

}

void addToLeaderboard (int game, struct Player* winner){
    FILE *fp;
    int lines = 0;
    char ch;
    //Getting the amount of lines on the file to add the game #
    fp = fopen("Leaderboard.dat","w+");
    if(fp){

    while(!feof(fp))
        {
          ch = fgetc(fp);
          if(ch == '\n')
          {
            lines++;
          }
        }

    fclose(fp);
    }else
        printf("Cannot open the file\n");

    //Writing to the file
    fp = fopen("Leaderboard.dat","a");
    if(fp){


    fprintf(fp,"GAME:%d %s (%c)-%d\n",lines+1,winner->name,winner->playerName,winner->playerScore);
    fclose(fp);


    }else
        printf("Cannot open the file\n");
}

void displayHighestScore(void){

    char garbage[30];

    char name[30];
    char symbol;
    int score = 0;
    //
    char fname[30];
    char fsymbol;
    int fscore = 0;

    int i;

    FILE *fp;
    fp = fopen("Leaderboard.dat","r");

    //Read the file and loop through every data and store the values of the high score
    if(fp == NULL){
        printf("Cannot open the file\n");
    }
    else{
    while(!feof(fp)){

    fscanf(fp,"%[^ ] %[^(](%c)-%d\n",garbage,name,&symbol,&score);
        if(score>=fscore){

            for(i=0;i<30;i++){
                fname[i] = name[i];
            }
            fsymbol = symbol;
            fscore = score;
        }
    }

    //Printing the high score player
    printf("*****************************\n");
    printf("Player with the Highest Score\n");
    printf("*****************************\n");
    printf("Player Name  ID   Score\t\n");
    printf("%-13s(%c)   $%d\n",fname,fsymbol,fscore);
    fclose(fp);
}

}


