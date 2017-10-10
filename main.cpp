#include <iostream>
#include <ctime>
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
bool isSorted(int arr[], int n){
    while(--n){
        if(arr[n] < arr[n-1]){
            return false;
        }
    }
    return true;
}
//------------------------------------------------

template<typename T>
void InsertionSort(T arr[], int l, int r){
    for(int i=l+1; i<=r; i++){
        T val = arr[i];
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
    return;
}


template<typename T>
void __merge(T arr[], int l, int mid, int r){
    int i=l, j=mid+1;
    int n = r-l+1;
    T tmp[n];
    int k = 0;

    while(i<=mid && j<=r){
        if(arr[i] <= arr[j]){
            tmp[k] = arr[i++];
        }else{
            tmp[k] = arr[j++];
        }
        k++;
    }
    while(i<=mid){
        tmp[k++] = arr[i++];
    }
    while(j<=r){
        tmp[k++] = arr[j++];
    }
    for(int i=0; i<k; i++){
        arr[i+l] = tmp[i];
    }
    return;
}

template<typename T>
void __mergeSort(T arr[], int l, int r){
    if(r-l <= 15){
        InsertionSort(arr, l, r);
        return;
    }


    int mid = l + (r-l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1,r);
    if(arr[mid] > arr[mid+1]){
        __merge(arr, l, mid, r);
    }
    return;
}

template<typename T>
void MergeSort(T arr[], int n){
    __mergeSort(arr, 0, n-1);
}

template<typename T>
void MergeSortPro(T arr[], int n){
    for(int i=1; i<n; i+=i){
        for(int j=0; j+i<n; j+= i+i){
            __merge(arr, j, j+i-1, min(n-1, j+i+i-1));
        }
    }
}

int main() {
    int n = 500000;
    bool print = 0;
    int* arr = generateArr(n);
    if(print) printArr(arr, n);
    time_t start = clock();


    MergeSort(arr, n);




    time_t end = clock();
    if(print) printArr(arr, n);
    if(!isSorted(arr, n)) cout<<endl<<endl<<"not sorted!!!"<<endl;
    cout<<endl<<"Spending: "<< double(end-start)/double(CLOCKS_PER_SEC) <<" s"<<endl;
    return 0;
}


