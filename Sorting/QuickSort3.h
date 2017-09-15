//
// Created by Shinelon on 2017/9/11.
//

#ifndef LEETCODE_DEMO_QUICKSORT3_H
#define LEETCODE_DEMO_QUICKSORT3_H

#include <iostream>
#include <ctime>
#include "InsertionSort.h"

using namespace std;

template<typename T>
void __quickSort3(T arr[], int left, int right) {
    // return
    if(right - left <= 15) {
        InsertionSort(arr, left, right);
        return ;
    }
    // partition
    swap(arr[left], arr[rand() % (right - left + 1) + left]);
    T v = arr[left];
    // [left+1, lt], [lt+1, gt-1], [gt, right]
    int lt = left, gt = right+1, i = left+1;
    while(i < gt) {
        if(arr[i] < v) {
            if(i > lt+1) {
                swap(arr[lt+1], arr[i]);
            }
            lt++;
            i++;
        }else if(arr[i] > v) {
            swap(arr[--gt], arr[i]);
        }else{
            i++;
        }
    }
    // recursion
    __quickSort3(arr, left, lt);
    __quickSort3(arr, gt, right);
}

template<typename T>
void QuickSort3(T arr[], int n) {
    srand(time(NULL));
    __quickSort3(arr, 0, n-1);
}

#endif //LEETCODE_DEMO_QUICKSORT3_H
