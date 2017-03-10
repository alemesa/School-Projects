//Programmer: Alejandro Mesa
//Project: Lab 10
//Purpose: Create a conversion tool that interacts with files


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 256

int main()
{
    //Files Pointers
    FILE * from;
    FILE * to;
    char singleLine[MAX]; //hold single lines of the file
    char choice; //hold choice: uppercase or lowercase
    int flag = 0; //flag to keep the loop running while choosing upper or lowercase
    int i;
    //Variables to hold the name of the files
    char original[30];
    char updated[30];



    printf("Change Case\n");
    printf("===========\n");

     do{
        printf("Case (U for upper, L for lower) : ");
        scanf(" %c",&choice);
        choice = toupper(choice);
        if(choice=='U'|| choice=='L')
            flag=1;
    }while(flag==0);

    //Getting Original File
    printf("Name of the original file : ");
    scanf("%s",original);
    from = fopen(original,"r");
    //Checking if exists
    if(from==NULL)
	{
		printf("\"%s\" File NOT FOUND!",original);
		exit(1);
	}

    //Getting Updated File
    printf("Name of the updated file  : ");
    scanf("%s",updated);
    to = fopen(updated,"w");
    //Checking if exists
    if(to==NULL)
	{
		printf("\"%s\" File NOT FOUND!",updated);
		exit(1);
	}

    //Copying data from one to the other one

    printf("\nResults of the conversion\n");
    printf("=========================\n");

    while(!feof(from)){
        fgets(singleLine,MAX,from);


        //Converting to uppercase
        if(choice=='U'){
        for(i=0;i<=strlen(singleLine);i++){
            singleLine[i]=toupper(singleLine[i]);

        }
        }
        //Converting to lowercase
        if(choice=='L'){
        for(i=0;i<=strlen(singleLine);i++){
            singleLine[i]=tolower(singleLine[i]);

        }
        }
        //Printing every singleLine to the updated file
        fprintf(to,singleLine);

        //Printing the results to the screen
        printf(singleLine);
    }


   //Close files
   fclose(to);
   fclose(from);
    printf("Text has been updated and stored in \"%s\"",updated);

    return 0;
}
