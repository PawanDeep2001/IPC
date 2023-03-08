/*
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Section:IPC144 NGG
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h> 
#include <string.h>
#include "accountTicketingUI.h"
#include "account.h"
#include "commonHelpers.h"
#include "ticket.h"

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
    char log[30], pass[30];
    int attempts;
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
            attempts = 3;
            do
            {
                printf("\nEnter the account#: ");
                acc = getInteger();
                printf("User Login        : ");
                scanf("%s", log);
                printf("Password          : ");
                scanf("%s", pass);


                for (i = 0; i < size; i++)
                {
                    if (acc == accounts[i].accountNum && accounts[i].accountType == 'A' && !(strcmp(log, accounts[i].Login.username)) && !(strcmp(pass, accounts[i].Login.password)))
                    {
                        out = 1;
                        index = i;
                        printf("\n");
                        attempts = 0;
                    }

                }
                if (out == 0)
                {
                    attempts -= 1;
                    printf("INVALID user login/password combination! [attempts remaining:%d]\n", attempts);
                    if (attempts == 0)
                    {
                        printf("\nERROR:  Access Denied.\n\n");
                        pauseExecution();
                        printf("\n");
                    }


                }
            } while (attempts!=0);
            
            
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
    int ans = -1, i=0, index=-1, acc=0, output=0, highest=0, number=0, ans3=0,j=0, ans4=0, ans5=0, error=0, index2=0, highest2=0, b, ans7=0, index3=0;
    char ans2, ans6, ans8, ans9;
    char active[10] = { "ACTIVE" };
    char closed[10] = { "CLOSED" };
    char c = { 'C' };
    char a = { 'A' };
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
                printf("\nERROR: Account listing is FULL, call ITS Support!\n\n");
                pauseExecution();
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
            output = 0;
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
            number = 0;
            output = 0;
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
                        printf("\n");
                        displayAccountDetailHeader();
                        displayAccountDetailRecord(data->accounts[i]);
                    }
                }
                for ( i = 0; i < data->TICKET_MAX_SIZE; i++)
                {
                    if (acc== data->tickets[i].accountNumber)
                    {
                        number += 1;
                    }
                }
                if (output==1)
                {

                    printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
                    ans2 = getCharOption("YN");
                    if (ans2 == 'Y')
                    {
                        for ( i = 0; i < data->TICKET_MAX_SIZE; i++)
                        {
                            if (data->tickets[i].accountNumber==acc)
                            {
                                data->tickets[i].accountNumber = 0;
                                data->tickets[i].ticketNumber = 0;
                            }
                        }
                        data->accounts[index].accountNum = 0;
                        printf("\n*** Account Removed! (%d ticket(s) removed) ***\n\n", number);
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
        else if (ans==5)
        {
            ans3 = 0;
            do
            {
                error = 0;
                printf("\n------ ----- --------------- ------ ------------------------------ --------\n");
                printf("Ticket Acct# Full Name       Status Subject                        Messages\n");
                printf("------ ----- --------------- ------ ------------------------------ --------\n");
                for (i = 0; i < data->TICKET_MAX_SIZE; i++)
                {
                    if (data->tickets[i].activity == 1 && data->tickets[i].countMessages == 1 && data->tickets[i].accountNumber>0)
                    {
                        printf("0%5d %5d %-15s %6s %-30s     %d\n", data->tickets[i].ticketNumber, data->tickets[i].accountNumber, data->tickets[i].message[0].fullName, active, data->tickets[i].subject, data->tickets[i].countMessages);
                    }
                }
                printf("------ ----- --------------- ------ ------------------------------ --------\n");
                printf("\nEnter the ticket number to view the messages or\n");
                printf("0 to return to previous menu: ");
                scanf("%d", &ans3);
                printf("\n");
                if (ans3!=0)
                {
                    for (i = 0; i < data->TICKET_MAX_SIZE; i++)
                    {
                        if (ans3==data->tickets[i].ticketNumber && data->tickets[i].activity == 1 && data->tickets[i].countMessages == 1)
                        {
                            printf("================================================================================\n");
                            printf("0%5d (ACTIVE) Re: %s\n", data->tickets[i].ticketNumber, data->tickets[i].subject);
                            printf("================================================================================\n");
                            printf("CUSTOMER (%s):\n", data->tickets[i].message[0].fullName);
                            printf("   %s\n\n", data->tickets[i].message[0].message);
                            pauseExecution();
                            
                            error = 1;
                        }
                    }
                    if (error == 0)
                    {
                        printf("ERROR: Invalid ticket number.\n\n");
                        pauseExecution();
                    }
                }
            } while (ans3!=0);
        }
        else if (ans==6)
        {
            ans4 = 0;
            do
            {
                error = 0;
                printf("\n------ ----- --------------- ------ ------------------------------ --------\n");
                printf("Ticket Acct# Full Name       Status Subject                        Messages\n");
                printf("------ ----- --------------- ------ ------------------------------ --------\n");

                for (i = 0; i < data->TICKET_MAX_SIZE; i++)
                {
                    if (data->tickets[i].activity == 1 && data->tickets[i].accountNumber > 0)
                    {
                        printf("0%5d %5d %-15s %6s %-30s     %d\n", data->tickets[i].ticketNumber, data->tickets[i].accountNumber, data->tickets[i].message[0].fullName, active, data->tickets[i].subject, data->tickets[i].countMessages);
                    }
                }
                printf("------ ----- --------------- ------ ------------------------------ --------\n");
                printf("\nEnter the ticket number to view the messages or\n");
                printf("0 to return to previous menu: ");
                scanf("%d", &ans4);
                printf("\n");
                if (ans4!=0)
                {
                    for (i = 0; i < data->TICKET_MAX_SIZE; i++)
                    {
                        if (ans4==data->tickets[i].ticketNumber && data->tickets[i].activity == 1)
                        {
                            error = 1;
                            printf("================================================================================\n");
                            printf("0%5d (ACTIVE) Re: %s\n", data->tickets[i].ticketNumber, data->tickets[i].subject);
                            printf("================================================================================\n");
                            error = 1;
                            for ( j = 0; j < data->tickets[i].countMessages; j++)
                            {
                                if (data->tickets[i].message[j].accountType==c)
                                {
                                    printf("CUSTOMER (%s):\n", data->tickets[i].message[j].fullName);
                                    printf("   %s\n\n", data->tickets[i].message[j].message);
                                }
                                else if (data->tickets[i].message[j].accountType == a)
                                {
                                    printf("AGENT (%s):\n", data->tickets[i].message[j].fullName);
                                    printf("   %s\n\n", data->tickets[i].message[j].message);
                                }
                            }
                            pauseExecution();
                            
                        }
                    }
                    if (error == 0)
                    {
                        printf("ERROR: Invalid ticket number.\n\n");
                        pauseExecution();
                    }
                }
                
            } while (ans4!=0);
        }
        else if (ans==7)
        {
            ans5 = 0;
            do
            {
                error = 0;
                printf("\n------ ----- --------------- ------ ------------------------------ --------\n");
                printf("Ticket Acct# Full Name       Status Subject                        Messages\n");
                printf("------ ----- --------------- ------ ------------------------------ --------\n");

                for (i = 0; i < data->TICKET_MAX_SIZE; i++)
                {
                    if (data->tickets[i].activity == 0 && data->tickets[i].accountNumber>0)
                    {
                        printf("0%5d %5d %-15s %6s %-30s     %d\n", data->tickets[i].ticketNumber, data->tickets[i].accountNumber, data->tickets[i].message[0].fullName, closed, data->tickets[i].subject, data->tickets[i].countMessages);
                    }
                }
                printf("------ ----- --------------- ------ ------------------------------ --------\n");
                printf("\nEnter the ticket number to view the messages or\n");
                printf("0 to return to previous menu: ");
                scanf("%d", &ans5);
                printf("\n");
                if (ans5!=0)
                {
                    for (i = 0; i < data->TICKET_MAX_SIZE; i++)
                    {
                        if (ans5==data->tickets[i].ticketNumber && data->tickets[i].activity == 0)
                        {
                            error = 1;
                            printf("================================================================================\n");
                            printf("0%5d (CLOSED) Re: %s\n", data->tickets[i].ticketNumber, data->tickets[i].subject);
                            printf("================================================================================\n");
                            for ( j = 0; j < data->tickets[i].countMessages; j++)
                            {
                                if (data->tickets[i].message[j].accountType==c)
                                {
                                    printf("CUSTOMER (%s):\n", data->tickets[i].message[j].fullName);
                                    printf("   %s\n\n", data->tickets[i].message[j].message);
                                }
                                else if(data->tickets[i].message[j].accountType == a)
                                {
                                    printf("AGENT (%s):\n", data->tickets[i].message[j].fullName);
                                    printf("   %s\n\n", data->tickets[i].message[j].message);
                                }
                            }
                            pauseExecution();
                            
                        }
                    }
                    if (error == 0)
                    {
                        printf("ERROR: Invalid ticket number.\n\n");
                        pauseExecution();
                    }
                }
            } while (ans5!=0);
        }
        else if (ans==8)
        {
            index2 = 0;
            highest2 = 0;
            output = 0;
            printf("\nEnter the account#: ");
            acc = getInteger();
            printf("\n");
            for (i = 0; i < data->ACCOUNT_MAX_SIZE; i++)
            {
                if (acc == data->accounts[i].accountNum)
                {
                    if (data->accounts[i].accountType == c)
                    {
                        displayAccountDetailHeader();
                        displayAccountDetailRecord(data->accounts[i]);
                        printf("\nAdd a new ticket for this customer? ([Y]es|[N]o): ");
                        ans6 = getCharOption("YN");
                        if (ans6=='Y')
                        {
                            output = 1;
                            b = i;
                        }
                    }
                    else
                    {
                        printf("ERROR: Agent accounts can't have tickets!\n\n");
                        pauseExecution();
                    }
                }
            }
            if (output == 1)
            {
                for (i = 0; i < data->TICKET_MAX_SIZE; i++)
                {
                    if (data->tickets[i].accountNumber == 0)
                    {
                        index2 = i;
                        break;
                    }
                }
                for (j = 0; j < data->TICKET_MAX_SIZE; j++)
                {
                    if (data->tickets[j].ticketNumber > highest2)
                    {
                        highest2 = data->tickets[j].ticketNumber;
                    }
                }
                if (i == data->TICKET_MAX_SIZE)
                {
                    printf("\nERROR: Ticket listing is FULL, call ITS Support!\n\n");
                    pauseExecution();
                }
                else
                {
                    data->tickets[index2].ticketNumber = highest2+1;
                    data->tickets[index2].accountNumber = data->accounts[b].accountNum;
                    data->tickets[index2].activity = 1;
                    data->tickets[index2].countMessages = 1;
                    data->tickets[index2].message[0].accountType = 'C';
                    strcpy(data->tickets[index2].message[0].fullName, data->accounts[b].Person.fullName);
                    
                    getTicket(&data->tickets[index2]);
                    printf("\n*** New ticket created! ***\n\n");
                    pauseExecution();
                }
            }
            
        }
        else if (ans==9)
        {
            output = 0;
            printf("\nEnter ticket number: ");
            acc = getInteger();
            do
            {
                for (i = 0; i < data->TICKET_MAX_SIZE; i++)
                {
                    if (acc == data->tickets[i].ticketNumber)
                    {
                        output = 1;
                        index3 = i;
                    }
                }
                if (output==1)
                {
                    printf("\n----------------------------------------");
                    printf("\nTicket 0%d - Update Options\n", data->tickets[index3].ticketNumber);
                    printf("----------------------------------------\n");
                    if (data->tickets[index3].activity == 1)
                    {
                        printf("Status  : ACTIVE\n");

                    }
                    else
                    {
                        printf("Status  : CLOSED\n");
                    }
                    printf("Subject : %s\n", data->tickets[index3].subject);
                    printf("Acct#   : %d\n", data->tickets[index3].accountNumber);
                    printf("Customer: %s\n", data->tickets[index3].message[0].fullName);
                    printf("----------------------------------------\n");
                    printf("1) Add CUSTOMER message\n");
                    printf("2) Add AGENT message\n");
                    printf("3) Close ticket\n");
                    printf("4) Re-activate ticket\n");
                    printf("0) Done\n");
                    printf("Selection: ");
                    ans7 = getIntFromRange(0, 4);

                    if (ans7 == 1)
                    {
                        if (data->tickets[index3].countMessages < 20)
                        {
                            if (data->tickets[index3].activity == 1)
                            {
                                data->tickets[index3].countMessages += 1;
                                printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                                getCString(data->tickets[index3].message[data->tickets[index3].countMessages - 1].message, 0, 150);
                                data->tickets[index3].message[data->tickets[index3].countMessages - 1].accountType = 'C';
                                strcpy(data->tickets[index3].message[data->tickets[index3].countMessages - 1].fullName, data->tickets[index3].message[0].fullName);
                                
                            }
                            else
                            {
                                printf("\nERROR: Ticket is closed - new messages are not permitted.\n");
                            }
                        }
                        else
                        {
                            printf("\nERROR: Message limit has been reached, call ITS Support!\n");
                        }
                    }
                    else if (ans7 == 2)
                    {
                        if (data->tickets[index3].countMessages < 20)
                        {
                            if (data->tickets[index3].activity == 1)
                            {
                                data->tickets[index3].countMessages += 1;
                                printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
                                getCString(data->tickets[index3].message[data->tickets[index3].countMessages - 1].message, 0, 150);
                                data->tickets[index3].message[data->tickets[index3].countMessages - 1].accountType = 'A';
                                strcpy(data->tickets[index3].message[data->tickets[index3].countMessages - 1].fullName, acco.Person.fullName);
                                
                            }
                            else
                            {
                                printf("\nERROR: Ticket is closed - new messages are not permitted.\n");
                            }
                        }
                        else
                        {
                            printf("\nERROR: Message limit has been reached, call ITS Support!\n");
                        }
                    }
                    else if (ans7 == 3)
                    {
                        if (data->tickets[index3].activity == 1)
                        {
                            printf("\nAre you sure you CLOSE this ticket? ([Y]es|[N]o): ");
                            ans8 = getCharOption("YN");
                            if (ans8 == 'Y')
                            {
                                close(&data->tickets[index3]);
                                printf("\n*** Ticket closed! ***\n");
                            }
                        }
                        else
                        {
                            printf("\nERROR: Ticket is already closed!\n");
                        }
                    }
                    else if (ans7 == 4)
                    {
                        if (data->tickets[index3].activity == 0)
                        {
                            printf("\nAre you sure you want to RE-ACTIVATE this closed ticket? ([Y]es|[N]o): ");
                            ans9 = getCharOption("YN");
                            if (ans9 == 'Y')
                            {
                                activate(&data->tickets[index3]);
                                printf("\n*** Ticket re-activated! ***\n");
                            }
                        }
                        else
                        {
                            printf("\nERROR: Ticket is already active!\n");
                        }

                    }
                    else if (ans7==0)
                    {
                        printf("\n");
                    }
                }
                else
                {
                    printf("\nERROR: Invalid ticket number.\n");
                }
                
            } while (ans7!=0);
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
    putchar('\n'); 
}





