/*
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Section:IPC144 NGG
*/
#include "account.h"
#ifndef ACCOUNTTICKETINGUI_H_ 
#define ACCOUNTTICKETINGUI_H_   
// Header file contents goes here...  


void displayAccountDetailHeader();
void displayAccountDetailRecord(struct Account account);
void applicationStartup(struct Account accounts[], int size);
int menuLogin(struct Account accounts[], int size);
void menuAgent(struct Account accounts[], int size, struct Account acco);
int findAccountIndexByAcctNum(int num, struct Account accounts[], int size, int zero);
void  displayAllAccountDetailRecords(struct Account accounts[], int size);
// Pause execution until user enters the enter key 
void pauseExecution(void);
#endif // !ACCOUNTTICKETINGUI_H_ 
