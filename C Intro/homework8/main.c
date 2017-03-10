#include <stdio.h> //Main Library
#include <ctype.h> //Upper and Lower Library

//Defining the constants
#define PREMIUM 22.25
#define MIDDLE 19.75
#define LOW 17.50

int main() {
    int days;

    printf("\t|-----------------------------|\n");
    printf("\t|  Welcome to the Ghost Hotel |\n");
    printf("\t|-----------------------------|\n\n");

    printf("\tAmount of days -> ");
    scanf("%d", &days);

    char select;
    int
    var = 0;

    //VALIDATE THE RATES INPUT
    do {
        printf("\tOur Rates are:\n");

        printf("\tA-  Premium Rate: $%.2f |\n", PREMIUM);
        printf("\tB-  Middle Rate: $%.2f  |\n", MIDDLE);
        printf("\tC-  Low Rate: $%.2f     |\n", LOW);
        printf("\tQ-  EXIT the Program     |\n");
        printf("\tSelect your rate -> ");

        scanf(" %c", & select);
        select = toupper(select);
        printf("\n");
        if (select == 'A' || select == 'B' || select == 'C' || select == 'Q') {
            var = 1;
        } else {
            printf("Invalid choice!\n");
        }

    } while (var == 0);

    //Find the price depending on the choice

    switch (select) {
    case 'A':
        printf("\tThe total will be %.2f\n", days * PREMIUM);
        break;
    case 'B':
        printf("\tThe total will be %.2f\n", days * MIDDLE);
        break;
    case 'C':
        printf("\tThe total will be %.2f\n", days * LOW);
        break;
    case 'Q':
        printf("\tBye Bye\n");
        break;
    }

    return 0;
}
