#include <stdio.h>
#include <stdlib.h>

char convert (char); //Prototype

int main()
{

    char letter,converted;

    printf("Conversion tool\n");
    printf("Enter a character:");
    scanf("%c",&letter);
    converted = convert(letter);
    printf("Your letter is --> %c\n",letter);
    printf("The converted letter is --> %c\n",converted);


}

char convert(char letter){
    //Simple Conversion suing ASCI Code where the difference between uppercase and lowercase is 32
    char result;
    if(letter>=65&&letter<=90)
        result=letter+32;
    else
        result=letter-32;
    return result;

}
