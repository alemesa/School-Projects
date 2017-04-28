#include <stdio.h>
#include <stdlib.h>

int calculation(float principal, float rate, int years){

    float result = 0;

    for (years;years>0;years--){
        result = result + ((principal * (1 + rate)) * (principal * (1 + rate)));
    }

    return result;
}


int main(void)
{


    float principal, rate, answer;
    int years;

    printf("Investment Calculator\n");
    printf("=====================\n");
    printf("Principal\t:");
    scanf("%f",&principal);
    printf("Annual Rate\t:");
    scanf("%f",&rate);
    printf("No of Years\t:");
    scanf("%d\n",&years);

    answer = calculation(principal, rate, years);
    printf("The future value is $%.2f\n",answer);


}

