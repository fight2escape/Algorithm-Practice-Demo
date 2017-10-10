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


void Bubble(int arr[], int n){
    for(int i=n-1; i>0; i--){
        int pos = -1;
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;

                pos = j+1;
            }
        }
        if(pos==-1) break;
        i = pos;
    }
}

int main() {
    int n = 150000;
    bool print = 0;
    int* arr = generateArr(n);
    if(print) printArr(arr, n);
    time_t start = clock();


    Bubble(arr, n);

    time_t end = clock();
    if(print) printArr(arr, n);
    if(!isSorted(arr, n)) cout<<endl<<endl<<"not sorted!!!"<<endl;
    cout<<endl<<"Spending: "<< double(end-start)/double(CLOCKS_PER_SEC) <<" s"<<endl;
    return 0;
}


