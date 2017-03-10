#include <stdio.h>
#include <stdlib.h>

//Programmer: Alejandro Mesa
//Program: Homework 14

int main()
{
    //Declaring variables
    FILE *fp;
    char first_name[31];
    char last_name[31];
    int number;
    int department;

    //Opening file with error checking and appending option
    fp = fopen("work_people.txt","a");
    if (fp){

        //Asking input
        printf("First Name: ");
        gets(first_name);
        printf("Last Name: ");
        gets(last_name);

        //Keep it inside the range
        do{

            printf("Employee Number(1000-6000): ");
            scanf(" %d",&number);
        }while(number>6000 || number<1000);
        //Keep it inside the range
        do{

            printf("Department Number(1-10): ");
            scanf(" %d",&department);
        }while(department>10 || department<1);

        //Printing to the file and closing it
        fprintf(fp,"%s %s #:%d Dep:%d\n",first_name,last_name,number,department);
        fclose(fp);
    }else
        printf("Cannot open the file\n");


    return 0;
}
