//
// Created by Shinelon on 2017/9/12.
//

#ifndef LEETCODE_DEMO_MAIN_SORT_H
#define LEETCODE_DEMO_MAIN_SORT_H

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>

#include "SortTestHelper.h"
#include "Student.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort2.h"
#include "QuickSort3.h"

using namespace std;

int main()
{
    int n = 50000;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, 2);
    //    int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Quick Sort", QuickSort, arr1, n);
    SortTestHelper::testSort("Quick Sort2", QuickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort3", QuickSort3, arr3, n);
    SortTestHelper::testSort("Merge Sort", MergeSort, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    return 0;
}

#endif //LEETCODE_DEMO_MAIN_SORT_H
