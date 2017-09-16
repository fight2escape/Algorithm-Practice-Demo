//
// Created by Shinelon on 2017/9/16.
//

#ifndef ALGORITHM_PRACTICE_DEMO_UNIONFIND_H
#define ALGORITHM_PRACTICE_DEMO_UNIONFIND_H

#include <cassert>

class UnionFind{
    // Quick Union + parent + rank + path compression
private:
    int *parent;
    int *rank;
    int count;

public:
    UnionFind(int count) {
        parent = new int[count];
        rank = new int[count];
        this->count = count;
        for(int i=0; i<count; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    int find(int v) {
        assert(v>=0 && v<count);
        if(parent[v] != v){
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    bool isConnected(int v, int w) {
        assert(v>=0 && v<count);
        assert(w>=0 && w<count);
        return find(v) == find(w);
    }

    void unionElements(int v, int w) {
        assert(v>=0 && v<count);
        assert(w>=0 && w<count);
        int vRoot = find(v);
        int wRoot = find(w);
        if(vRoot ==wRoot){
            return;
        }
        if(rank[vRoot] < rank[wRoot]) {
            parent[vRoot] = w;
        }else if(rank[vRoot] > rank[wRoot]) {
            parent[wRoot] = v;
        }else{
            parent[wRoot] = v;
            rank[vRoot]++;
        }
    }
};

#endif //ALGORITHM_PRACTICE_DEMO_UNIONFIND_H
