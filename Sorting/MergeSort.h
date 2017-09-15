//
// Created by Shinelon on 2017/9/10.
//

#ifndef LEETCODE_DEMO_MERGESORT_H
#define LEETCODE_DEMO_MERGESORT_H

#include "InsertionSort.h"

template<typename T>
void __merge(T arr[], int left, int mid, int right) {
    // [left, mid] 和 [mid+1, right]
    int len = right - left + 1;
    T aux[len];
    for (int i = 0; i < len; i++) {
        aux[i] = arr[left + i];
    }

    int i = left;
    int j = mid + 1;
    for (int k = left; k <= right; k++) {
        if (i > mid) {
            arr[k] = aux[j-left];
            j++;
        }
        else if (j > right) {
            arr[k] = aux[i-left];
            i++;
        }
        else if (aux[i-left] < aux[j-left]) {
            arr[k] = aux[i-left];
            i++;
        }
        else {
            arr[k] = aux[j - left];
            j++;
        }
    }
}

template<typename T>
void __mergeSort(T arr[], int left, int right) {
//    if (left >= right) {
//        return;
//    }
    if(right - left <= 50 ) {
        InsertionSort(arr, left, right);
        return;
    }
    int mid = left + (right - left) / 2;
    __mergeSort(arr, left, mid);
    __mergeSort(arr, mid + 1, right);
    // 优化，对已经有序的数组不再执行一次归并
    if(arr[mid] > arr[mid+1]) {
        __merge(arr, left, mid, right);
    }
}

// 递归实现：自顶向下划分
//template<typename T>
//void MergeSort(T arr[], int n) {
//    // 闭区间
//    __mergeSort(arr, 0, n - 1);
//}

// 迭代实现：自底向上合并
template<typename T>
void MergeSort(T arr[], int n) {
    for(int sz = 1; sz <= n; sz += sz) {
        for(int i = 0; i+sz < n; i+= sz+sz) {
            __merge(arr, i, i+sz-1, min(i+sz+sz-1, n-1));
        }
    }
}

//int n = 50000;
//cout << "Test for Random Array, size = " << n << ", random range [0," << n << "]" << endl;
//int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
////    int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 1);
//int *arr2 = SortTestHelper::copyIntArray(arr1, n);
//
//SortTestHelper::testSort("Insertion Sort", InsertionSort, arr1, n);
//SortTestHelper::testSort("Merge Sort", MergeSort, arr2, n);
//
//cout<<endl;
//delete[] arr1;
//delete[] arr2;

#endif //LEETCODE_DEMO_MERGESORT_H
