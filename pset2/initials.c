/*
    initials.c
    
    Author: John C, @JaxomofRuatha
    
    Solution for CS50 Problem Set 2 "initials"
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //Get input of name from user
    char* s = GetString();
    bool start = false;
    
    for (int i = 0, inputLen = strlen(s); i < inputLen; i++)
    {
        char c = s[i];
        
        //If current character is not a space and a word was not previously started, current character is an initial.
        if (c != ' ' && start == false)
        {
            printf("%c", toupper(c));
            start = true;
        }
        
        //If current character is a space, either there is no word yet or a word has ended.
        if (c == ' ')
        {
            start = false;
        }
    }
    
    printf("\n");
    
    return 0;
}
