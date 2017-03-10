#include <stdio.h>
#include <stdlib.h>

int main()
{


    printf("Hello to sum and average of 10 integers!\n");
    calculations();

    return 0;



}

int calculations(void)
{
    int times = 1; //Loop variable

    int num = 0; //User Input
    int total=0; //Calculate the sum
    float average = 0; //Calculate the average


    printf("Enter any 10 integers\n");

    for(times=1;times<11;times++){
        printf("%d-> ",times);
        scanf("%d",&num);
        total = total + num;

    }

    average = (float)total / 10;

    printf("The sum of the integers is: %d\n", total);
    printf("The average of the integers is: %.2f\n\n",average);

    char again = ' '; //Asking to continue or not
    printf("Press any letter to continue\n");
    printf("Or 'no' 'N' to quit\n");
    scanf("%c",&again);

    while(again != 'N' || again != "no"){
        calculations();
    }


}
