#include <stdio.h>
#include <stdlib.h>

void simplify(int*, int*);

int main()
{
    char again;

    do{

            //Declaring variables
    int numerator, denominator;
            //Variables to handle negative values
    int k = 0;
    int j = 0;
            //Getting user input
    printf("\n|Fraction Simplifier!\n");
    printf("|===================\n");
    printf("|Enter numerator:");
    scanf("%d",&numerator);
    printf("|Enter denominator:");
    scanf("%d",&denominator);
    printf("|%d / %d = ",numerator,denominator);


    //Convert negative values to positive
    if(numerator<0){

        numerator=-numerator;
        k=1;
    }
    if(denominator<0){

        denominator=-denominator;
        j=1;
    }

    //If else loops in case numerator or denominator is 0, if not conitnue with the program
    if(numerator==0){
        printf("0");
    }
    else if(denominator==0){
        printf("Cannot by divide by 0");
    }
    else{
        //Call simplify function
    simplify(&numerator,&denominator);
        //If-else statements to handle negative numbers
        if(k==0 && j==0){

           printf("%d / %d ",numerator,denominator);
        }
        if(k==1 && j==0){

           printf("-%d / %d ",numerator,denominator);
        }
        if(k==0 && j==1){

           printf("%d / -%d ",numerator,denominator);
        }
        if(k==1 && j==1){

           printf("-%d / -%d = %d / %d",numerator,denominator,numerator,denominator);
        }

    }
    printf("\n|Press any letter to continue or Q to exit ->");
    scanf(" %c",&again);
    again = toupper(again);
    } while(again != 'Q');

    printf("|Thanks for using the program");
    return 0;

}

void simplify(int *numerator, int *denominator){

    int i; //For loop

    //Divide the numerator and denominator starting by 2 until the remainder is 0
    for(i=2;i<=*numerator;i++){
        //When the remainder is 0 keep the same i and try again
        if(*numerator%i==0 && *denominator%i==0){

            *numerator=*numerator/i;
            *denominator=*denominator/i;
            i = i-1; //To keep trying the same divisor
        }


    }
    numerator = *numerator;
    denominator = *denominator;

}




