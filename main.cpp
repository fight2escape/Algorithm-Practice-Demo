#include <iostream>
using namespace std;

template<typename T>
void selectionSort(T* arr, int n){
    for(int i=0; i<n; i++){
        int pos = i;
        for(int j=i+1; j<n; j++)
            if(arr[j] < arr[i])
                pos = j;
        if(i != pos)
            swap(arr[i], arr[pos]);
    }
}


int main() {
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(int);
    selectionSort(arr, n);
    for(auto a : arr){
        cout<<a<<" ";
    }
    return 0;
}