/*
    greedy.c
    
    Author: John C, @JaxomofRuatha
    
    Solution for CS50 Problem Set 1 "greedy"
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get amount of change owed from the user.
    float change;
    
    do
    {
        printf("O hai! How much change is owed?\n");
        change = GetFloat();
    }
    while (change < 0);
    
    //Create iteration variable for number of coins and total cents involved
    int numCoins = 0;
    int cents = round(change * 100);
    
    //Determine highest coin value remaining in total cents breakdown, and add to coin counter for each coin subtracted.
    while (cents >= 25)
    {
        cents = cents - 25;
        numCoins++;
    }
    while (cents >= 10)
    {
        cents = cents - 10;
        numCoins++;
    }
    while (cents >= 5)
    {
        cents = cents - 5;
        numCoins++;
    }
    while (cents >= 1)
    {
        cents = cents - 1;
        numCoins++;
    }
    printf ("%d\n", numCoins);
}
