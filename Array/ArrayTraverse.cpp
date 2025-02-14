#include<iostream>
#define MX 10
using namespace std;

void printArr(int arr[]){
    for(int i = 0; i < MX; i++){
        cout << arr[i]  << " ";
    }cout << endl;
}
void inputArr(int arr[]){
    for(int i = 0; i < MX; i++){
        cin >> arr[i];
    }
}

int main(){
    int key = 5;
    int arr[MX];   
    
    inputArr(arr);
    printArr(arr);
    return 0;
}