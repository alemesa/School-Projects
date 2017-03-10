#include <stdio.h>
#include <stdlib.h>

//Programmer: Alejandro Mesa
//Project: Homework 11 --  Write a program that will calculate and display the average, highest, and lowest
//                         mark in the class of 40 students


#define CLASS 40 //Change the value easy

int main()
{
    //Create both arrays
    int studentID[CLASS];
    int student_score[CLASS];
    //Initialise the Random Number Generator
    srand(time(NULL));

    // In this case the range for students will 100000-100400, incrementing 10 for every student
    int initial_student = 100000; //Assign student number
    int increment = 10;  // Increment of the student number

    //Declare the variables
    int highest,lowest,highest_position,lowest_position;
    double total;

    int i;

    //For the purpose of this homework I'm going to generate random scores from 0 to 100 for the students
    //For loop to generate random scores and store it on the array
    for(i=0;i<CLASS;i++){

        int range = 100;
        int min = 0;
        int random_number = 0;


        random_number = rand() % range + min;

        student_score[i]= random_number;

    }

    //For loop to assign numbers to the students
    for(i=0;i<CLASS;i++){

        studentID[i]=initial_student;
        initial_student=initial_student+increment;

    }

    //For loop to calculate average, maximum and minimum

    //Start the variables
    highest=student_score[0];
    lowest = student_score[0];
    highest_position = 0;
    lowest_position = 0;
    total = 0;


    for(i=0;i<CLASS;i++){

        //Calculate the total
        total = total + student_score[i];


        //If to compare the highest mark
        if(student_score[i] > highest){


            highest = student_score[i];
            highest_position = i;

        }
        //If to compare the lowest mark
        if(student_score[i] <= lowest){

            lowest = student_score[i];
            lowest_position = i;

        }


    }

    //Print the values
    printf("The average is -> %.2lf\n",total/CLASS);
    printf("The highest mark is -> %d | Student ID -> %d\n",highest,studentID[highest_position]);
    printf("The lowest mark is -> %d | Student ID -> %d\n",lowest,studentID[lowest_position]);

    //Print the list to check the values
    printf("==\t==========\t=====\n");
    printf(" #\tSTUDENT ID\tSCORE\n");
    for(i=0;i<CLASS;i++){

        printf(" %d\t-> %d\t %d\n",i+1,studentID[i],student_score[i]);

    }
    return 0;
}
