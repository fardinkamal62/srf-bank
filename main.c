#include <stdio.h>
#include <stdlib.h>
#include "transaction.h"
#include "db_operation.h"

int user_nav_comand;

void clear_screen()
{
#ifdef _WIN32
    system("cls"); // Clear screen on Windows
#else
    system("clear"); // Clear screen on Linux
#endif
}

void singup()
{
    char name[100];
    long number;
    int pin;
    int id = 2121;

    printf("\n\t\t\t\t Enter Your Name: ");
    scanf(" %[^\n]s", &name);
    printf("\n\t\t\t\t Enter Your Mobile Number: ");
    scanf("%ld", &number);
    printf("\n\t\t\t\t Enter A new PIN: ");
    scanf("%d", &pin);

    clear_screen();
    printf("\n\n \t\t\t\t********** SRF Bank Sign Up Success **********\n\n");
    printf("\n\t\t\t\tName Is %s", name);
    printf("\n\t\t\t\tPhone Number %ld", number);
    printf("\n\t\t\t\tID %d", id);
    printf("\n\t\t\t\tPIN For Account %d", pin);

    // Aper successfully sign up user redirect main page its your work

    printf("\n\n\n\n\n\n\n\n\n\n");
}

void login()
{
    int given_user_id, given_user_pin;

    printf("\n\t\t\t\t Enter Your Account Number: ");
    scanf("%d", &given_user_id);
    printf("\t\t\t\t Enter Your Account PIN: ");
    scanf("%d", &given_user_pin);
    Account data = db_operation(given_user_id, given_user_pin);

    if (data.accountNumber != 0)
    {
        clear_screen();
        printf("\n\n \t\t\t\t********** FSS Bank Log In Success **********\n\n");
        transaction(data);
    }
}

int main()
{
        clear_screen();
        printf("\n\n \t\t\t\t********** SRF Bank **********\n\n");
        printf("\t\t\t\t 1. Sign Up \n");
        printf("\t\t\t\t 2. Log In \n");
        printf("\t\t\t\t Q. Quit \n");

        printf("\n\n\t\t\t\t Select What You Want: ");
        scanf(" %c", &user_nav_comand);

        switch (user_nav_comand)
        {
        case '1':
            singup();
            break;
        case '2':
            login();
            break;
        case 'Q':
        case 'q':
            printf("\n\n\t\t\t\t\t Bye Bye \n");
            exit(0);
            break;
        }
    

    return 0;
}
