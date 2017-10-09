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

//------------------------------------------------//

void InsertionSort(int arr[], int l, int r){
    for(int i=l+1; i<=r; i++){
        int val = arr[i];
        int pos = i;
        for(int j=i-1; j>=l; j--){
            if(arr[j] > val){
                arr[j+1] = arr[j];
                pos = j;
            }else{
                break;
            }
        }
        arr[pos] = val;
    }
}

void merge(int arr[], int l, int mid, int r){
    int i = l, j= mid+1;
    int n = r-l+1;
    int *tmp = new int[n];
    int ti = 0;
    while(i<=mid && j<=r){
        if(arr[i] <= arr[j]){
            tmp[ti++] = arr[i++];
        }else{
            tmp[ti++] = arr[j++];
        }
    }
    while(i<=mid){
        tmp[ti++] = arr[i++];
    }
    while(j<=r){
        tmp[ti++] = arr[j++];
    }
    for(int i=l; i<=r; i++){
        arr[i] = tmp[i-l];
    }
}

void __mergeSort(int arr[], int l, int r){
    if(r-l <= 10){
        InsertionSort(arr, l ,r);
        return;
    }
    int mid = l + (r-l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if(arr[mid] > arr[mid+1]){
        merge(arr, l, mid, r);
    }
}

void MergeSort(int arr[], int n){
    __mergeSort(arr, 0, n-1);
}


// 迭代实现
void MergeSort2(int arr[], int n){
    for(int i=1; i<n; i++){
        for(int j=0; j+i<n; j++){
            merge(arr, j, j+i-1, min(j+i+i, n-1));
        }
    }
}


int main() {
    int n = 15;
    int* arr = generateArr(n);
    printArr(arr, n);

//    MergeSort(arr, n);
    MergeSort2(arr, n);

    printArr(arr, n);


    return 0;
}


