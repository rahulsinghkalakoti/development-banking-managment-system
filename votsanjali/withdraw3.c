

#include <stdio.h>


int isValidAccount(long long int account_no);
void withdraw(int *balance);

int main()
{
    long long int account_no;
    int balance = 5000; 

   
    printf("Enter your account number: ");
    scanf("%lld", &account_no);

    
    if (isValidAccount(account_no)) {
        printf("Your account balance is: %d\n", balance);
        
        withdraw(&balance);
        printf("Remaining balance: %d\n", balance);
    } else {
        printf("Sorry! Please create an account first....\n");
    }

    return 0;
}


int isValidAccount(long long int account_no)
{
    return (account_no > 10000000000 && account_no < 100000000000);
}


void withdraw(int *balance)
{
    int withdrawAmount;

    printf("Enter withdrawal amount: ");
    scanf("%d", &withdrawAmount);

 if (withdrawAmount <= 0) {
        printf("Invalid amount. Please enter a positive amount to withdraw.\n");
       
    }

    if (*balance - withdrawAmount >= 10) {
        *balance -= withdrawAmount;
        printf("%d rupees debited from your bank account\n", withdrawAmount);
    } else {
        printf("You cannot withdraw %d rupees. Minimum balance should be 10 rupees.\n", withdrawAmount);
        printf("Your current balance is: %d\n", *balance);
}
}
