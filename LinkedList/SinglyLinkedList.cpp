#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    node * next;
}node;

node * createNode(int data){
    node * newNode = (node *) malloc(sizeof(node));

    if(newNode == NULL){
        puts("Failed to create node");
        exit(0);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertNode(node ** head, int data, int pos){
    node * newNode = createNode(data);

    if(!pos){ // insert at front of list
        newNode->next = *head;
        *head = newNode;
    }
    else{ // instert at back of list
        if(*head == NULL){ // If list is empty, insert as first node
            *head = newNode;
        }
        else{
            node * temp = *head;

            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

void deleteNode(node ** head, int key){
    if(*head == NULL){
        puts("List is empty");
        return;
    }

    node * temp = *head;
    node * prev = NULL;

    if(temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Node with data %d not found\n", key);
    }
    else{
        prev->next = temp->next;
        free(temp);
        printf("Node with data %d deleted\n", key);
    }
}

void printList(node ** head){
    if(*head == NULL){
        puts("List is empty");
        return;
    }

    node * temp = *head;

    while(temp != NULL){
        printf("%d", temp->data);
        temp->next != NULL ? printf(" -> ") : puts("");
        temp = temp->next;
    }
    return;
}

void freeList(node ** head){
    node * temp = *head;

    while(temp != NULL){
        node * nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    *head = NULL;
    return;
}

void menu(node ** head){
    // system("cls");

    puts("Linked List Operations:");

    puts("1. Insert Node");
    puts("2. Delete Node");
    puts("3. Print List");
    puts("4. Free List");
    puts("5. Exit");

    puts("Enter your choice:");

    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1: {
            int data, pos;
            puts("Enter data to insert:");
            scanf("%d", &data);
            puts("Enter position (0 for front, 1 for back):");
            scanf("%d", &pos);
            insertNode(head, data, pos);
            break;
        }
        case 2: {
            int key;
            puts("Enter data of node to delete:");
            scanf("%d", &key);
            deleteNode(head, key);
            break;
        }
        case 3:
            printList(head);
            break;
        case 4:
            freeList(head);
            puts("List freed.");
            break;
        case 5:
            exit(0);
        default:
            puts("Invalid choice. Try again.");
            menu(head);
    }
}

int main(){
    node * head = NULL;

    while(1)menu(&head);

    freeList(&head); // Free the list before exiting
    return 0;
}