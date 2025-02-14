#include<iostream>

using namespace std;

int main(){

    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

    int low, high, mid, target;
    low = 0, high = (sizeof(arr)/sizeof(arr[0])) - 1;

    cin >> target;
    cout << endl;

    while (low <= high){
        mid = (low + high) / 2;

        if(target < arr[mid]){
            high = mid - 1;
        }
        else if(target > arr[mid]){
            low = mid + 1;
        }
        else if(target == arr[mid]){
            cout << "Target found at index: " << mid << endl;
            exit(0);
        }
    }
    
    cout << "Target not found\n";
    return 0;
}