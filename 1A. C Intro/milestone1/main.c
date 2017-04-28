//I declare that the attached assignment is wholly my own work in accordance with
//Seneca Academic Policy. No part of this assignment has been copied manually or
//electronically from any other source (including web sites) or distributed to
//other students.
//Name : Alejandro Mesa
//Student ID : 038515151

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//PROTOTYPE FUNCTIONS
char getTileType(int);
void displayBoard(int) ;

int main()
{
    /*int size;
    printf("--Program Start\n");
    printf("Enter board size -> ");
    scanf("%d",&size);
    displayBoard(size);
    printf("--Program End--\n");
    return 0;*/


    int s = 1;
    printf("--Program Start\n");
    if (getTileType(153) != 'W') printf("153 should return W");
    else if (getTileType(65) != 'L') printf("65 should return L");
    else if (getTileType(49) != 'G') printf("49 should return G");
    else if (getTileType(0) != 'C') printf("0 should return C");
    else if (getTileType(105) != 'G') printf("105 should be G");
    else if (getTileType(79) != ' ') printf("79 should be space");
    else {
        printf("getTileType test passed!\nEnter board size: ");
        scanf("%d", &s);
    displayBoard(s);
    printf("--Program End--\n");
        }
    return 0;
}



char getTileType (int index){
    char tile = ' ';
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
    return tile;

}

void displayBoard(int size){
     int i;
     int middle_space = size-2; //this is the middle space on the row on the center

     int first_left = size-1+(size-1)+(size-1)+(size-2); //this is the first number on the left after finishing first line (left column)
     int first_right = size; //this is the first number on the right after finishing top row (right column)

     int rows = size-2; //this is the rows not inlcuding top row or bottom row
     int first_last_row = size + (size-1) + (size-1); //this is the first number of the last row which will be regressive on the loop

     //If size is 1
    if(size==1){
        printf(" ___ ");
        printf("\n");
        printf("| %c |",getTileType(0));

        printf("\n");

        printf("|___|");
        printf("\n");


        }
    //Sizes > 1
    else{
     ////FIRST ROW PRINTING
     //Printing top part
     for(i=0;i<size;i++){

        printf(" ___ ");

     }
     printf("\n");
     //Printing mid part
     for(i=0;i<size;i++){

        printf("| %c |",getTileType(i));

     }
     printf("\n");
     //Printing bottom part
     for(i=0;i<size;i++){

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
        printf("| %c |",getTileType(first_left));
        for(y=0;y<middle_space;y++){
                printf("     ");
        }
        printf("| %c |",getTileType(first_right));
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
     for(i=first_last_row-1;i>(size+(size-2)-1);i--){

        printf(" ___ ");

     }
     printf("\n");
     //Printing mid part
     for(i=first_last_row-1;i>(size+(size-2)-1);i--){

        printf("| %c |",getTileType(i));

     }
     printf("\n");
     //Printing bottom part
     for(i=first_last_row-1;i>(size+(size-2)-1);i--){

        printf("|___|");

     }
     printf("\n");



     }

}







