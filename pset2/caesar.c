/*
    caesar.c
    
    Author: John C, @JaxomofRuatha
    
    Solution for CS50 Problem Set 2 "caesar"
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    
    //Check to make sure number of arguments is valid.
    if (argc != 2)
    {
        printf("Please input a valid key!");
        return 1;
    }
    else
    {
        //Convert the input into an integer with alphabet value
        int k = atoi(key) % 26;
        
        //Check that key is not zero
        if (k == 0)
        {
            printf("Please input a valid key!\n");
            return 1;
        }
        
        //Get user text to encrypt
        printf("plaintext:  ");
        string pText = GetString();
        
        //Encrypt and print text after checking whether upper, lower, or non-alphabetical
        if (pText != NULL)
        {
            printf("ciphertext: ");
            for (int i = 0, n = strlen(pText); i<n; i++)
            {
                int c = 0;
                if (isupper(pText[i]))
                {
                    c = (((int)pText[i] - 65 + k) % 26) + 65;
                    printf("%c", (char) c);
                }
                else if (islower(pText[i]))
                {
                    c = (((int)pText[i] - 97 + k) % 26) + 97;
                    printf("%c", (char) c);
                }
                else
                {
                    printf("%c", pText[i]);
                }
            }
            printf("\n");
            return 0;
        }
    }
        
}
