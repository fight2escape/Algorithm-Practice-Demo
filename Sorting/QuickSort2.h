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
    // [left+1, i] <= v
    // [j, right] >= v
    int i = left+1, j = right;
    while(true) {
        while(i <= right && arr[i] < v) { i++; }
        while(j > left && arr[j] > v) { j--; }
        if(i > j) {
            break;
        }
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[left], arr[j]);
    return j;
}

template<typename T>
void __quickSort2(T arr[], int left, int right){
    if(right - left <= 15) {
        InsertionSort(arr, left, right);
        return ;
    }
    int p = __partition2(arr, left, right);
    __quickSort2(arr, left, p-1);
    __quickSort2(arr, p+1, right);
}

template<typename T>
void QuickSort2(T arr[], int n) {
    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}

#endif //LEETCODE_DEMO_QUICKSORT2_H
