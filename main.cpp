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
//------------------------------------------------//


int __partition(int arr[], int l, int r){
    swap(arr[l], arr[ rand()%(r-l+1)+l ]);
    int val = arr[l];
    int i=l+1, j=r+1;
    // [l+1, j-1], [j, r]
    while(true){
        while(i<j && arr[i]<=val) i++;
        while(i<j && arr[j-1]>=val) j--;
        if(i>=j) break;
        swap(arr[i], arr[j-1]);
        i++;
        j--;
    }
    swap(arr[l], arr[j-1]);
    return j-1;
}

void __sort(int arr[], int l, int r){
    if(l >= r){
        return;
    }
    int mid = __partition(arr, l, r);
    __sort(arr, l, mid-1);
    __sort(arr, mid+1, r);
}

void sort(int arr[], int n){
    srand(time(NULL));
    __sort(arr, 0, n-1);
}

int main() {
    int n = 15;
    int* arr = generateArr(n);
    printArr(arr, n);


    sort(arr, n);



    printArr(arr, n);
    return 0;
}


