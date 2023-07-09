#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "account.h"
#include "db_operation.h"

int nav_command;
int go_back;

int withdraw_balance;
int deposit_balance;
int sent_money_balance;
int loan_request_balance;
int balance;
int loan = 0;

int r_account;

char name[256];
int pin;
int id;

Account globalData;

void can_back()
{
    globalData = db_operation(id, pin);
    printf("\n\n\t\t\t\t 1. Go Back: ");
    scanf("%d", &go_back);
    if (go_back == 1)
    {
        transaction(globalData);
        go_back = 0;
    }
    else
    {
        printf("\n\n\t\t\t\t Command Valid Input: ");
        scanf("%d", &go_back);
        if (go_back == 1)
        {
            transaction(globalData);
            go_back = 0;
        }
        else
        {
            printf("\n\n\t\t\t\t You Input Multiple Time");
        }
    }
}

void withdraw()
{
    clear_screen();
    printf("\n\n \t\t\t\t********** SRF Bank Withdraw System **********\n\n");
    printf("\n\t\t\t\tMaximum Withdraw Amount: %d", balance);
    printf("\n\t\t\t\tEnter An Amount: ");
    scanf("%d", &withdraw_balance);

    clear_screen();
    if (withdraw_balance <= balance)
    {
        balance -= withdraw_balance; // Update the balance by subtracting the withdrawal amount
        printf("\n\n \t\t\t\t********** Withdrawal Is Successful **********\n\n");
        printf("\n\t\t\t\tWithdrawn Amount: %d", withdraw_balance);
        printf("\n\t\t\t\tNew Balance: %d", balance);
        replaceAccountInCSV(id, pin, balance, loan);
        can_back();
    }
    else
    {
        printf("\n\n \t\t\t\t********** Insufficient Balance **********\n\n");
        printf("\n\t\t\t\tCurrent Balance: %d", balance);
        can_back();
    }

    printf("\n\n\n\n\n");
}

void deposit()
{
    clear_screen();
    printf("\n\n \t\t\t\t********** SRF Bank Deposit System **********\n\n");
    printf("\n\t\t\t\tEnter Amount: ");
    scanf("%d", &deposit_balance);

    clear_screen();
    if (deposit_balance > 0)
    {
        balance += deposit_balance; // Update the balance by adding the deposit amount
        printf("\n\n \t\t\t\t********** Deposit Is Successful **********\n\n");
        printf("\n\t\t\t\tDeposit Amount: %d", deposit_balance);
        printf("\n\t\t\t\tNew Balance: %d", balance);
        replaceAccountInCSV(id, pin, balance, loan);
        can_back();
    }
    else
    {
        printf("\n\n \t\t\t\t********** Invalid Deposit Amount **********\n\n");
        printf("\n\t\t\t\tName: %s", name);
        printf("\n\t\t\t\tCurrent Balance: %d", balance);
        can_back();
    }

    printf("\n\n\n\n\n");
}

void send_money()
{
    int reciever_new_balance;
    clear_screen();
    printf("\n\n \t\t\t\t********** SRF Bank Send Money System **********\n\n");
    printf("\n\t\t\t\tYour Balance Is: %d", balance);
    printf("\n\t\t\t\tEnter An Amount: ");
    scanf("%d", &sent_money_balance);
    printf("\n\t\t\t\tEnter Account Number: ");
    scanf("%d", &r_account);

    Account reciever = searchAccountByAccountNumber(r_account, -1);
    reciever_new_balance = reciever.accountBalance + sent_money_balance;

    clear_screen();
    if (sent_money_balance <= balance)
    {
        sleep(1);
        balance -= sent_money_balance; // Update the balance by subtracting the withdrawal amount
        printf("\n\n \t\t\t\t********** Send Money Is Successful **********\n\n");
        printf("\n\t\t\t\tSent Amount: %d", sent_money_balance);
        printf("\n\t\t\t\tReceiver: %s", reciever.accountHolder);
        printf("\n\n\t\t\t\tNew Balance: %d", balance);
        replaceAccountInCSV(id, pin, balance, loan);
        replaceAccountInCSV(reciever.accountNumber, reciever.accountPin, reciever_new_balance, reciever.accountLoan);
        can_back();
    }
    else
    {
        printf("\n\n \t\t\t\t********** Insufficient Balance **********\n\n");
        printf("\n\t\t\t\tName: %s", name);
        printf("\n\t\t\t\tCurrent Balance: %d", balance);
        can_back();
    }

    printf("\n\n\n\n\n");
}

void get_loan()
{
    if (globalData.accountLoan == 0)
    {
        clear_screen();
        printf("\n\n \t\t\t\t********** SRF Bank Loan System **********\n\n");
        printf("\n\t\t\t\tYour Balance Is: %d", balance);
        printf("\n\t\t\t\tEnter An Amount: ");
        scanf("%d", &loan_request_balance);

        balance += loan_request_balance;
        clear_screen();
        printf("\n\n\n\t\t\t\tThank Your For Request A Loan", balance);
        sleep(1);
        printf("\n\t\t\t\tYour request is successful");
        printf("\n\t\t\t\tNew Balance %d", balance);
        replaceAccountInCSV(id, pin, balance, loan_request_balance);
        can_back();

        printf("\n\n\n\n\n");
    }
    else
    {
        clear_screen();
        printf("\n\n\t\t\t\t You are not eligible for loan");
        printf("\n\t\t\t\t Your Pre loan rest is %d", globalData.accountLoan);
        can_back();

        printf("\n\n\n\n\n");
    }
}

void balance_inquiry()
{
    clear_screen();
    printf("\n\n \t\t\t\t********** SRF Bank Balance Inquiry System **********\n\n");
    printf("\n\t\t\t\t Hello %s", name);
    printf("\n\t\t\t\t Your Balance is %d", balance);
    can_back();
}

void change_pin()
{
    int pin_cry;
    clear_screen();
    printf("\n\n \t\t\t\t********** SRF Bank PIN Change System **********\n\n");
    printf("\n\t\t\t\t Enter Your Old PIN: ");
    scanf("%d", &pin_cry);
    if (pin_cry == pin)
    {
        printf("\n\t\t\t\t Old Pin Is Match");
        printf("\n\n\t\t\t\t Enter New PIN: ");
        scanf("%d", &pin_cry);
        pin = pin_cry;
        printf("\t\t\t\t New PIN is set and pin is %d", pin);
        replaceAccountInCSV(id, pin, balance, loan);
        can_back();
    }
    else
    {
        printf("\n\n \t\t\t\tYou Enter Wrong old PIN . Please Try Again Later\n\n");
        can_back();
    }
}

void pay_loan(){
    int pay_loan_balance;
    clear_screen();
    printf("\n\n \t\t\t\t********** SRF Bank Loan System **********\n\n");
    printf("\n\t\t\t\tYour Balance Is: %d", balance);
    printf("\n\t\t\t\tEnter An Amount: ");
    scanf("%d", &pay_loan_balance);

    if (pay_loan_balance <= balance)
    {
        sleep(1);
        int new_loan = loan - pay_loan_balance;
        balance -= pay_loan_balance; // Update the balance by subtracting the withdrawal amount
        printf("\n\n \t\t\t\t********** Loan Pay Is Successful **********\n\n");
        printf("\n\t\t\t\tLoan Paid Amount: %d", pay_loan_balance);
        printf("\n\t\t\t\tNew Balance: %d", balance);
        replaceAccountInCSV(id, pin, balance, new_loan);
        can_back();
    }

    else
    {
        printf("\n\n \t\t\t\t********** Insufficient Balance **********\n\n");
        printf("\n\t\t\t\tName: %s", name);
        printf("\n\t\t\t\tCurrent Balance: %d", balance);
        can_back();
    }

    printf("\n\n\n\n\n");
}

int transaction(Account data)
{
    globalData = data;
    strcpy(name, data.accountHolder);
    pin = data.accountPin;
    id = data.accountNumber;
    balance = data.accountBalance;
    loan = data.accountLoan;

    clear_screen();
    printf("\t\t\t\t********** SRF Bank **********\n\n");
    printf("\n\t\t\t\t Hello %s\n", data.accountHolder);
    printf("\t\t\t\t Current Balance %d\n", data.accountBalance);
    printf("\t\t\t\t Loan Amount %d\n\n", data.accountLoan);
    printf("\n\t\t\t\t\t 1. Withdraw \n");
    printf("\t\t\t\t\t 2. Deposit \n");
    printf("\t\t\t\t\t 3. Send money \n");
    printf("\t\t\t\t\t 4. Get Loan \n");
    printf("\t\t\t\t\t 5. Balance Inquiry \n");
    printf("\t\t\t\t\t 6. Change PIN \n");
    printf("\t\t\t\t\t 7. Pay Loan \n");
    printf("\t\t\t\t\t Q. Quit \n");

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

    case '7':
        pay_loan();
    case 'q':
    case 'Q':
        printf("\n\n\t\t\t\t\t Bye Bye \n");
        exit(0);
        break;
    }
}
