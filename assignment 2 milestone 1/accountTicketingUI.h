/*
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Section:IPC144 NGG
*/
#include "ticket.h"
#include "account.h"
#ifndef ACCOUNTTICKETINGUI_H_ 
#define ACCOUNTTICKETINGUI_H_   
// Header file contents goes here...  

struct AccountTicketingData {
    struct Account* accounts;   // array of accounts    
    const int ACCOUNT_MAX_SIZE; // maximum elements for account array  
    struct Ticket* tickets;     // array of tickets     
    const int TICKET_MAX_SIZE;  // maximum elements for ticket array 
}data;

void displayAccountDetailHeader();
void displayAccountDetailRecord(struct Account account);
void applicationStartup(struct AccountTicketingData *data);
int menuLogin(struct Account accounts[], int size);
void menuAgent(struct AccountTicketingData *data, struct Account acco);
int findAccountIndexByAcctNum(int num, struct Account accounts[], int size, int zero);
void  displayAllAccountDetailRecords(struct Account accounts[], int size);
// Pause execution until user enters the enter key 
void pauseExecution(void);
#endif // !ACCOUNTTICKETINGUI_H_ 
