#include<stdio.h>
#include<stdlib.h>
#define MX 100

int stackArray[MX];
int top = -1;

void push(int data){
    if(top == MX-1){
        puts("Stack Overflow!");
        exit(0);
    }
    stackArray[(++top)] = data;
}

int pop(){
    if(top == -1){
        puts("Stack Underflow!");
        exit(0);
    }
    return stackArray[(top--)];
}

int main(){

    while(1){
        int choice, data;
        printf("1. Push\n2. Pop\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                printf("Popped data: %d\n", pop());
                break;
            case 3:
                exit(0);
            default:
                puts("Invalid choice!");
        }
    }
}