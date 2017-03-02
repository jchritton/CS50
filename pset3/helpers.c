/*
    helpers.c
    
    Author: John C, @JaxomofRuatha
    
    Solution for CS50 Problem Set 3 "find" - MORE COMFORTABLE
*/
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //Create variables for the bottom, top, and middle values in current search field.
    int loVal = 0;
    int hiVal = n - 1;
    int midVal = (loVal + hiVal) / 2;
    
    //As long as there is a valid range of values, either search up, down, or return the current value as search found.
    while (loVal <= hiVal)
    {
        if (values[midVal] == value)
        {
            return true;
        }
        else if (values[midVal] > value)
        {
            hiVal = midVal - 1;
            midVal = (loVal + hiVal) / 2;
        }
        else if (values[midVal] < value)
        {
            loVal = midVal + 1;
            midVal = (loVal + hiVal) / 2;
        }
    }

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    bool swap = false;
    
    //Iterate through columns, compare each number with the next in the array, bubble sort the larger values up.
    for (int x = 0; x < n - 1; x++)
    {
        for (int i = x + 1; i < n; i++)
        {
            if (values[x] > values[i])
            {
                int current = values[x];
                values[x] = values[i];
                values[i] = current;
                swap = true;
            }
        }
        
        //If the array has been iterated through without swapping values, the array is sorted.
        if (!swap)
        {
            break;
        }
    }
    
    return;
}
