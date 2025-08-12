#include<stdio.h>
#include<stdbool.h>
#define MX 100

int queue[MX];
int front = -1, rear = -1;

bool isEmpty(){
    return (front == -1 || front > rear);
}

void qInsert(int data){
    if(front == -1){
        front = rear = 0;
        queue[rear] = data;
    } else {
        queue[++rear] = data;
    }
}

int qDelete(){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return -1;  // Error value
    }
    int temp = queue[front++];
    if(front > rear){  // Queue becomes empty
        front = rear = -1;
    }
    return temp;
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

    int src, dest;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    printf("Enter the destination vertex: ");
    scanf("%d", &dest);
    src--, dest--;

    int visited[n];
    int origin[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
        origin[i] = -1;
    }    
    
    qInsert(src);
    visited[src] = 1;


    while(!isEmpty()){
        int temp = qDelete();
        if(temp == -1) break;

        for(int j = 0; j < n; j++){
            if(adjMat[temp][j] && !visited[j]){
                qInsert(j);
                visited[j] = 1;
                origin[j] = temp;
                if(j == dest) break;
            }
        }
    }

    
    if(origin[dest] == -1) puts("No path found!");
    else{
        int temp = dest;
        printf("%c ", dest+'A');
        while(temp != src){
            printf(" <- %c", origin[temp]+'A');
            temp = origin[temp];
        }
        printf("\n");
    }
}
