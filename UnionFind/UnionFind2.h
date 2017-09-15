//
// Created by Shinelon on 2017/9/15.
//

#ifndef LEETCODE_DEMO_UNIONFIND2_H
#define LEETCODE_DEMO_UNIONFIND2_H

#include <cassert>

namespace UF2 {
    class UnionFind {
    private:
        int *parent;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[n];
            for(int i=0; i<n; i++) {
                parent[i] = i;
            }
        }
        ~UnionFind() {
            delete[] parent;
        }
        int find(int p) {
            assert(p >= 0 && p<count);
            while(p != parent[p]) {
                p = parent[p];
            }
            return p;
        }
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
        void unionElements(int p, int q) {
            int pParent = find(p);
            int qParent = find(q);
            if(pParent == qParent) {
                return;
            }
            parent[pParent] = qParent;
        }
    };
}

#endif //LEETCODE_DEMO_UNIONFIND2_H
