#include <stdio.h>
#include <stdlib.h>

#define DAYS 15
#define PRICE 0.35
#define DAILY 3

//I'm assuming that the dose on the exercise is a single take on the medicine
//The calculation should be that * 3 times a day * 15 days

void calculations(int, double*, double*);

int main()
{
    int age;
    double price_total;
    double medicine_total;

    printf("Medicine Calculations!\n");
    printf("Please enter the age of your child -> ");
    scanf("%d",&age);
    if(age<2)
        printf("Doctor's Discretion\n");
    else{
        calculations(age,&medicine_total,&price_total);
        printf("=====================================================\n");
        printf("The medicine should be taken %d times day for %d days\n",DAILY,DAYS);
        printf("The medicine price is %.2lf per ml\n",PRICE);
        printf("----------------------------------------------\n");
        printf("The total amount of medicine is --> %.2lf \(ml)\n",medicine_total);
        printf("The total price is --> $ %.2lf\n",price_total);
    }

    return 0;
}

void calculations(int age, double *medicine_total, double *price_total){

    if(age>=2 && age<=5)
        *medicine_total = 7.5 * DAYS * DAILY;
    else if(age>=6 && age<=11)
        *medicine_total = 10 * DAYS * DAILY;
    else
        *medicine_total = 15 * DAYS * DAILY;

    *price_total = *medicine_total * PRICE;


}
