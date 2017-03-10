#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Programmer: Alejandro Mesa
//Program: Homework 13

#define SIZE 31

//PROTOTYPES
int find_name(char names[][SIZE],char find[31]);
void show_names(char names[][SIZE]);

//MAIN FUNCTION
int main()
{
    //Declaring variables and an array of 10 super heroes
    char names[10][SIZE]={"Iron Man","Captain America","Thor","Vision","Spider-Man","Hulk","Hawkeye","Ant-Man","Black Widow","Arta Kogan"};
    char find[SIZE];
    int n;
    show_names(names);

    //Getting name to search
    printf("Enter a name to search: ");
    fgets(find,SIZE,stdin);

    //Remove trailing newline, if there.
    if ((strlen(find)>0) && (find[strlen (find) - 1] == '\n'))
        find[strlen (find) - 1] = '\0';

    n = find_name(names,find);
    if(n==1)
        printf("The name exists. Result = %d",n);
    else
        printf("Name doesn't exists. Result = %d",n);

    return 0;
}

//FIND NAME FUNCTION
int find_name(char names[][SIZE], char find[SIZE]){


    int result = 0;
    int i;

    //Running strcmp to compare arrays
    for (i=0;i<10;i++){
            if( strcmp(names[i],find) == 0){
                result=1;
            }
    }
    return result;

}

//VOID FUNCTION TO PRINT ALL THE NAMES
void show_names(char names[][SIZE]){

    int i;

    for (i=0;i<10;i++){

            printf("* %s ",names[i]);
            //Create an space every 5 names
            if((i+1)%5==0){
                printf("\n");
            }

    }
    printf("\n============\n");
}
