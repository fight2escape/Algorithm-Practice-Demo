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
        for(int j=i-1; j>=l ;j--){
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


template<typename T>
void __sort(T arr[], int l, int r){
    if(r-l <= 15){
        InsertionSort(arr, l, r);
        return;
    }

    swap(arr[l], arr[ rand()%(r-l+1)+l ]);
    T val = arr[l];
    int lt=l, gt=r+1, i=l+1;
    while(i<gt){
        if(arr[i] < val){
            swap(arr[i++], arr[++lt]);
        }else if(arr[i] > val){
            swap(arr[i], arr[--gt]);
        }else{
            i++;
        }
    }
    swap(arr[l], arr[lt]);

    __sort(arr, l, lt-1);
    __sort(arr, gt, r);
    return;
}

template<typename T>
void sort(T arr[], int n){
    srand(time(NULL));
    __sort(arr, 0, n-1);
}

int main() {
    int n = 1500000;
    bool print = 0;
    int* arr = generateArr(n);
    if(print) printArr(arr, n);
    time_t start = clock();


    sort(arr, n);




    time_t end = clock();
    if(print) printArr(arr, n);
    if(!isSorted(arr, n)) cout<<endl<<endl<<"not sorted!!!"<<endl;
    cout<<endl<<"Spending: "<< double(end-start)/double(CLOCKS_PER_SEC) <<" s"<<endl;
    return 0;
}


