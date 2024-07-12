#include <stdio.h>
#include <stdbool.h> 
#include <string.h> 
#include <stdlib.h>
  
int isdigit(int str);
int aito(int tasknumber);
int validateTaskNumber(int task);
void createAccount(long long int *account_no, char name[], int *balance);
void deposit(long long int account_no, int *balance);
void withdraw(long long int account_no, int *balance);
void checkBalance(long long int account_no, int balance);
void displayAccountDetails(long long int account_no, char name[], int balance);
bool isAccountValid(long long int account_no);
int isNumeric(const char *str);

int main()
 {
    char taskInput[10];
    int task, exit = 1;
    int balance = 0;
    char name[50] = "";
    long long int account_no = 0;

    printf("\n\n**** Project-2: Banking Management System ****\n");
    printf("\n1 - Create account");
    printf("\n2 - Deposit");
    printf("\n3 - Withdraw");
    printf("\n4 - Check balance");
    printf("\n5 - Display account details");
    printf("\n0 - Exit\n");

    while (exit != 0)
     {
        printf("\nPlease enter the task number: ");
        scanf("%s", &taskInput);
        if (isNumeric(taskInput))
        {
            task = atoi(taskInput);
        if (validateTaskNumber(task))
         {
            switch (task)
             {
                case 1:
                    createAccount(&account_no, name, &balance);
                    break;
                case 2:
                    deposit(account_no, &balance);
                    break;
                case 3:
                    withdraw(account_no, &balance);
                    break;
                case 4:
                    checkBalance(account_no, balance);
                    break;
                case 5:
                    displayAccountDetails(account_no, name, balance);
                    break;
                case 0:
                    exit = 0;
                    break;
            }
        }
         else
          {
            printf("\nPlease enter a valid task number\n");
        }
    }
    else
    {
        printf("\nPlease enter a valid task number\n");
    }
    }
    printf("You have left\n");
    return 0;
}

int validateTaskNumber(int task)
 {
    return (task >= 0 && task <= 5);
}

void createAccount(long long int *account_no, char name[], int *balance)
 {
    do
     {
        printf("\nPlease enter 11 digit account number only: ");
        scanf("%lld", account_no);
    }
     while (!isAccountValid(*account_no));

    printf("Please enter your account holder name: ");
    scanf("%s", name);

    do
     {
        printf("Please enter balance (Opening account should be 500 minimum): ");
        scanf("%d", balance);
    }
     while (*balance < 500);

    printf("\n\n*Thank you for joining India Bank*\nYour account details:\n");
    displayAccountDetails(*account_no, name, *balance);
}

void deposit(long long int account_no, int *balance) 
{
    int amount;
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);
    *balance += amount;
    printf("Amount deposited successfully. New balance: %d\n", *balance);
}

void withdraw(long long int account_no, int *balance)
 {
    int amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);
    if (amount > *balance)
     {
        printf("Insufficient balance.\n");
    } 
    else
     {
        *balance -= amount;
        printf("Amount withdrawn successfully. New balance: %d\n", *balance);
    }
}

void checkBalance(long long int account_no, int balance)
 {
    if (isAccountValid(account_no))
     {
        printf("Account Number: %lld\n", account_no);
        printf("Current Balance: %d\n", balance);
    }
     else
      {
        printf("Sorry! Please create an account first....\n");
    }
}

void displayAccountDetails(long long int account_no, char name[], int balance) 
{
    if (isAccountValid(account_no))
     {
        printf("Account Number: %lld\n", account_no);
        printf("Account Holder Name: %s\n", name);
        printf("Account Balance: %d\n", balance);
    }
     else
      {
        printf("Sorry! Please create an account first....\n");
    }
}
int isNumeric(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}
bool isAccountValid(long long int account_no)
 {
    return (account_no > 10000000000 && account_no < 100000000000);
}
