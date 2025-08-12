#include<stdio.h>
#include<stdbool.h>
#define MX 100

int stack[MX];
int top = -1;

bool isEmpty(){
    return top == -1;
}
void push(int data){
    if(top == MX-1){
        puts("Stack Overflow!");
        return;
    }
    stack[++top] = data;
}
int pop(){
    if(isEmpty()){
        puts("Stack Underflow!");
        return -1;  // Error value
    }
    return stack[top--];
}

int main(){
    int n; 
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int adjMat[n][n];
    printf("Enter the adjacency matrix\n");

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &adjMat[i][j]);
        }
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    src--;

    int visited[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }

    push(src);
    visited[src] = 1;

    while(!isEmpty()){
        int temp = pop();
        printf("%c ", temp+'A');
        
        for(int j = 0; j < n; j++){
            if(adjMat[temp][j] && !visited[j]){
                push(j);
                visited[j] = 1;
            }
        }
    }
}