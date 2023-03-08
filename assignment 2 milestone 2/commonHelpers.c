/*
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Section:IPC144 NGG
*/
// Uses the time.h library to obtain current year information 
// Get the current 4-digit year from the system 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> 
#include "commonHelpers.h"
#include <string.h>
//function descriptions
int currentYear(void) 
{                                                                
time_t currentTime = time(NULL);     
return localtime(&currentTime)-> tm_year + 1900; 
} 
// As demonstrated in the course notes: https://ict.senecacollege.ca//~ipc144/pages/content/formi.html#buf  
// Empty the standard input buffer 
void clearStandardInputBuffer(void) 
{
    while (getchar() != '\n') 
    {
        ; // On purpose: do nothing     
    } 
} 
int getInteger() //return an integer value
{
    int integer;
    char newLine;
    do
    {
        scanf("%d%c", &integer, &newLine);
        if (newLine != '\n')
        {
            printf("ERROR: Value must be an integer: ");
            clearStandardInputBuffer();
        }

    } while (newLine!= '\n');
    
    return integer;
}
int getPositiveInteger() //return a positive integer
{
    int posInteger;
    char newLine;
    do
    {
        scanf("%d%c", &posInteger, &newLine);
        if (newLine != '\n' || posInteger<0)
        {
            printf("ERROR: Value must be a positive integer greater than zero: ");
        }

    } while (newLine != '\n' || posInteger<0);
    return posInteger;
}
double getDouble() //return a double value
{
    double doubleValue;
    char newLine;
    do
    {
        scanf("%lf%c", &doubleValue, &newLine);
        if (newLine != '\n')
        {
            printf("ERROR: Value must be a double floating-point number: ");
            clearStandardInputBuffer();
        }

    } while (newLine != '\n');

    return doubleValue;
}
double getPositiveDouble() // return a positive double value
{
    double posDoublevalue;
    char newLine;
    do
    {
        scanf("%lf%c", &posDoublevalue, &newLine);
        if (newLine != '\n')
        {
            printf("ERROR: Value must be a double floating-point number: ");
            clearStandardInputBuffer();
        }
        else if (posDoublevalue <= 0)
        {
            printf("ERROR: Value must be a positive double floating-point number: ");
        }

    } while (newLine != '\n' || posDoublevalue <= 0);
    return posDoublevalue;
}
int getIntFromRange(int min, int max) //return a value in a range of a minimum and a maximum value
{
        int integer;
        char newLine;
        do
        {
            
            scanf("%d%c", &integer, &newLine);
            if (newLine != '\n')
            {
                printf("ERROR: Value must be an integer: ");
                clearStandardInputBuffer();
            }
            else if (integer<min || integer>max)
            {
                printf("ERROR: Value must be between %d and %d inclusive: ", min, max); 
                if (newLine == '\n')
                {
                    newLine = '\0';
                }
            }

        } while (newLine != '\n' || integer<min || integer>max);

        return integer;
}
char getCharOption(char * possiblechar) //return a single character
{
    
    char character;
    char secchar;
    int i, qwerty;
    qwerty = 0;
    /*for (j = 0; possiblechar[j] != '\0'; j++)
    {
        ;
    }*/
    do
    {
        scanf("%c%c", &character, &secchar);
        for ( i = 0; i < strlen(possiblechar); i++)
        {
            
            if (possiblechar[i]==character && secchar != 'o' && secchar!='g')
            {
                qwerty += 1;
            }
        }
        if (qwerty==0)
        {
            printf("ERROR: Character must be one of [");
            for (i = 0; i < strlen(possiblechar); i++)
            {
                printf("%c", possiblechar[i]);
            }
            printf("]: ");
            
        }
        if (secchar != '\n')
        {
            clearStandardInputBuffer();
        }
    } while (qwerty==0);
    return character;
}
void getCString(char* string, int min, int max) //doesn't return any value, but returns a string though the string pointer.
{
    int i;
    
    do
    {
        
        scanf("%40[^\n]", string);
        for ( i = 0; string[i] != '\0'; i++)
        {
            ;
        }
        
        if (i>max && min != max)
        {
            printf("ERROR: String length must be no more than %d chars: ", max);
            
            
        }
        else if (min==max && i != min)
        {
            printf("ERROR: String length must be exactly %d chars: ", min);
            
            
        }
        else if (i<min && min != max)
        {
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
            
        }
        
        clearStandardInputBuffer();
        
        
            
        
    } while (i< min || i>max);
}

