//
// Created by Shinelon on 2017/9/14.
//

#ifndef LEETCODE_DEMO_INDEXMAXHEAP_H
#define LEETCODE_DEMO_INDEXMAXHEAP_H

#include <iostream>
#include <cassert>
using namespace std;

template<typename Item>
class IndexMaxHeap {

private:
    Item *data;
    int *indexes;
    int *reverse;
    int count;
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[indexes[k]] > data[indexes[k / 2]]) {
            swap(indexes[k], indexes[k / 2]);
            reverse[indexes[k]] = k;
            reverse[indexes[k/2]] = k/2;
            k /= 2;
        }
    }

    void shiftDown(int k) {
        // 得到最后一个元素的值，先假定为堆顶元素的值,作为比较值
        int index = indexes[k];
        Item cur = data[index];
        while (2 * k <= count) {
            int j = 2 * k; // k是需要交换的子节点
            // 比较左右子节点，得到较大值的下标
            if (j + 1 <= count && data[indexes[j]] < data[indexes[j + 1]]) {
                j += 1;
            }
            // 父节点大则退出
            if (cur >= data[indexes[j]]) {
                break;
            }
            indexes[k] = indexes[j];
            reverse[indexes[k]] = k;
            k = j;
        }
        indexes[k] = index;
        reverse[indexes[k]] = k;
    }

public:
    IndexMaxHeap(int capacity) {
        data = new Item[capacity + 1];
        indexes = new int[capacity + 1];
        reverse = new int[capacity + 1];
        for(int i=0; i<capacity+1; i++) {
            reverse[i] = 0;
        }
        count = 0;
        this->capacity = capacity;
    }

    ~IndexMaxHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int getSize() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    // 内部实现是从1开始的，对用户而言是从0开始的，内部需要加1
    void insert(int i, Item item) {
        assert(capacity >= count + 1);
        assert(i+1 >= 1 && i+1 <= capacity);
        i++;
        data[i] = item;
        indexes[count + 1] = i;
        count++;
        shiftUp(count);
    }

    Item extractMax() {
        assert(count > 0);
        Item res = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return res;
    }

    int extractMaxIndex() {
        assert(count > 0);
        int res = indexes[1] -1;
        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return res;
    }

    bool contain(int i) {
        assert(i+1 >= 1 && i+1 <=capacity);
        return reverse[i+1] !=0;
    }

    Item getItem(int i) {
        assert( contain(i));
        return data[i+1];
    }

    void change(int i, Item newItem) {
        assert( contain(i));
        i++;
        data[i] = newItem;
//        for(int j=1; j<=count; j++) {
//            if(indexes[j] == i) {
//                shiftUp(j);
//                shiftDown(j);
//                return;
//            }
//        }
        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);
    }
};

#endif //LEETCODE_DEMO_INDEXMAXHEAP_H
