#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db_operation.h"

Account parseAccountFromCSV(const char *line)
{
    Account account;
    char lineCopy[MAX_LINE_LENGTH];
    strncpy(lineCopy, line, sizeof(lineCopy));

    char *token;
    int i = 0;

    // Parse the line and populate the account structure
    token = strtok(lineCopy, ",");
    while (token != NULL)
    {
        switch (i)
        {
        case 0:
            account.accountNumber = atoi(token);
            break;
        case 1:
            account.accountPin = atoi(token);
        case 2:
            strncpy(account.accountHolder, token, sizeof(account.accountHolder));
            break;
        case 3:
            account.accountBalance = atoi(token);
            break;
        case 4:
            account.accountLoan = atoi(token);
            break;
        }
        token = strtok(NULL, ",");
        i++;
    }
    return account;
}

Account searchAccountByAccountNumber(int accountNumber, int accountPin)
{
    FILE *csvFile = fopen("accounts.csv", "r");

    if (csvFile == NULL)
    {
        fprintf(stderr, "Failed to open the CSV file.\n");
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    while (fgets(line, sizeof(line), csvFile) != NULL)
    {
        Account account = parseAccountFromCSV(line);
        if (account.accountNumber == accountNumber)
        {
            if (accountPin == -1)
            {
                return account;
            }
            if (account.accountPin == accountPin)
            {
                found = 1;
                return account;
            }
        }
    }

    fclose(csvFile);

    if (!found)
    {
        printf("Account with Account Number %d not found.\n", accountNumber);
    }
}

void replaceAccountInCSV(int accountNumber, int accountPin, double newBalance, double accountLoan)
{
    FILE *csvFile = fopen("accounts.csv", "r+");

    if (csvFile == NULL)
    {
        fprintf(stderr, "Failed to open the CSV file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int replaced = 0;

    while (fgets(line, sizeof(line), csvFile) != NULL)
    {
        Account account = parseAccountFromCSV(line);
        if (account.accountNumber == accountNumber)
        {
            // Modify the account details
            account.accountPin = accountPin;
            account.accountBalance = newBalance;
            account.accountLoan = accountLoan;

            // Move the file pointer to the beginning of the current line
            fseek(csvFile, -(strlen(line)), SEEK_CUR);

            // Write the updated account details back to the file
            fprintf(csvFile, "%d,%d,%s,%d,%d\n", account.accountNumber, account.accountPin, account.accountHolder, account.accountBalance, account.accountLoan);

            replaced = 1;
            break;
        }
    }

    fclose(csvFile);
}

Account db_operation(int accountNumber, int accountPin)
{
    return searchAccountByAccountNumber(accountNumber, accountPin);
}
