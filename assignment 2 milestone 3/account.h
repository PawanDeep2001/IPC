/*
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Section:IPC144 NGG
*/
// // Your identification information commented header goes here... //  
#ifndef ACCOUNT_H_ 
#define ACCOUNT_H_  
// Header file contents goes here...  

struct Person
{
    char fullName[31];
    int yearOfBirth;
    double TotIncome;
    char residenceCountry[31];
}person;
struct UserLogin
{
    char username[11];
    char password[9];
}login;
struct Account
{
    int accountNum;
    char accountType;
    struct Person Person;
    struct UserLogin Login;
}account;

void getAccount(struct Account* account);
void getPerson(struct Account* account);
void getUserLogin(struct Account* account);
void updateAccount(struct Account* account);
void updatePerson(struct Account* account);
void updateUserLogin(struct Account* account);
#endif // !ACCOUNT_H_ 
