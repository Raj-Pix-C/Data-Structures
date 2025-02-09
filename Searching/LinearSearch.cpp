#include<iostream>

using namespace std;

int main(){

    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

    int n, target;
    n = (sizeof(arr)/sizeof(arr[0]));
    cin >> target;
    cout << endl;

    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            cout << "Target found at index: " << i << endl;
            exit(0);
        }
    }

    cout << "Target not found\n";
    return 0;
}