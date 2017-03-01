/*
    water.c
    
    Author: John C, @JaxomofRuatha
    
    Solution for CS50 Problem Set 1 "water"
*/

#include <stdio.h>
#include <cs50.h>

int main(void)

//Takes user input of shower length in minutes, output is equivalent number of bottles.
{
    printf("minutes: ");
    int minutes = GetInt();
    printf("bottles: %d\n", (minutes*192)/16);
}
