#include<iostream>
#define MX 10
using namespace std;

void inAtStrt(int arr[], int key){
    for(int i = MX-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = key;
}
void inAtEnd(int arr[], int key){
    arr[MX-1] = key;
}
void inAtGivenPos(int arr[], int key, int pos){
    for(int i = MX-1; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = key;
}
void inAfterVal(int arr[], int key, int val){
    int pos;
    for(int j = 0; j < MX-1; j++){
        if(arr[j] == val){
            pos = j+1;
            break;
        }
    }
    for(int i = MX-1; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = key;
}
void printArr(int arr[]){
    for(int i = 0; i < MX; i++){
        cout << arr[i]  << " ";
    }cout << endl;
}

int main(){
    int key = 5;
    int arr[MX] = {2, 6, 7, 0 ,4, 3, 1, 8, 9, 10};   

    //inAtStrt(arr, key);
    //inAtEnd(arr, key);
    //inAtGivenPos(arr, key, 9);
    //inAfterVal(arr, key, 0);
    
    printArr(arr);
    return 0;
}