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
#include "commonHelpers.h"
void displayAccountDetailHeader()
{
    printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");
    printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");
}
void displayAccountDetailRecord(struct Account account)
{
    char agent[10] = { "AGENT" };
    char client[10] = { "CUSTOMER" };
    char a = { 'C' };
    char password[8];
    char empty[20] = {""};
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
        printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s %8s\n", account.accountNum, client, account.Person.fullName, account.Person.yearOfBirth, account.Person.TotIncome, account.Person.residenceCountry, empty, empty);

    }
    else 
    {
        printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s %8s\n", account.accountNum, agent, account.Person.fullName, account.Person.yearOfBirth, account.Person.TotIncome, account.Person.residenceCountry, account.Login.username, password);
    }
}
void applicationStartup(struct AccountTicketingData *data)
{

    char output;
    int ans;
    do
    {
        ans=menuLogin(data->accounts, data->ACCOUNT_MAX_SIZE);
        
        if (ans==0)
        {
            printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
            output = getCharOption("yYnN");
            printf("\n");
            
        }
        else
        {
            menuAgent(data, data->accounts[ans]);
        }
    } while (output == 'n' || output == 'N' );
    printf("==============================================\n");
    printf("Account Ticketing System - Terminated\n");
    printf("==============================================\n");
}
int menuLogin(struct Account accounts[], int size)
{
    int select, index=-1;
    int acc, i, out=0;
    do
    {
        printf("==============================================\n");
        printf("Account Ticketing System - Login\n");
        printf("==============================================\n");
        printf("1) Login to the system\n");
        printf("0) Exit application\n");
        printf("----------------------------------------------\n");
        printf("\nSelection: ");
        select = getIntFromRange(0, 1);
        
        if (select == 1)
        {
            printf("\nEnter your account#: ");
            acc = getInteger();
            
            for (i = 0; i < size; i++)
            {
                if (acc == accounts[i].accountNum && accounts[i].accountType=='A')
                {
                    out = 1;
                    index = i;
                    printf("\n");
                }
                
            }
            if (out==0)
            {
                printf("ERROR:  Login failed!\n\n");
                pauseExecution();
                
            }
            
        }
        else
        {
            index = 0;
            out = 1;
        }
    } while ((select>1|| select<0) || out==0);
    return index;
}
void menuAgent(struct AccountTicketingData *data, struct Account acco)
{
    int ans = -1, i=0, index=-1, acc=0, output=0, highest=0;
    char ans2;
    do
    {
        printf("AGENT: %s (%d)\n", acco.Person.fullName, acco.accountNum);
        printf("==============================================\n");
        printf("Account Ticketing System - Agent Menu\n");
        printf("==============================================\n");
        printf("1) Add a new account\n");
        printf("2) Modify an existing account\n");
        printf("3) Remove an account\n");
        printf("4) List accounts: detailed view\n");
        printf("----------------------------------------------\n");
        printf("5) List new tickets\n");
        printf("6) List active tickets\n");
        printf("7) List closed tickets\n");
        printf("8) Add a new ticket\n");
        printf("9) Manage a ticket\n");
        printf("----------------------------------------------\n");
        printf("0) Logout\n\n");
        printf("Selection: ");
        ans = getIntFromRange(0, 9);
        
        if (ans==1)
        {
            for ( i = 0; i < data->ACCOUNT_MAX_SIZE; i++)
            {
                if (data->accounts[i].accountNum==0)
                {
                    index = i;
                    break;
                }
                if (data->accounts[i].accountNum>highest)
                {
                    highest = data->accounts[i].accountNum;
                }
                
            }
            if (i== data->ACCOUNT_MAX_SIZE)
            {
                printf("ERROR: Account listing is FULL, call ITS Support! ");
            }
            else 
            {
                data->accounts[index].accountNum = highest + 1;
                getAccount(&data->accounts[index]);
                getPerson(&data->accounts[index]);
                
                if (data->accounts[index].accountType == 'A')
                {
                    getUserLogin(&data->accounts[index]);
                }
                printf("\n*** New account added! ***\n\n");
                pauseExecution();
            }
            
        }
        else if (ans==2)
        {
            printf("\nEnter the account#: ");
            acc = getInteger();
            for (i = 0; i < data->ACCOUNT_MAX_SIZE; i++)
            {
                if (acc==data->accounts[i].accountNum)
                {
                    output = 1;
                    index = i;
                    break;
                }
            }
            if (output==0)
            {
                printf("ERROR:  Login failed!\n");
            }
            else
            {
                updateAccount(&data->accounts[index]);
            }
        }
        else if (ans==3)
        {
            printf("\nEnter the account#: ");
            acc = getInteger();
            if (acc==acco.accountNum)
            {
                printf("\nERROR: You can't remove your own account!\n\n");
                pauseExecution();
                
            }
            else
            {
                for (i = 0; i < data->ACCOUNT_MAX_SIZE; i++)
                {
                    if (acc== data->accounts[i].accountNum)
                    {
                        output = 1;
                        index = i;
                        displayAccountDetailHeader();
                        displayAccountDetailRecord(data->accounts[i]);
                    }
                }
                if (output==1)
                {

                    printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
                    ans2 = getCharOption("YN");
                    if (ans2 == 'Y')
                    {
                        data->accounts[index].accountNum = 0;
                        printf("\n*** Account Removed! ***\n\n");
                        pauseExecution();
                        
                    }
                }
                
            }
        }
        else if (ans==4)
        {
            printf("\n");
            displayAllAccountDetailRecords(data->accounts, data->ACCOUNT_MAX_SIZE);
            printf("\n");
            /*displayAccountDetailHeader();
            do
            {
                displayAccountDetailRecord(accounts[i]);
                i++;
            } while (accounts[i].accountNum==0);*/
            pauseExecution();
            
        }
        else if (ans>4)
        {
        printf("\nFeature #%d currently unavailable!\n\n", ans);
        pauseExecution();
        }
    } while (ans!=0);
    printf("\n### LOGGED OUT ###\n\n");
}
int findAccountIndexByAcctNum(int num, struct Account accounts[], int size, int zero)
{
    int i;
    int index=0, number=0;
    if (zero==0)
    {
        for ( i = 0; i < size; i++)
        {
            if (num== accounts[i].accountNum)
            {
                index = i;
            }
        }
        if (index==0)
        {
            return -1;
        }
        else
        {
            return index;
        }
    }
    else
    {
        printf("Enter your account#: ");
        number = getInteger();
        for (i = 0; i < size; i++)
        {
            if (number == accounts[i].accountNum)
            {
                index = i;
            }
        }
        if (index == 0)
        {
            return -1;
        }
        else
        {
            return index;
        }
    }
}
void  displayAllAccountDetailRecords(struct Account accounts[], int size)
{
    int i = 0;
    displayAccountDetailHeader();
    for ( i = 0; i<size; i++)
    {
        if (accounts[i].accountNum>0)
        {
            displayAccountDetailRecord(accounts[i]);
        }
        
    }
    /* do
    {
        if (accounts[i].accountNum>0)
        {
            displayAccountDetailRecord(accounts[i]);
        }
        i++;
    } while (i==size);*/
}
// Pause execution until user enters the enter key 
void pauseExecution(void) 
{    
    printf("<< ENTER key to Continue... >>");     
    clearStandardInputBuffer();     
    printf("\n");
}





