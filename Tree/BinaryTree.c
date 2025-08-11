#include<stdio.h>
#include<stdlib.h>


typedef struct Node {  // Definition of a binary tree node
    int data;
    Node* left;
    Node* right;
}Node;

Node* createNode(int data) {  // Function to create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(Node* root) {  // Inorder traversal
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node * root){
    if(root == NULL) return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node * root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {  // Example usage
    Node * root = createNode(1);                          //       1       //
    root->left = createNode(2);                           //      / \      //
    root->right = createNode(3);                          //     2   3     //
    root->left->left = createNode(4);                     //    / \ / \    //
    root->left->right = createNode(5);                    //   4  5 6  7   //
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}