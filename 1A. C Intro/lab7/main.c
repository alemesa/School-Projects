#include <stdio.h>
#include <stdlib.h>
#define SIZE 100 //Change the size of the array easily

//Programmer: Alejandro Mesa
//Program Name: lab7.c
//Purpose: Input information into arrays, validate the input and display it

//Function Prototypes
void clear_buffer(void);
int get_an_int(void);
double get_a_double(void);

//MAIN function
int main()
{
    //Variables for the loop that store in the array and the loop that prints the information
    int i,y;
    //Creating variables for my parallel arrays and temprary storing variables
    int barcode[SIZE] = {0};
    int store_barcode = 0;
    double price[SIZE] = {0};
    double store_price = 0;
    int quantity[SIZE] = {0};
    int store_quantity = 0;

    //Calculate the total at the end
    double total = 0;
    //Stop the count when the using exits the loop, that way I know the length of the array
    int count;

    printf("Grocery Store Inventory\n");
    printf("Press 0 while entering the Barcode # to exit\n");
    printf("=======================\n");
    //For loop to store informaiton on the arrays
    for(i=0;i<SIZE;i++){

        printf("Barcode  ->  ");
      //-PREVIOUS  scanf("%d",&store_barcode);
        store_barcode= get_an_int();
        //If to exit the loop
        if(store_barcode==0){
            //Store the length of the array
            count=i;
            //Flag to exit the loop
            i=SIZE;

        }
        //If that works like and exit if the barcode is 0 it will not enter here, otehrwise it will go in and proceed
        if(i<100){
            barcode[i]=store_barcode;
            printf("Price    ->  ");
            store_price = get_a_double();
            //scanf(" %lf",&store_price);

            price[i]=store_price;
            printf("Quantity ->  ");
            store_quantity = get_an_int();
           //-PREVIOUS scanf(" %d",&store_quantity);
            quantity[i]=store_quantity;
            printf("-----------\n");
            }


    }

    //Printing the results
    printf("\n\t\tGoods in Stock\n");
    printf("\t\t==============\n");
    printf("Barcode\tPrice\tQuantity\tValue\n");
    printf("------------------------------------------\n");

    //For to iterate on the array and print everything
    for(y=0; y<count; y++){

    //Calculate the total as the loops iterates
    total = total + (price[y]*quantity[y]);
    //Print the table
    printf("%d\t%.2lf\t%d\t\t%.2lf\n", barcode[y], price[y], quantity[y], price[y]*quantity[y]);

    }
    //Print the total
    printf("\t\t\t\t------\n");
    printf("Total values goods in stock\t%.2lf \n",total);



    return 0;
}

//Using the functions form the class to clear the buffer
void clear_buffer(void){
	while(getchar() != '\n') /* will read until finds a new line character */
	       ;       /* empty body of the while loop */
}
//And to validate the input
int get_an_int(void){
	int n,error = 0;


	do{
		if( 0 == scanf("%d", &n) || getchar() != '\n'){
			clear_buffer();
			printf("Error! Enter an integer -> ");
			error = 1;
		} else error = 0;
	}while( error );
	return n;
}

//To validate doubles too
double get_a_double(void){
	double m;
	int error = 0;


	do{
		if( 0 == scanf("%lf", &m) || getchar() != '\n'){
			clear_buffer();
			printf("Error! Enter an integer/double -> ");
			error = 1;
		} else error = 0;
	}while( error );
	return m;
}


