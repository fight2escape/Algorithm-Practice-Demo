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

void __sort(int arr[], int l, int r){
    if(l >= r){
        return;
    }
    // partition
    swap(arr[l], arr[ rand()%(r-l+1)+l ]);
    int val = arr[l];
    int lt = l, gt = r+1;
    int i=l+1;
    while(i < gt){
        if(arr[i] > val){
            swap(arr[--gt], arr[i]);
        }else if(arr[i] < val){
            swap(arr[++lt], arr[i]);
            i++;
        }else{
            i++;
        }
    }
    // [l, lt-1], [lt, gt-1], [gt, r]
    swap(arr[l], arr[lt]);
    // recursive
    __sort(arr, l ,lt-1);
    __sort(arr, gt, r);
}

void sort(int arr[], int n){
    srand(time(NULL));
    __sort(arr, 0, n-1);
}

int main() {
    int n = 15000;
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


