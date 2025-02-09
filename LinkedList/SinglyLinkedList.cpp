#include<iostream>
#include<stdlib.h>
using namespace std;


typedef struct Node{
    int data;
    Node * next;
}Node;

Node * CreateNode(int data){
    Node * CurrentNode;

    Node * NewNode = (Node *) malloc(sizeof(Node));

    if(NewNode == NULL){
        cout << "No new node allocated\n";
        exit(0);
    }
    NewNode->data = data;
    NewNode->next = NULL;

    return NewNode;
}

void insertAtBeginning(Node ** head, int data){
    Node * NewNode = CreateNode(data);

    NewNode->next = *head;
    *head = NewNode;
    return;
}

void insertAtEnd(Node ** tail, int data){
    Node * NewNode = CreateNode(data);

    if(*tail == NULL){
        *tail = NewNode;
        return;
    }
    Node * temp = *tail;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = NewNode;
    return;
}

void deleteNode(Node ** head, int key){
    Node * temp = *head;
    Node * prev = NULL;
    if (temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        cout << "Node with key=" << key << " deleted.\n";
        return;
    }

    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node with key=" << key << " not found.\n";
        return;
    }

    prev->next = temp->next;
    free(temp);
    cout << "Node with key=" << key << " deleted\n";
}

void searchNode(Node * head, int key){
    Node * temp = head;
    while (temp != NULL){
        if(temp->data == key){
            cout << "Node found\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Node not found.\n";
    return;
}

void displayList(Node * head){
    if(head == NULL){
        cout << "Empty list.\n";
        return;
    }
    Node * temp = head;
    while (temp != NULL){
        cout << temp->data;
        temp = temp->next;
        if(temp != NULL)
            cout << " -> ";
    }
    cout << endl;
    return;    
}


int main(){

    Node * Head = NULL;
    int value, choice;

    do{
        cout << "Choose number from menu for operation\n\n";
        cout << "1.Insert at beginning\n2.Insert at end\n";
        cout << "3.Delete a node\n4.Search a key\n";
        cout << "5.Display list\n6.Exit\n";
        cin >> choice;

        if(choice == 1){
            cout << "Enter the Value of the node:";
            cin >> value;
            insertAtBeginning(&Head, value);
        }
        else if(choice == 2){
            cout << "Enter the Value of the node:";
            cin >> value;
            insertAtEnd(&Head, value);
        }
        else if(choice == 3){
            cout << "Enter the Value of the node:";
            cin >> value;
            deleteNode(&Head, value);
        }
        else if(choice == 4){
            cout << "Enter the Value of the node:";
            cin >> value;
            searchNode(Head, value);
        }
        else if(choice == 5){
            displayList(Head);
        }
        else exit(0);
    }while(choice);

    return 0;
}