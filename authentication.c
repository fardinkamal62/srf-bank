#include<stdio.h>
#include<stdlib.h>
int user_nav_comand;

void singup(){
    char name[100];
    long number;
    int pin;
    int id = 2121;

    printf("\n\t\t\t\t Enter Your Name: ");
    scanf(" %[^\n]s", &name);
    printf("\n\t\t\t\t Enter Your Mobile Number: ");
    scanf("%ld",&number);
    printf("\n\t\t\t\t Enter A new PIN: ");
    scanf("%d",&pin);



    system("cls");
    printf("\n\n \t\t\t\t********** FSS Bank Sign Up Success **********\n\n");
    printf("\n\t\t\t\tName Is %s",name);
    printf("\n\t\t\t\tPhone Number %ld",number);
    printf("\n\t\t\t\tID %d",id);
    printf("\n\t\t\t\tPIN For Account %d",pin);

    // Aper successfully sign up user redirect main page its your work

    printf("\n\n\n\n\n\n\n\n\n\n");


}
void login(){
    int user_id = 1010,user_pin = 1010;
    int given_user_id,given_user_pin;

    printf("\t\t\t\t Enter Your Account Number: ");
    scanf("%d",&given_user_id);
    printf("\n");
    printf("\t\t\t\t Enter Your Account PIN: ");
    scanf("%d",&given_user_pin);

    if(given_user_id == user_id && given_user_pin == user_pin){
        system("cls");
        printf("\n\n \t\t\t\t********** FSS Bank Log In Success **********\n\n");


        // Aper successfully Log in user redirect main page its your work

    }


}
int main(){

    printf("\n\n \t\t\t\t********** FSS Bank **********\n\n");
    printf("\t\t\t\t 1. Sign Up \n");
    printf("\t\t\t\t 2. Log In \n");

    printf("\n\n\t\t\t\t Select What You Want: ");
    scanf("%d",&user_nav_comand);
    switch(user_nav_comand){

    case 1:
        singup();
        break;

    case 2:
        login();
        break;
    }


}
