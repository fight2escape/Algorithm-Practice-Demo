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


template<typename T>
void BubbleSort(T arr[], int n){
    int newi;
    for(int i=n-1; i>0; i = newi){
        newi = -1;
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
                // 记录最后一次交换的位置设置为n的值
                // 如果近乎有序，可以节省大量时间
                newi = j+1;
            }
        }
        if(!newi) break;
    }
}


int main() {
    int n = 15;
    int* arr = generateArr(n);
    printArr(arr, n);

    BubbleSort(arr, n);

    printArr(arr, n);
    return 0;
}


