#include <stdio.h>

int validatetasknumber(int task) {
    return (task >= 0 && task <= 4);
}

void displaytasknumber(int task) {
    if (validatetasknumber(task)) {
        printf("Task number %d is valid.\n", task);
    } else {
        printf("Task number %d is invalid.\n", task);
    }
}

int main() {
    int task1;
    int task2;

    displaytasknumber(task1);
    displaytasknumber(task2);

    return 0;
}