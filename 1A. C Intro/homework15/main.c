//Programmer: Alejandro Mesa
//Program: Homework 15
//Modification of fun24a
#include <stdio.h>
#define SIZE 3

int get_quantity(int prod[], int quant[], float price[]);
int search_prod(int search,int prod[], int quant[]);

int main(){

    //Declaring all variables
	int product_num[SIZE] = {0};
	int in_stock[SIZE] = {0};
	float price[SIZE] = {0};
	float total_price = 0;
	int index = 0;
	int total = 0;
	int query = 0;
	int search = 0;

	total = get_quantity(product_num, in_stock, price);

	printf("\nPRODUCT NUMBER\t\tQUANTITY\t\tPRICE\n\n");

	for( index = SIZE-1; index >= 0; index --){
		printf("%9d%20d%20.2f\n", product_num[index], in_stock[index], price[index]);

        //Calculate the price when quantity is not 0
        if(in_stock[index]!=0){
            total_price=total_price+(price[index]*in_stock[index]);
        }

	}
	printf("\nTotal: %d\n", total);
	printf("Average Price %.2f\n", total_price/total);

	printf("=================\n");
	printf("Search System\n ");
	printf("Enter the product #: ");
	scanf(" %d",&search);

	//Call of the search function
	query = search_prod(search , product_num, in_stock);
	if(query==0)
        printf("Not Found\n");
    else
        printf("Found\n");



    return 0;

}

//Get quantity function
int get_quantity(int prod[], int quant[], float price[]){
	int index, total = 0;

	for( index = 0; index < SIZE; index ++){
			prod[index] = 1000 + index;
			printf("Enter quantity of product #%d left in stock:",prod[index]);
			scanf("%d", &quant[index]);
			printf("Enter the price of product #%d:",prod[index]);
			scanf("%f",&price[index]);
			total += quant[index];
	}
	return total;
}

//Search function
int search_prod(int search,int prod[], int quant[]){

    int found = 0;
    int index;
    for( index = 0; index < SIZE; index ++){
			if(search == prod[index]){

                if(quant[index]>0){

                    found = 1;

                }

			}

	}


     return found;

}
