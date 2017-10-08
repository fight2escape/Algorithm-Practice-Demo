#include <iostream>
using namespace std;

int* generateArr(int n){
    int* arr = new int[n];
    for(int i=0; i<n; i++){
        arr[i] = rand() % n;
    }
    return arr;
}

void printArr(int arr[], int n){
    cout<<endl<<"------------------"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}


template<typename T>
void insertionSort(T arr[], int n){
    for(int i=1; i<n; i++){
        T tmp = arr[i];
        int pos = i;
        for(int j=i-1; j>=0; j--){
            if(arr[j] > tmp){
                arr[j+1] = arr[j];
                pos = j;
            }else{
                break;
            }
        }
        arr[pos] = tmp;
    }
}

template<typename T>
void InsertionSort(T arr[], int left, int right){
    for(int i=left+1; i<=right; i++){
        T tmp = arr[i];
        int pos = i;
        for(int j=i-1; j>=left; j--){
            if(arr[j] > tmp){
                arr[j+1] = arr[j];
                pos = j;
            }else{
                break;
            }
        }
        arr[pos] = tmp;
    }
}

int main() {
    int n = 30;
    int* arr = generateArr(n);
    printArr(arr, n);

//    insertionSort(arr, n);
    InsertionSort(arr, 0, 5);
    printArr(arr, n);
    return 0;
}


