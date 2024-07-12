#include <stdio.h>

void displayAccountDetails(long long int account_no, char name[], int balance) {
    printf("Account number: %lld\n", account_no);
    printf("Account holder name: %s\n", name);
    printf("Account balance: %d\n\n", balance);
}

int main() {
    long long int account_no = 10000000000;
    char name[50];
    int balance;

    displayAccountDetails(account_no, name, balance);

    return 0;
}