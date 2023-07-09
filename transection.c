#include<stdio.h>
#include <stdbool.h>

int user_nav_comand;
int go_back;

float withdraw_balance;
float deposit_balance;
float sent_money_balance;
float loan_request_balance;
float pre_loan_balance = 0;
float balance = 1000;

int r_account;
bool pre_loan = false;

char name[100] = "Md Siamul Islam Soaib";
long number = 0177306620;
int pin = 2121;
int id = 2121;

void can_back(){

    printf("\n\n 1. Go Back: ");
        scanf("%d",&go_back);
        if(go_back == 1){
            main();
        }else{
            printf("\n\n Command Valid Input: ");
            scanf("%d",&go_back);
            if(go_back == 1){
            main();
        }else{
            printf("\n\n You Input Multiple Time");
        }
        }


}
void withdraw(){
    system("cls");
printf("\n\n \t\t\t\t********** Welcome To FSS Bank Withdraw System **********\n\n");
printf("\n\t\t\t\tYour Balance Is: %.2f", balance);
printf("\n\t\t\t\tEnter An Amount: ");
scanf("%f", &withdraw_balance);

system("cls");
if (withdraw_balance <= balance) {
    balance -= withdraw_balance; // Update the balance by subtracting the withdrawal amount
    printf("\n\n \t\t\t\t********** Withdrawal Is Successful **********\n\n");
    printf("\n\t\t\t\tName: %s", name);
    printf("\n\t\t\t\tWithdrawn Amount: %.2f", withdraw_balance);
    printf("\n\t\t\t\tNew Balance: %.2f", balance);
    can_back();
} else {
    printf("\n\n \t\t\t\t********** Insufficient Balance **********\n\n");
    printf("\n\t\t\t\tName: %s", name);
    printf("\n\t\t\t\tCurrent Balance: %.2f", balance);
    can_back();
}




    printf("\n\n\n\n\n");


}
//
void deposit(){
    system("cls");
printf("\n\n \t\t\t\t********** Welcome To FSS Bank Deposit System **********\n\n");
printf("\n\t\t\t\tYour Balance Is: %.2f", balance);
printf("\n\t\t\t\tEnter An Amount: ");
scanf("%f", &deposit_balance);

system("cls");
if (deposit_balance > 0) {
    balance += deposit_balance; // Update the balance by adding the deposit amount
    printf("\n\n \t\t\t\t********** Deposit Is Successful **********\n\n");
    printf("\n\t\t\t\tName: %s", name);
    printf("\n\t\t\t\tDeposit Amount: %.2f", deposit_balance);
    printf("\n\t\t\t\tNew Balance: %.2f", balance);
    can_back();
} else {
    printf("\n\n \t\t\t\t********** Invalid Deposit Amount **********\n\n");
    printf("\n\t\t\t\tName: %s", name);
    printf("\n\t\t\t\tCurrent Balance: %.2f", balance);
    can_back();
}





    printf("\n\n\n\n\n");

}

void send_money(){
    system("cls");
printf("\n\n \t\t\t\t********** Welcome To FSS Bank Send Money System **********\n\n");
printf("\n\t\t\t\tYour Balance Is: %.2f", balance);
printf("\n\t\t\t\tEnter An Amount: ");
scanf("%f", &sent_money_balance);
printf("\n\t\t\t\tEnter Account Number: ");
scanf("%d", &r_account);

system("cls");
if (sent_money_balance <= balance) {
    balance -= sent_money_balance; // Update the balance by subtracting the withdrawal amount
    printf("\n\n \t\t\t\t********** Send Money Is Successful **********\n\n");
    printf("\n\t\t\t\tName: %s", name);
    printf("\n\t\t\t\tWithdrawn Amount: %.2f", sent_money_balance);
    printf("\n\t\t\t\tSend Money Account Number: %d", r_account);
    printf("\n\t\t\t\tNew Balance: %.2f", balance);
    can_back();
} else {
    printf("\n\n \t\t\t\t********** Insufficient Balance **********\n\n");
    printf("\n\t\t\t\tName: %s", name);
    printf("\n\t\t\t\tCurrent Balance: %.2f", balance);
    can_back();
}




    printf("\n\n\n\n\n");

}

void get_loan(){
    if(pre_loan == false){
        system("cls");
        printf("\n\n \t\t\t\t********** Welcome To FSS Bank Loan System **********\n\n");
        printf("\n\t\t\t\tYour Balance Is: %.2f", balance);
        printf("\n\t\t\t\tEnter An Amount: ");
        scanf("%f", &loan_request_balance);

        balance +=loan_request_balance;
        system("cls");
        printf("\nThank Your For Request A Loan . Your Request Is Successful . New Balance is %.2f",balance);
        can_back();


        printf("\n\n\n\n\n");
    }else{
        system("cls");
        printf("\n\n\t\t\t\t You are not eligible for loan");
        printf("\n\t\t\t\t Your Pre loan rest is %.2f",pre_loan_balance);
        can_back();

        printf("\n\n\n\n\n");
    }

}

void balance_inquiry(){
    system("cls");
    printf("\n\n \t\t\t\t********** Welcome To FSS Bank Balance Inquiry System **********\n\n");
    printf("\n\t\t\t\t Hello %s",name);
    printf("\n\t\t\t\t Your Balance is %.2f",balance);
    can_back();

}

void chnage_pin(){
    int pin_cry;
    system("cls");
    printf("\n\n \t\t\t\t********** Welcome To FSS Bank PIN Change System **********\n\n");
    printf("\n\t\t\t\t Enter Your Old PIN: ");
    scanf("%d",&pin_cry);
    if(pin_cry == pin){
    printf("\n\n \t\t\t\tOld Pin Is Match");
    printf("\n\t\t\t\tEnter New PIN: ");
    scanf("%d",&pin_cry);
    pin = pin_cry;
    printf("\t\t\t\tNew PIN is set and pin is %d",pin);
    can_back();
    }else{
        printf("\n\n \t\t\t\tYou Enter Wrong old PIN . Please Try Again Leter\n\n");
    can_back();
    }


}

int main(){
    system("cls");
        printf("\n\n \t\t\t\t********** FSS Bank **********\n\n");
        printf("\t\t\t\t 1. Withdraw \n");
        printf("\t\t\t\t 2. Deposit \n");
        printf("\t\t\t\t 3. Send money \n");
        printf("\t\t\t\t 4. Get Loan \n");
        printf("\t\t\t\t 5. Balance Inquiry \n");
        printf("\t\t\t\t 6. Change PIN \n");



    printf("\n\n\t\t\t\t Select What You Want: ");
    scanf("%d",&user_nav_comand);
    switch(user_nav_comand){

    case 1:
        withdraw();
        break;

    case 2:
        deposit();
        break;

    case 3:
        send_money();
        break;

    case 4:
        get_loan();
        break;

    case 5:
        balance_inquiry();
        break;

    case 6:
        chnage_pin();
        break;
    }





    return 0;

}
