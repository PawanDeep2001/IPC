/*
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Section:IPC144 NGG
*/
#ifndef COMMON_HELPERS_H_ 
#define COMMON_HELPERS_H_  
// Header file contents goes here...  

//prototype of functions
int currentYear();
void clearStandardInputBuffer(void);
int getInteger();
int getPositiveInteger();
int getIntFromRange(int min, int max);
double getDouble();
double getPositiveDouble();
char getCharOption(char *possiblechar);
void getCString(char *string, int min, int max);
#endif // !COMMON_HELPERS_H_


