/*
    credit.c
    
    Author: John C, @JaxomofRuatha
    
    Solution for CS50 Problem Set 1 "credit"
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get credit card number from user
    printf("Please input your card number: ");
    long long cardNum = get_long_long();

    //Find length of card number
    int numlen = 0;
    long long cardNumTemp = cardNum;
    while (cardNumTemp)
    {
        cardNumTemp /= 10;
        numlen++;
    }

    //Determine whether number of digits is valid
    if ((numlen != 13) && (numlen != 15) && (numlen != 16))
    {
        printf("INVALID\n");
    }

    //Initiate and populate array for checking digit location
    int cardArray[numlen + 1];
    long long j = cardNum;
    for (int i = 0; i <= numlen; i++)
    {
        cardArray[i] = j % 10;
        j /= 10;
    }

    //Find all even digits starting backwards from last, multiply each by 2, add all product digits together
    int evenSum = 0;
    for (int i = 1; i <= numlen; i += 2)
    {
        if (2 * cardArray[i] < 10)
        {
            evenSum = evenSum + (cardArray[i] * 2);
        }
        else
        {
            evenSum = evenSum + 1 + (2 * cardArray[i] - 10);
        }
    }

    //Find all odd digits starting from last, get sum
    int oddSum = 0;
    for (int i = 0; i <= numlen; i += 2)
    {
        oddSum = oddSum + cardArray[i];
    }

    int compID1;
    int compID2;

    //Get the first two digits of the card number, check company ID tags
    if ((evenSum + oddSum) % 10 == 0)
    {
        compID1 = cardArray[numlen - 1];
        compID2 = cardArray[numlen - 2];
        if (numlen == 15 && compID1 == 3 && (compID2 == 4 || compID2 == 7))
        {
            printf("AMEX\n");
        }
        else if (numlen == 16 && compID1 == 5 && (compID2 >= 1 && compID2 <= 5))
        {
            printf("MASTERCARD\n");
        }
        else if ((numlen == 13 || numlen == 16) && compID1 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    return 0;
}
