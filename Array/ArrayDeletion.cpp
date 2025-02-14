#include<iostream>
#define MX 10
using namespace std;

void delAtStrt(int arr[]){
    for(int i = 0; i < MX-1; i++){
        arr[i] = arr[i+1];
    }
}
void delAtEnd(int arr[]){
    for(int i = MX-1; i >= 0; i--){
        if(arr[i] != 0){
            arr[i] = 0;
            return;
        }
    }
}
void delAtGivenPos(int arr[], int pos){
    for(int i = pos; i < MX; i++){
        arr[i] = arr[i+1];
    }
}
void delVal(int arr[], int key){
    int pos;
    for(int j = 0; j < MX-1; j++){
        if(arr[j] == key){
            pos = j;
            break;
        }
    }
    for(int i = pos; i < MX; i++){
        arr[i] = arr[i+1];
    }
}
void printArr(int arr[]){
    for(int i = 0; i < MX; i++){
        cout << arr[i]  << " ";
    }cout << endl;
}


int main(){
    int key = 1, pos = 7;
    int arr[MX] = {2, 6, 7, 0 ,4, 3, 1, 8, 9, 10};

    // delAtStrt(arr);
    // delAtEnd(arr);
    // delAtGivenPos(arr, pos);
    // delVal(arr, key);

    printArr(arr);
    return 0;
}