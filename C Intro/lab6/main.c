//Programmer: Alejandro Mesa
//Project: Lab 6 -- Create a game of dice using the random functions

#include <stdio.h>
#include <stdlib.h>

//Clear the buffer function
void clear_buffer(void){
	while(getchar() != '\n');
}

//Main Function
int main()
{
    //Input of the user
    int guess;
    //Limits of the dice throw 1 and 6 inlcusive
    int a = 1;
    int b = 6;
    //Variables to store the rand numbers + i for the for loop
    int m,n,i;
    //Flag to exit the do-while loop
    int flag;

    //Random NUmber Generator
    srand(time(NULL));
    printf("Welcome!!!\n");
    printf("Game of Dice\n");
    printf("============\n");

    do{
    flag = 0;
    printf("Enter total sought : ");
    scanf("%d",&guess);
        //Validate for negative numbers , 1 and bigger than 12
        if(guess>12 || guess<=1){
            printf("--> %d Invalid input! Try Again! **\n",guess);
            printf("--> Valid Input is a number between %d and %d\n",a*2,b*2);
            flag = 1;
            clear_buffer();
        }
    }
    while(flag==1);

    //For loop that finishes when the sum of both ranom
    //numbers is equal to
    for(i=1; n+m!=guess ;i++){

    //Store two numbers between 1 and 6 using rand function
        m=a + rand() % (b+1-a);
        n=a + rand() % (b+1-a);

        printf("Result of throw %d : %d + %d",i,m,n);


    }
    printf("You got your total in %d throws\n",i-1);
    return 0;
}
