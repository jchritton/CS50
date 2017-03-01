/*
    vigenere.c
    
    Author: John C, @JaxomofRuatha
    
    Solution for CS50 Problem Set 2 "vigenere"
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Check for correct number of arguments and only alphabetical characters for the key
    if (argc != 2)
    {
        printf("Please input the correct number of arguments!\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Please input only alphabetical characters!");
                return 1;
            }
        }
    }
    
    string k = argv[1];
    int kLength = strlen(k);
    
    //Get text to encipher from user input.
    printf("plaintext:  ");
    string p = GetString();
    printf("ciphertext: ");
    
    for (int i = 0, j = 0, n = strlen(p); i < n; i++)
    {
        //Track which character of key currently being used, wrap around for key length.
        int key = tolower(k[j % kLength]) - 97;
        
        //Use caesar cipher with a key of the current character's ASCII value, print result.
        if (isupper(p[i]))
        {
            printf("%c", 65 + (p[i] - 65 + key) % 26);
            j++;
        }
        else if (islower(p[i]))
        {
            printf("%c", 97 + (p[i] - 97 + key) % 26);
            j++;
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}
