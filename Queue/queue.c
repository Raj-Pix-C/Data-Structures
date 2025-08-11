#include<stdio.h>
#include<stdlib.h>
#define MX 100

int queueArray[MX];
int front = -1, rear = -1;

int isEmpty(){
    return (front == -1);
}

int isFull(){
    return ((rear + 1) % MX == front);
}

void qInsert(int data){
    if(isFull()){
        puts("Queue Overflow!");
        return;
    }
    
    if(isEmpty()){
        front = rear = 0;
    }
    else{
        rear = (rear + 1) % MX;
    }
    
    queueArray[rear] = data;
    printf("Inserted %d\n", data);
}

int qDelete(){
    if(isEmpty()){
        puts("Queue Underflow!");
        return -1;
    }
    
    int temp = queueArray[front];
    
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % MX;
    }
    
    return temp;
}

void display(){
    if(isEmpty()){
        puts("Queue is empty");
        return;
    }
    
    printf("Queue: ");
    int i = front;
    while(1){
        printf("%d ", queueArray[i]);
        if(i == rear) break;
        i = (i + 1) % MX;
    }
    puts("");
}

int main(){
    int choice, data;
    
    while(1){
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                qInsert(data);
                break;
            case 2:
                data = qDelete();
                if(data != -1){
                    printf("Deleted data: %d\n", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                puts("Invalid choice!");
        }
    }
    
    return 0;
}