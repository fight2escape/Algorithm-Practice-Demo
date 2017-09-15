//
// Created by Shinelon on 2017/9/10.
//

#ifndef LEETCODE_DEMO_SELECTIONSORT_H
#define LEETCODE_DEMO_SELECTIONSORT_H

template<typename T>
void SelectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

//int n = 30000;
//int *arr = SortTestHelper::generateRandomArray(n, 0, 4);
//SortTestHelper::testSort("Selection Sort:", SelectionSort, arr, n);
//selectionSort(arr, n);
//SortTestHelper::printArray(arr, n);

//float b[4] = { 4.4, 3.3, 2.2, 1.1 };
//selectionSort(b, 4);
//SortTestHelper::printArray(b, 4);
//
//string c[4] = { "A", "B", "C", "D" };
//selectionSort(c, 4);
//SortTestHelper::printArray(c, 4);
//
//Student d[4] = { {"D", 90}, {"C", 100}, {"B", 95}, {"A", 95} };
//selectionSort(d, 4);
//SortTestHelper::printArray(d, 4);

#endif //LEETCODE_DEMO_SELECTIONSORT_H
