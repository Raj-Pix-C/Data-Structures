#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    Node * left;
    Node * right;
}Node;

Node * createNode(int data){
    Node * newNode = (Node *) malloc(sizeof(Node));

    if(!newNode){
        puts("Memory error!");
        return NULL;
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void buildTree(Node * root, int nodes[], int k, int n){
    if(2*k < n && nodes[2*k] != 0) {
        (root)->left = createNode(nodes[2*k]);
        buildTree(root->left, nodes, 2*k, n);
    }
    if(2*k+1 < n && nodes[2*k+1] != 0){
        (root)->right = createNode(nodes[2*k+1]);
        buildTree(root->right, nodes, 2*k+1, n);
    }
}

void inorder(Node * root){
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    n++;

    int nodes[n];
    nodes[0] = 0;
    printf("Enter the node values (0 for NULL): ");

    for(int i = 1; i < n; i++) {
        scanf("%d", &nodes[i]);
    }
    
    if(nodes[1] == 0) {
        puts("Empty tree!");
        return 0;
    }
    
    Node * root = createNode(nodes[1]);
    buildTree(root, nodes, 1, n);
    
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    
    return 0;
}