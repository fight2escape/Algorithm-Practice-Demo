//
// Created by Shinelon on 2017/9/11.
//

#ifndef LEETCODE_DEMO_QUICKSORT_H
#define LEETCODE_DEMO_QUICKSORT_H

#include <iostream>
#include <ctime>
#include "InsertionSort.h"
using namespace std;

template<typename T>
int __partition(T arr[], int left, int right) {
    swap(arr[left], arr[rand() % (right-left+1) + left]);

    T v = arr[left];
    int j = left;
    for(int i = left+1; i <= right; i++) {
        if(arr[i] < v) {
            swap(arr[i], arr[++j]);
        }
    }
    swap(arr[left], arr[j]);
    return j;
}

template<typename T>
void __quickSort(T arr[], int left, int right) {
    // [left, right]
//    if(left >= right) {
//        return;
//    }
    if( right - left <= 15) {
        InsertionSort(arr, left, right);
        return;
    }
    int p = __partition(arr, left, right);
    __quickSort(arr, left, p-1);
    __quickSort(arr, p+1, right);
}

template<typename T>
void QuickSort(T arr[], int n) {
    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}

#endif //LEETCODE_DEMO_QUICKSORT_H
