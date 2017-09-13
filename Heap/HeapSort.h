//
// Created by Shinelon on 2017/9/13.
//

#ifndef LEETCODE_DEMO_HEAPSORT_H
#define LEETCODE_DEMO_HEAPSORT_H

#include "Heap.h"
#include "SortTestHelper.h"
#include "sorting/QuickSort3.h"

template<typename T>
void HeapSort1(T arr[], int n) {
    MaxHeap<T> mh = MaxHeap<T>(n);
    for(int i = 0; i < n; i++) {
        mh.insert( arr[i] );
    }
    for(int i = n-1; i >= 0; i--) {
        arr[i] = mh.extractMax();
    }
}

template<typename T>
void HeapSort2(T arr[], int n) {
    MaxHeap<T> mh = MaxHeap<T>(arr, n);
    for(int i=n-1; i>=0; i--) {
        arr[i] = mh.extractMax();
    }
}

#endif //LEETCODE_DEMO_HEAPSORT_H

//int n = 10000000;
//
//int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
//int *arr2 = SortTestHelper::copyIntArray(arr1, n);
//int *arr21 = SortTestHelper::copyIntArray(arr1, n);
//SortTestHelper::testSort("Heap Sort1", HeapSort1, arr1, n);
//SortTestHelper::testSort("Heap Sort2", HeapSort2, arr21, n);
//SortTestHelper::testSort("Quick Sort3", QuickSort3, arr2, n);
//cout<<endl<<"================"<<endl;
//
//int *arr3 = SortTestHelper::generateRandomArray(n, 0, 10);
//int *arr4 = SortTestHelper::copyIntArray(arr3, n);
//int *arr41 = SortTestHelper::copyIntArray(arr3, n);
//SortTestHelper::testSort("Heap Sort1", HeapSort1, arr3, n);
//SortTestHelper::testSort("Heap Sort2", HeapSort2, arr41, n);
//SortTestHelper::testSort("Quick Sort3", QuickSort3, arr4, n);
//cout<<endl<<"================"<<endl;
//
//int *arr5 = SortTestHelper::generateNearlyOrderedArray(n, 10);
//int *arr6 = SortTestHelper::copyIntArray(arr5, n);
//int *arr61 = SortTestHelper::copyIntArray(arr5, n);
//SortTestHelper::testSort("Heap Sort1", HeapSort1, arr5, n);
//SortTestHelper::testSort("Heap Sort2", HeapSort2, arr61, n);
//SortTestHelper::testSort("Quick Sort3", QuickSort3, arr6, n);
//cout<<endl<<"================"<<endl;