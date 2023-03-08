/*
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Section:IPC144 NGG
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> 
#include "accountTicketingUI.h"
#include "account.h"
void displayAccountDetailHeader()
{
    printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
    printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
}
void displayAccountDetailRecord(struct Account account)
{
    char agent[10] = { "AGENT" };
    char client[10] = { "CLIENT" };
    char a = { 'C' };
    char password[8];
    int i;
    for ( i = 0; i < 8; i++)
    {
        if (i%2==1)
        {
            password[i] = '*';
        }
        else
        {
            password[i] = account.Login.password[i];
        }
    }
    if (a == account.accountType)
    {
        printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s %8s\n", account.accountNum, client, account.Person.fullName, account.Person.yearOfBirth, account.Person.TotIncome, account.Person.residenceCountry, account.Login.username, password);

    }
    else 
    {
        printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s %8s\n", account.accountNum, agent, account.Person.fullName, account.Person.yearOfBirth, account.Person.TotIncome, account.Person.residenceCountry, account.Login.username, password);
    }
}






