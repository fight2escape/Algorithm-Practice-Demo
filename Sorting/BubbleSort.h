//
// Created by Shinelon on 2017/9/10.
//

#ifndef LEETCODE_DEMO_BUBBLESORT_H
#define LEETCODE_DEMO_BUBBLESORT_H

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

//int n = 10000;
//int *arr = SortTestHelper::generateRandomArray(n, 1, 100);
//int *arr2 = SortTestHelper::copyIntArray(arr, n);
//int *arr3 = SortTestHelper::generateNearlyOrderedArray(n, 10000);
//int *arr4 = SortTestHelper::copyIntArray(arr3, n);
//SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
//SortTestHelper::testSort("Bubble Sort", BubbleSort, arr2, n);
//SortTestHelper::testSort("Bubble Sort", BubbleSort, arr3, n);
//SortTestHelper::testSort("Selection Sort", selectionSort, arr4, n);

//delete[] arr;
//delete[] arr2;
//delete[] arr3;
//delete[] arr4;
//delete[] arr;

#endif //LEETCODE_DEMO_BUBBLESORT_H
