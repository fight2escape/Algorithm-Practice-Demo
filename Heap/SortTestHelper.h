//
// Created by Shinelon on 2017/9/10.
//

#ifndef LEETCODE_DEMO_SORTTESTHELPER_H
#define LEETCODE_DEMO_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {

    // 生成N个元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rangeL + rand() % (rangeR - rangeL + 1);
        }
        return arr;
    }

    // 生成近乎有序的数组
    int *generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        for (int i = 0; i < swapTimes; i++) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n-1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        assert(isSorted(arr, n));

        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    }

    int* copyIntArray(int a[], int n) {
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
        }
        return arr;
    }

}

#endif //LEETCODE_DEMO_SORTTESTHELPER_H