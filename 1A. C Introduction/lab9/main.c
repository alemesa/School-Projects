// Fraction Simplifier
// w9.c
// Alejandro Mesa Suarez

#include <stdio.h>
// Simplify FUnction handling negative values, positive values and 0 using Structures and pointers

//Structure Fraction

struct Fraction{
    int numerator;     //Holds numerator
    int denominator;   //Holds denominator
    int k;             //Flag for numerator negative values
    int j;             //Flag for denominator negative values
};

//Prototypes
void enter(struct Fraction* f);
void simplify(struct Fraction* f);
void display(const struct Fraction* f);

 int main(void)
 {
     //Allocate memory for f that will hold 2 integers
         struct Fraction f;

         printf("Fraction Simplifier\n");
         printf("===================\n");

         enter(&f);
         simplify(&f);
         display(&f);

         return 0;
 }

 void enter(struct Fraction* f){

    f->k=0;
    f->j=0;

    //Getting user input
    printf("Enter numerator:    ");
    scanf("%d",&f->numerator);
    printf("Enter denominator:  ");
    scanf("%d",&f->denominator);
    printf("%d / %d = ",f->numerator,f->denominator);

    if(f->numerator<0){

        f->numerator=-f->numerator;
        f->k=1;
    }
    if(f->denominator<0){

        f->denominator=-f->denominator;
        f->j=1;
    }


 }

 void simplify(struct Fraction* f){

 int i; //For loop

    //Divide the numerator and denominator starting by 2 until the remainder is 0
    for(i=2;i<=f->numerator;i++){
        //When the remainder is 0 keep the same i and try again
        if(f->numerator%i==0 && f->denominator%i==0){

            f->numerator=f->numerator/i;
            f->denominator=f->denominator/i;
            i = i-1; //To keep trying the same divisor
        }


    }



 }

void display(const struct Fraction* f){

 if(f->numerator==0){
        printf("0");
    }
else if(f->denominator==0){
        printf("Cannot by divide by 0");
    }
else{
        if(f->k==0 && f->j==0){

           printf("%d / %d ",f->numerator,f->denominator);
        }
        if(f->k==1 && f->j==0){

           printf("-%d / %d ",f->numerator,f->denominator);
        }
        if(f->k==0 && f->j==1){

           printf("%d / -%d ",f->numerator,f->denominator);
        }
        if(f->k==1 && f->j==1){

           printf("-%d / -%d = %d / %d",f->numerator,f->denominator,f->numerator,f->denominator);
        }

}

}








