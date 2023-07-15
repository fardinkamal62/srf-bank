#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "transaction.h"
#include "db_operation.h"

char user_nav_command;

void clear_screen()
{
#ifdef _WIN32
    system("cls"); // Clear screen on Windows
#else
    system("clear"); // Clear screen on Linux
#endif
};

void login()
{
    int given_user_id, given_user_pin;

    printf("\n\t\t\t\t\t Enter Your Account Number: ");
    scanf("%d", &given_user_id);
    printf("\t\t\t\t\t Enter Your Account PIN: ");
    scanf("%d", &given_user_pin);
    Account data = db_operation(given_user_id, given_user_pin);

    if (data.accountNumber != 0)
    {
        clear_screen();
        printf("\n\t\t\t\t\t********** SRF Bank Log In Success **********\n\n");
        transaction(data);
    }
};

void signup()
{
    char name[MAX_LINE_LENGTH];
    long number;
    int pin;

    srand(time(NULL));
    int id = rand() % 9000 + 1000;

    printf("\n\t\t\t\t Enter Your Name: ");
    scanf(" %[^\n]s", &name);
    printf("\n\t\t\t\t Enter Your NID Number: ");
    scanf("%ld", &number);
    printf("\n\t\t\t\t Enter A new PIN: ");
    scanf("%d", &pin);

    clear_screen();
    printf("\n\t\t\t\t\t********** SRF Bank Sign Up Success **********\n\n");
    printf("\n\t\t\t\t Name is %s", name);
    printf("\n\t\t\t\t NID Number %ld", number);
    printf("\n\t\t\t\t Account Number %d", id);
    printf("\n\t\t\t\t PIN For Account %d", pin);
    printf("\n\t\t\t\t Redirecting to login page...\n");
    appendAccountToCSV(id, name, pin, 0, 0);

    sleep(5);
    login();
};

int main()
{
    clear_screen();
    printf("\n\t\t\t\t\t********** SRF Bank **********\n\n");
    printf("\t\t\t\t\t\t 1. Sign Up \n");
    printf("\t\t\t\t\t\t 2. Log In \n");
    printf("\t\t\t\t\t\t Q. Quit \n");

    while (1)
    {
        printf("\n\n\t\t\t\t\t Select Option: ");
        scanf(" %c", &user_nav_command);
        switch (user_nav_command)
        {
        case '1':
            signup();
            break;
        case '2':
            login();
            break;
        case 'Q':
        case 'q':
            printf("\n\n\t\t\t\t\t\t Bye Bye! \n");
            exit(0);
        default:
            printf("\n\n\t\t\t\t\t\t Invalid Entry");
            break;
        }
    }
    return 0;
};
