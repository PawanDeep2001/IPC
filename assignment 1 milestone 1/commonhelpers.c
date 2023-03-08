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
int getInteger()
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
int getPositiveInteger()
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
double getDouble()
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
double getPositiveDouble()
{
    double posDoublevalue;
    char newLine;
    do
    {
        scanf("%lf%c", &posDoublevalue, &newLine);
        if (newLine != '\n' || posDoublevalue < 0)
        {
            
            printf("ERROR: Value must be a positive double floating-point number: ");
        }

    } while (newLine != '\n' || posDoublevalue < 0);
    return posDoublevalue;
}
int getIntFromRange(int min, int max)
{
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
               
            }

        } while (newLine != '\n' || integer<min || integer>max);

        return integer;
    }
}
char getCharOption()
{
    const char possiblechar[7] = { "qwerty\0" };
    char character;
    int i, qwerty;
    qwerty = 0;
    do
    {
        scanf("%c", &character);
        for ( i = 0; i < 6; i++)
        {
            
            if (possiblechar[i]==character)
            {
                qwerty += 1;
            }
        }
        if (qwerty==0)
        {
            printf("ERROR: Character must be one of [");
            for (i = 0; i < 6; i++)
            {
                printf("%c", possiblechar[i]);
            }
            printf("]: ");
            clearStandardInputBuffer();
        }
    } while (qwerty==0);
    return character;
}
void getCString(char* string, int min, int max)
{
    int i;
    
    do
    {
        clearStandardInputBuffer();
        scanf("%30[^\n]", string);
        for ( i = 0; string[i] != '\0'; i++)
        {
            ;
        }
        
        if (i>max)
        {
            printf("ERROR: String length must be no more than %d chars: ", max);
            
        }
        else if (min==max && i != min)
        {
            printf("ERROR: String length must be exactly %d chars: ", min);
            
        }
        else if (i<min)
        {
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
            
        }
        
    } while (i< min || i>max);
    
    
}

