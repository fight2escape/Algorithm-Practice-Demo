//
// Created by Shinelon on 2017/9/14.
//

#ifndef LEETCODE_DEMO_BINARYSEARCH_H
#define LEETCODE_DEMO_BINARYSEARCH_H


// 迭代法
template<typename T>
int BinarySearch(T arr[], int n, T target) {
    // [left, right]
    int left = 0, right = n-1, mid;
    while(left <= right) {
        mid = left + (right - left) / 2;
        if(arr[mid] > target) {
            right = mid - 1;
        }else if(arr[mid] < target) {
            left = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}


// 递归法
template<typename T>
int __binarySearch2(T arr[], T target, int left, int right) {
    if(left > right) {
        return -1;
    }
    int mid = left + (right-left)/2;
    if(arr[mid] > target) {
        right = mid-1;
    }else if(arr[mid] < target) {
        left = mid+1;
    }else{
        return mid;
    }
    __binarySearch2(arr, target, left, right);
}

template<typename T>
int BinarySearch2(T arr[], int n, T target) {
    // [left, right]
    return __binarySearch2(arr, target, 0, n-1);
}

#endif //LEETCODE_DEMO_BINARYSEARCH_H
