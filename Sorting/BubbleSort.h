//
// Created by Shinelon on 2017/9/10.
//

#ifndef LEETCODE_DEMO_BUBBLESORT_H
#define LEETCODE_DEMO_BUBBLESORT_H

template<typename T>
void BubbleSort(T arr[], int n) {
    for (int i = n-1; i > 0; i--) {
        int newn = -1;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
                newn = j + 1;
            }
        }
        // 记录最后一次交换的位置设置为n的值
        // 如果近乎有序，可以节省大量时间
        if (newn < 0) {
            break;
        }
        n = newn + 1;
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
