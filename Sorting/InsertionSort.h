//
// Created by Shinelon on 2017/9/10.
//

#ifndef LEETCODE_DEMO_INSERTIONSORT_H
#define LEETCODE_DEMO_INSERTIONSORT_H

template<typename T>
void InsertionSort(T arr[], int n) {
    for(int i=1; i<n; i++){
        T tmp = arr[i];
        for(int j=i-1; j>=0; j--){
            if(arr[j] > tmp){
                swap(arr[j], arr[j+1]);
            }else{
                break;
            }
        }
    }
}

template<typename T>
void InsertionSortPro(T arr[], int n) {
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

//int n = 10000;
////int *arr = SortTestHelper::generateRandomArray(n, 0, n);
//int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
//int *arr2 = SortTestHelper::copyIntArray(arr, n);
//
//SortTestHelper::testSort("Insertion Sort", InsertionSort, arr, n);
//SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);
//
//delete[] arr;
//delete[] arr2;

#endif //LEETCODE_DEMO_INSERTIONSORT_H
