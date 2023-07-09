#ifndef DB_OPERATION_H
#define DB_OPERATION_H

#include "account.h"  // Include any necessary header files

Account db_operation(int accountNumber, int pin);
void replaceAccountInCSV(int accountNumber, int accountPin, int newBalance, int accountLoan);
void appendAccountToCSV(int accountNumber, char accountHolder[MAX_LINE_LENGTH], int accountPin, int accountBalance, int accountLoan);

#endif
