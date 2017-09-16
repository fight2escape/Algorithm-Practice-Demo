//
// Created by Shinelon on 2017/9/16.
//

#ifndef ALGORITHM_PRACTICE_DEMO_INDEXMINHEAP_H
#define ALGORITHM_PRACTICE_DEMO_INDEXMINHEAP_H

#include <algorithm>
#include <cassert>

using namespace std;

template<typename Item>
class IndexMinHeap {
private:
    Item *data;
    int *indexes;
    int *reverse;

    int count;
    int capacity;

    void shiftUp(int k) {
        while(k > 1 && data[indexes[k]] < data[indexes[k/2]]) {
            swap(indexes[k], indexes[k/2]);
            reverse[indexes[k]] = k;
            reverse[indexes[k/2]] = k/2;
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while(2*k <= count) {
            int j = 2*k;
            if(j+1 <= count && data[indexes[j+1]] < data[indexes[j]]) {
                j += 1;
            }
            if(data[indexes[k]] <= data[indexes[j]]) {
                break;
            }
            swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:
    IndexMinHeap(int n) {
        data = new Item[n+1];
        indexes = new int[n+1];
        reverse = new int[n+1];
        count = 0;
        capacity = n+1;

        for(int i=0; i<capacity; i++) {
            reverse[i] = 0;
        }
    }
    ~IndexMinHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(int i, Item item) {
        assert(count + 1 < capacity);
        assert(i+1 >= 1 && i+1 < capacity);
        i++;
        data[i] = item;
        indexes[count + 1] = i;
        reverse[i] = count + 1;
        count++;
        shiftUp(count);
    }

    Item extractMin() {
        assert(count>0);
        Item res = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return res;
    }

    Item extractMinIndex() {
        assert(count>0);
        // 因为规定索引从 1 开始，但用户使用是从 0 开始
        int res = indexes[1] - 1;
        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return res;
    }

    Item getItem(int i) {
        assert(i+1 >= 1 && i+1 < capacity);
        return data[i+1];
    }

    bool contain(int i) {
        assert(i+1 >= 1 && i+1 < capacity);
        return reverse[i+1] != 0;
    }

    void change(int i,Item item) {
        assert( contain(i) );
        i++;
        data[i] = item;
        int j = reverse[i];
        shiftUp(j);
        shiftDown(j);
    }
};


#endif //ALGORITHM_PRACTICE_DEMO_INDEXMINHEAP_H
