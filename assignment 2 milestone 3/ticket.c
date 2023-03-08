/*
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Section:IPC144 NGG
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ticket.h"
#include "commonHelpers.h"
#include "accountTicketingUI.h"
void getTicket(struct Ticket* ticket)
{
    printf("\nNew Ticket (Ticket#:0%5d)\n", ticket->ticketNumber);
    printf("----------------------------------------\n");
    printf("Enter the ticket SUBJECT (30 chars. maximum): ");
    getCString(ticket->subject, 0, 30);
    printf("\nEnter the ticket message details (150 chars. maximum). Press the ENTER key to submit:\n");
    getCString(ticket->message[0].message, 0, 150);
}
void activate(struct Ticket* ticket)
{
    ticket->activity = 1;
}
void close(struct Ticket* ticket)
{
    ticket->activity = 0;
}

