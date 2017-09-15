//
// Created by Shinelon on 2017/9/11.
//

#ifndef LEETCODE_DEMO_QUICKSORT2_H
#define LEETCODE_DEMO_QUICKSORT2_H

#include <iostream>
#include <ctime>
#include "InsertionSort.h"

using namespace std;

template<typename T>
int __partition2(T arr[], int left, int right) {
    swap(arr[left], arr[rand() % (right - left + 1) + left]);
    T v = arr[left];
    // [left+1, j-1], [j, right]
    int j = right+1, i = left+1;
    while(true) {
        while(i < j && arr[i] <= v) { i++; }
        while(j > i && arr[j-1] >= v) { j--; }
        if(i >= j) { break; }
        swap(arr[i], arr[j-1]);
        i++;
        j--;
    }
    swap(arr[left], arr[j-1]);
    return j-1;
}

template<typename T>
void __quickSort2(T arr[], int left, int right) {
    // return
    if(right - left <= 15) {
        InsertionSort(arr, left, right);
        return;
    }
    // partition
    int p = __partition2(arr, left, right);
    // recursion
    __quickSort2(arr, left, p-1);
    __quickSort2(arr, p+1, right);
}

template<typename T>
void QuickSort2(T arr[], int n) {
    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}

#endif //LEETCODE_DEMO_QUICKSORT2_H
