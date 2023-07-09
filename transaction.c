#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "account.h"
#include "db_operation.h"

int nav_command;
int go_back;

float withdraw_balance;
float deposit_balance;
float sent_money_balance;
float loan_request_balance;
float pre_loan_balance = 0;
float balance;
float loan = 0;

int r_account;
bool pre_loan = false;

char name[256];
int pin;
int id;

Account globalData;

void can_back()
{
    globalData = db_operation(id, pin);
    printf("\n\n 1. Go Back: ");
    scanf("%d", &go_back);
    if (go_back == 1)
    {
        transaction(globalData);
        go_back = 0;
    }
    else
    {
        printf("\n\n Command Valid Input: ");
        scanf("%d", &go_back);
        if (go_back == 1)
        {
            transaction(globalData);
            go_back = 0;
        }
        else
        {
            printf("\n\n You Input Multiple Time");
        }
    }
}

void withdraw()
{
    clear_screen();
    printf("\n\n \t\t\t\t********** Welcome To SRF Bank Withdraw System **********\n\n");
    printf("\n\t\t\t\tYour Balance Is: %.2f", balance);
    printf("\n\t\t\t\tEnter An Amount: ");
    scanf("%f", &withdraw_balance);

    clear_screen();
    if (withdraw_balance <= balance)
    {
        balance -= withdraw_balance; // Update the balance by subtracting the withdrawal amount
        printf("\n\n \t\t\t\t********** Withdrawal Is Successful **********\n\n");
        printf("\n\t\t\t\tName: %s", name);
        printf("\n\t\t\t\tWithdrawn Amount: %.2f", withdraw_balance);
        printf("\n\t\t\t\tNew Balance: %.2f", balance);
        replaceAccountInCSV(id, pin, balance, loan);
        can_back();
    }
    else
    {
        printf("\n\n \t\t\t\t********** Insufficient Balance **********\n\n");
        printf("\n\t\t\t\tName: %s", name);
        printf("\n\t\t\t\tCurrent Balance: %.2f", balance);
        can_back();
    }

    printf("\n\n\n\n\n");
}

void deposit()
{
    clear_screen();
    printf("\n\n \t\t\t\t********** Welcome To SRF Bank Deposit System **********\n\n");
    printf("\n\t\t\t\tYour Balance Is: %.2f", balance);
    printf("\n\t\t\t\tEnter An Amount: ");
    scanf("%f", &deposit_balance);

    clear_screen();
    if (deposit_balance > 0)
    {
        balance += deposit_balance; // Update the balance by adding the deposit amount
        printf("\n\n \t\t\t\t********** Deposit Is Successful **********\n\n");
        printf("\n\t\t\t\tName: %s", name);
        printf("\n\t\t\t\tDeposit Amount: %.2f", deposit_balance);
        printf("\n\t\t\t\tNew Balance: %.2f", balance);
        replaceAccountInCSV(id, pin, balance, loan);
        can_back();
    }
    else
    {
        printf("\n\n \t\t\t\t********** Invalid Deposit Amount **********\n\n");
        printf("\n\t\t\t\tName: %s", name);
        printf("\n\t\t\t\tCurrent Balance: %.2f", balance);
        can_back();
    }

    printf("\n\n\n\n\n");
}

void send_money()
{
    int reciever_new_balance;
    clear_screen();
    printf("\n\n \t\t\t\t********** Welcome To SRF Bank Send Money System **********\n\n");
    printf("\n\t\t\t\tYour Balance Is: %.2f", balance);
    printf("\n\t\t\t\tEnter An Amount: ");
    scanf("%f", &sent_money_balance);
    printf("\n\t\t\t\tEnter Account Number: ");
    scanf("%d", &r_account);

    Account reciever = searchAccountByAccountNumber(r_account, -1);
    reciever_new_balance = reciever.accountBalance + sent_money_balance;

    clear_screen();
    if (sent_money_balance <= balance)
    {
        balance -= sent_money_balance; // Update the balance by subtracting the withdrawal amount
        printf("\n\n \t\t\t\t********** Send Money Is Successful **********\n\n");
        printf("\n\t\t\t\tName: %s", name);
        printf("\n\t\t\t\tWithdrawn Amount: %.2f", sent_money_balance);
        printf("\n\t\t\t\tSend Money Account Number: %d", r_account);
        printf("\n\t\t\t\tNew Balance: %.2f", balance);
        replaceAccountInCSV(id, pin, balance, loan);
        replaceAccountInCSV(reciever.accountNumber, reciever.accountPin, reciever_new_balance, reciever.accountLoan);
        can_back();
    }
    else
    {
        printf("\n\n \t\t\t\t********** Insufficient Balance **********\n\n");
        printf("\n\t\t\t\tName: %s", name);
        printf("\n\t\t\t\tCurrent Balance: %.2f", balance);
        can_back();
    }

    printf("\n\n\n\n\n");
}

void get_loan()
{
    if (globalData.accountLoan == 0)
    {
        clear_screen();
        printf("\n\n \t\t\t\t********** Welcome To SRF Bank Loan System **********\n\n");
        printf("\n\t\t\t\tYour Balance Is: %.2f", balance);
        printf("\n\t\t\t\tEnter An Amount: ");
        scanf("%f", &loan_request_balance);

        balance += loan_request_balance;
        clear_screen();
        printf("\n\n\n\t\t\t\tThank Your For Request A Loan . Your Request Is Successful . New Balance is %.2f", balance);
        replaceAccountInCSV(id, pin, balance, loan_request_balance);
        can_back();

        printf("\n\n\n\n\n");
    }
    else
    {
        clear_screen();
        printf("\n\n\t\t\t\t You are not eligible for loan");
        printf("\n\t\t\t\t Your Pre loan rest is %.2f", globalData.accountLoan);
        can_back();

        printf("\n\n\n\n\n");
    }
}

void balance_inquiry()
{
    clear_screen();
    printf("\n\n \t\t\t\t********** Welcome To SRF Bank Balance Inquiry System **********\n\n");
    printf("\n\t\t\t\t Hello %s", name);
    printf("\n\t\t\t\t Your Balance is %.2f", balance);
    can_back();
}

void change_pin()
{
    int pin_cry;
    clear_screen();
    printf("\n\n \t\t\t\t********** Welcome To SRF Bank PIN Change System **********\n\n");
    printf("\n\t\t\t\t Enter Your Old PIN: ");
    scanf("%d", &pin_cry);
    if (pin_cry == pin)
    {
        printf("\n\n \t\t\t\tOld Pin Is Match");
        printf("\n\t\t\t\tEnter New PIN: ");
        scanf("%d", &pin_cry);
        pin = pin_cry;
        printf("\t\t\t\tNew PIN is set and pin is %d", pin);
        replaceAccountInCSV(id, pin, balance, loan);
        can_back();
    }
    else
    {
        printf("\n\n \t\t\t\tYou Enter Wrong old PIN . Please Try Again Leter\n\n");
        can_back();
    }
}

int transaction(Account data)
{
    globalData = data;
    strcpy(name, data.accountHolder);
    pin = data.accountPin;
    id = data.accountNumber;
    balance = data.accountBalance;

    clear_screen();
    printf("\t\t\t\t********** SRF Bank **********\n\n");
    printf("\n\t\t\t\t Hello %s\n", data.accountHolder);
    printf("\t\t\t\t Balance %d\n\n", data.accountBalance);
    printf("\n\t\t\t\t 1. Withdraw \n");
    printf("\t\t\t\t 2. Deposit \n");
    printf("\t\t\t\t 3. Send money \n");
    printf("\t\t\t\t 4. Get Loan \n");
    printf("\t\t\t\t 5. Balance Inquiry \n");
    printf("\t\t\t\t 6. Change PIN \n");
    printf("\t\t\t\t Q. Quit \n");

    printf("\n\n\t\t\t\t Select What You Want: ");
    scanf(" %c", &nav_command);

    switch (nav_command)
    {
    case '1':
        withdraw();
        break;

    case '2':
        deposit();
        break;

    case '3':
        send_money();
        break;

    case '4':
        get_loan();
        break;

    case '5':
        balance_inquiry();
        break;

    case '6':
        change_pin();
        break;
    case 'q':
    case 'Q':
        printf("\n\n\t\t\t\t\t Bye Bye \n");
        exit(0);
        break;
    }
}
