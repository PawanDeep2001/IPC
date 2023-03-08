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


void getAccount(struct Account* account)
{

    printf("Account Data: New Record\n");
    printf("----------------------------------------\n");
    printf("Enter the account number: ");
    account->accountNum= getInteger();
    printf("Enter the account type (A=Agent | C=Customer): ");
    account->accountNum = getCharOption("AC");
}
void getPerson(struct Account* account)
{
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
    printf("\n");
}
void getUserLogin(struct Account* account)
{
    printf("User Login Data Input\n");
    printf("----------------------------------------\n");
    printf("Enter user login (10 chars max): ");
    getCString(account->Login.username, 0, 10);
    printf("Enter the password (must be 8 chars in length): ");
    getCString(account->Login.password, 8, 8);
    printf("\n");
}
