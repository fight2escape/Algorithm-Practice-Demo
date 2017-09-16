//
// Created by Shinelon on 2017/9/16.
//

#ifndef ALGORITHM_PRACTICE_DEMO_MINHEAP_H
#define ALGORITHM_PRACTICE_DEMO_MINHEAP_H

#include <algorithm>
#include <cassert>

using namespace std;

template<typename Item>
class MinHeap {
private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k) {
        while(k > 1 && data[k] < data[k/2]) {
            swap(data[k], data[k/2]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while(2*k <= count) {
            int j = 2*k;
            if(j+1 <= count && data[j+1] < data[j]) {
                j += 1;
            }
            if(data[k] <= data[j]) {
                break;
            }
            swap(data[k], data[j]);
            k = j;
        }
    }

public:
    MinHeap(int n) {
        data = new Item[n+1];
        count = 0;
        capacity = n+1;
    }
    ~MinHeap() {
        delete[] data;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Item item) {
        int i = count + 1;
        assert(i < capacity);
        data[i] = item;
        count++;
        shiftUp(i);
    }

    Item extractMin() {
        assert(count>0);
        Item res = data[1];
        swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return res;
    }
};

#endif //ALGORITHM_PRACTICE_DEMO_MINHEAP_H
