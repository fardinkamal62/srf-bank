#ifndef DB_OPERATION_H
#define DB_OPERATION_H

#include "account.h"  // Include any necessary header files

Account db_operation(int accountNumber, int pin);
void replaceAccountInCSV(int accountNumber, int accountPin, double newBalance, double accountLoan);

#endif
