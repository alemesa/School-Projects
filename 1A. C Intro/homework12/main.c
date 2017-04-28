//Programmer: Alejandro Mesa
//Program: Homework 12

#include <stdio.h>
#define SIZE 15

//Prototype
char password_check(char passwd[], char temp[]);

int main() {

//Declaring variables
  char passwd[SIZE]={0};
  char temp[SIZE]={0};

    char check = 0;

    //Saving both passwords
  printf("Maximum amount of characters is %d\n",SIZE);
  printf("Enter a password: ");
  scanf("%s",passwd);

  printf("Enter same password again: ");
  scanf("%s",temp);

  printf("=============\n");
  //Calling the check function
  check = password_check(passwd, temp);

  if(check == 'A'){
    printf("The passwords are the same\n");
    printf("The result is %c\n",check);
    }
  else {
        printf("First password was %s\n",passwd);
        printf("Second password was %s\n",temp);
    printf("Not the same passwords\n");
    printf("First character missing on the original password is %c\n",check);
    }

  return 0;

}

char password_check(char passwd[], char temp[]) {

  char return_value = 'A';
  int i;

  for (i=SIZE-1; i>0 ;i--) {

    if(passwd[i] != temp[i]){

      return_value = passwd[i];


    }

  }

  return return_value;

}
