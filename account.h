#ifndef ACCOUNT_H
#define ACCOUNT_H

#define MAX_LINE_LENGTH 256

typedef struct
{
    int accountNumber;
    int accountPin;
    char accountHolder[MAX_LINE_LENGTH];
    int accountBalance;
    int accountLoan;
} Account;

// Function prototypes related to the Account data type
Account parseAccountFromCSV(const char *line);
Account searchAccountByAccountNumber(int accountNumber, int accountPin);

#endif
