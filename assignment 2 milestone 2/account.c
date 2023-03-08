/*
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Section:IPC144 NGG
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> 
#include "account.h"
#include "commonHelpers.h"
#include "accountTicketingUI.h"

void getAccount(struct Account* account)
{
    printf("\nNew Account Data (Account#:%d)\n", account->accountNum);
    printf("----------------------------------------\n");
    printf("Enter the account type (A=Agent | C=Customer): ");
    account->accountType = getCharOption("AC");
    
}
void getPerson(struct Account* account)
{
    int i=0;
    printf("\nPerson Data Input\n");
    printf("----------------------------------------\n");
    printf("Enter the person's full name (30 chars max): ");
    getCString(account->Person.fullName, 0, 30);
    printf("Enter birth year (current age must be between 18 and 110): ");
    account->Person.yearOfBirth = getIntFromRange(1911, 2003);
    printf("Enter the household Income: $");
    account->Person.TotIncome = getPositiveDouble();
    printf("Enter the country (30 chars max.): ");
    getCString(account->Person.residenceCountry, 0, 30);
    while (account->Person.residenceCountry[i] != '\0')
    {

        if (account->Person.residenceCountry[i] >= 'a' && account->Person.residenceCountry[i] <= 'z')
        {
            account->Person.residenceCountry[i] = account->Person.residenceCountry[i] - 32;
        }
        i++;
    }
    
}
void getUserLogin(struct Account* account)
{
    int i, space, num, symbol, upper, lower;
    printf("\nUser Login Data Input\n");
    printf("----------------------------------------\n");
    do
    {
        space = 0;
        printf("Enter user login (10 chars max): ");
        getCString(account->Login.username, 0, 10);
        for (i = 0; i < 10; i++)
        {
            if (account->Login.username[i]==' ')
            {
                space = 1;
            }
        }
        if (space>0)
        {
            printf("ERROR:  The user login must NOT contain whitespace characters.\n");
        }
    } while (space>0);
    do
    {
        lower = 0;
        upper = 0;
        num = 0;
        symbol = 0;
        printf("Enter the password (must be 8 chars in length): ");
        getCString(account->Login.password, 8, 8);
        for ( i = 0; i < 8; i++)
        {
            if (account->Login.password[i]>='0' && account->Login.password[i]<='9')
            {
                num += 1;
            }
            else if (account->Login.password[i]>= 'a' && account->Login.password[i] <= 'z')
            {
                lower += 1;
            }
            else if (account->Login.password[i] >= 'A' && account->Login.password[i] <= 'Z')
            {
                upper += 1;
            }
            else if (account->Login.password[i] == '!' || account->Login.password[i] == '@' || account->Login.password[i] == '#' || account->Login.password[i] == '$' || account->Login.password[i] == '^' || account->Login.password[i] == '&' || account->Login.password[i] == '*' || account->Login.password[i] == '%')
            {
                symbol += 1;
            }
        }
        if (num != 2 || lower != 2 || upper != 2 || symbol != 2)
        {
            printf("SECURITY: Password must contain 2 of each:\n");
            printf("          Digit: 0-9\n");
            printf("          UPPERCASE character\n");
            printf("          lowercase character\n");
            printf("          symbol character: !@#$%c^&*\n",'%');
        }
    } while (num != 2 || lower != 2 || upper != 2 || symbol != 2);
    

    
}
void updateAccount(struct Account* account)
{
    int ans=0;
    do
    {
        printf("\nUpdate Account: %d (%s)\n", account->accountNum, account->Person.fullName);
        printf("----------------------------------------\n");
        printf("1) Update account type (current value: %c)\n", account->accountType);
        printf("2) Person\n");
        printf("3) Login\n");
        printf("0) Done\n");
        printf("Selection: ");
        ans = getIntFromRange(0, 3);
        if (ans==1)
        {
            printf("\nEnter the account type (A=Agent | C=Customer): ");
            account->accountType = getCharOption("AC");
            if (account->accountType=='A')
            {
                printf("\nAgent type accounts require a user login.  Please enter this information now:\n");
                getUserLogin(account);
                
            }
        }
        else if (ans==2)
        {
            updatePerson(account);
        }
        else if (ans==3)
        {
            if (account->accountType=='A')
            {
                updateUserLogin(account);
            }
            else
            {
                printf("\nERROR:  Customer account types don't have user logins!\n");
            }
            
        }
        else if (ans==0)
        {
            printf("\n");
        }
        
    } while (ans!=0);
}
void updatePerson(struct Account* account)
{
    int ans=0, i=0;
    do
    {
        printf("\nPerson Update Options\n");
        printf("----------------------------------------\n");
        printf("1) Full name (current value: %s)\n", account->Person.fullName);
        printf("2) Household Income (current value: $%.2lf)\n", account->Person.TotIncome);
        printf("3) Country (current value: %s)\n", account->Person.residenceCountry);
        printf("0) Done\n");
        printf("Selection: ");
        ans = getIntFromRange(0, 3);
        if (ans == 1)
        {
            printf("\nEnter the person's full name (30 chars max): ");
            getCString(account->Person.fullName, 0, 30);
            
        }
        else if (ans == 2)
        {
            printf("\nEnter the household Income: $");
            account->Person.TotIncome = getPositiveDouble();
        }
        else if (ans == 3)
        {
            printf("\nEnter the country (30 chars max.): ");
            getCString(account->Person.residenceCountry, 0, 30);
            while (account->Person.residenceCountry[i] !='\0')
            {

                if (account->Person.residenceCountry[i] >= 'a' && account->Person.residenceCountry[i] <= 'z')
                {
                    account->Person.residenceCountry[i] = account->Person.residenceCountry[i] - 32;
                }
                i++;
            }
            
        }
        
        
    } while (ans!=0);
}
void updateUserLogin(struct Account* account)
{
    int ans=0, lower, upper, num, symbol, i;
    do
    {
        printf("\nUser Login: %s - Update Options\n", account->Login.username);
        printf("----------------------------------------\n");
        printf("1) Password\n");
        printf("0) Done\n");
        printf("Selection: ");
        ans = getIntFromRange(0, 1);
        if (ans==1)
        {
            do
            {
                lower = 0;
                upper = 0;
                num = 0;
                symbol = 0;
                printf("\nEnter the password (must be 8 chars in length): ");
                getCString(account->Login.password, 8, 8);
                for (i = 0; i < 8; i++)
                {
                    if (account->Login.password[i] >= '0' && account->Login.password[i] <= '9')
                    {
                        num += 1;
                    }
                    else if (account->Login.password[i] >= 'a' && account->Login.password[i] <= 'z')
                    {
                        lower += 1;
                    }
                    else if (account->Login.password[i] >= 'A' && account->Login.password[i] <= 'Z')
                    {
                        upper += 1;
                    }
                    else if (account->Login.password[i] == '!' || account->Login.password[i] == '@' || account->Login.password[i] == '#' || account->Login.password[i] == '$' || account->Login.password[i] == '^' || account->Login.password[i] == '&' || account->Login.password[i] == '*' || account->Login.password[i] == '%')
                    {
                        symbol += 1;
                    }
                }
                if (num != 2 || lower != 2 || upper != 2 || symbol != 2)
                {
                    printf("SECURITY: Password must contain 2 of each:\n");
                    printf("          Digit: 0-9\n");
                    printf("          UPPERCASE character\n");
                    printf("          lowercase character\n");
                    printf("          symbol character: !@#$%c^&*\n",'%');
                }
            } while (num != 2 || lower != 2 || upper != 2 || symbol != 2);
        }
        
    } while (ans!= 0);
}
