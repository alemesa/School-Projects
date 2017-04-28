#include <stdio.h>
#include <string.h>
#define SIZE 100 //CONSTANT VARIABLE, EASY CHANGEABLE

//Programmer: Alejandro Mesa
//Project: Lab8

//Count words in C
//Program is made in a way that will count the correct amount of words even
//if the user enters empty spaces at the beginning
//or if the user enters more that 1 consecutive empty spaces

//Prototype function
int wordCount(char []);

//MAIN function
int main()
{
    //Create an array to store every letter
    char text[SIZE];
    text[0]='\0'; //Initialize first element to check if the user do not enter anything
    int count;
    //Ask for input
    printf("Word Counter\n");
    printf("============\n");
    printf("Text to be analyzed -> ");
    //Store every letter in an array
    scanf("%[^\n]",&text);

    //In case nothing is entered
    if (text[0] == '\0'){
        printf("Amount of words -> 0");
    }
    //Continue with the program
    else{
        count = wordCount(text);
        printf("\nAmount of words -> %d",count);
    }
    return 0;
}

//Word count function
int wordCount(char text[]){
    int state = 0;     //state = 1 means that the previous letter was acceptable
                           //state = 0 means that the previous letter was not acceptable was either a space or anything else
                           //this is a flag to avoid counting consecutive empty space

    int i; //Loop variable
    int count = 0; //Count variable which will be returned at the end of the function
    printf("Text entered  -> ");

    //Start the loop
    for(i=0;i<strlen(text);i++){
        //Print every letter on the array

        printf("%c",text[i]);
        if(text[i]=='\n'||text[i]=='\t'||text[i]=='\f'||text[i]=='\v'||text[i]==' '||text[i]=='\c'||text[i]==','){
            //First time will increase add +1 to count but if there is a consecutive ' ' it will not
            //increase because it will not enter the if because state is set to 0, and it will be restarted
            //when an acceptable variable is entered


            if(state==1){
                count++;
            }
            state=0;
        }

       //Restart the state variable to 1 because is an acceptable character
        else{


            state=1;
        }



    }

    if(state==0){
        count--;
    }





    return count+1;
}
