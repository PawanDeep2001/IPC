/*
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Section:IPC144 NGG
*/
// // Your identification information commented header goes here... //  
#ifndef TICKET_H_ 
#define TICKET_H_  
// Header file contents goes here...  
struct Message
{
    char accountType;
    char fullName[31];
    char message[151];
}message;
struct Ticket
{
    int ticketNumber;
    int accountNumber;
    int activity;
    char subject[31];
    int countMessages;
    struct Message message[19];
};

#endif // !TICKET_H_ 
