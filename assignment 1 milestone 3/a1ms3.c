// #############################################################################################
//  Assignment: 1 
//  Milestone : 3
// #############################################################################################
// Name:Pawan Deep
// ID : 111144218
// Email : pdeep1@myseneca.ca
// Section : IPC144 NGG
// #############################################################################################


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "account.h"
#include "accountTicketingUI.h"

// ------------------------------------------------------------------
// Main entry point to application:

int main(void)
{
    // *** NOTE: No other variables are allowed to be declared ***
    struct Account account = { 0 };                             // *** DO NOT MODIFY THIS LINE ***

    printf("Assignment 1 Milestone 3 - Tester\n");              // *** DO NOT MODIFY THIS LINE ***
    printf("=============================================\n");  // *** DO NOT MODIFY THIS LINE ***

    // ---------------------------------------------------------
    // Account Data
    // ---------------------------------------------------------
    // Input (new record)
    //________________(__________________);   // Call function to get user input for a new "Account"
    
    getAccount(&account);
    // ---------------------------------------------------------
    // Person Data
    // ---------------------------------------------------------
    // Input (new record)
    //________________(__________________);   // Call function to get user input for a new "Person"
    getPerson(&account);

    // ---------------------------------------------------------
    // UserLogin Data
    // ---------------------------------------------------------
    // Input (new record)
    //________________(__________________);   // Call function to get user input for a new "UserLogin"
    getUserLogin(&account);
    // ---------------------------------------------------------
    // Display formatted Account details
    // ---------------------------------------------------------
    //_______________________________;         // Call function to display the account detail header
    displayAccountDetailHeader();
    // ________________(__________________);   // Call function to display an account detail record
    displayAccountDetailRecord(account);
    putchar('\n');
    printf("Account, Person, and User Login test completed!\n");  // *** DO NOT MODIFY THIS LINE ***

    return 0;       // *** DO NOT MODIFY THIS LINE ***
}