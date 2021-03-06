//
// Created by Shinelon on 2017/9/15.
//

#ifndef LEETCODE_DEMO_UNIONFIND3_H
#define LEETCODE_DEMO_UNIONFIND3_H

#include <cassert>
namespace UF3 {
    class UnionFind {
    private:
        int* parent;
        int* sz; // 表示以本节点为根的树所包含的元素数量
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[n];
            sz = new int[n];
            for(int i=0; i<n; i++) {
                parent[i] = i;
                sz[i] = 1;
            }
        }
        ~UnionFind() {
            delete[] parent;
            delete[] sz;
        }
        int find(int p) {
            assert(p>=0 && p<count);
            while(p != parent[p]) {
                p = parent[p];
            }
            return p;
        }
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);
            if(pRoot == qRoot) {
                return ;
            }
            if(sz[pRoot] < sz[qRoot]) {
                parent[pRoot] = qRoot;
                sz[qRoot] += sz[pRoot];
            }else {
                parent[qRoot] = pRoot;
                sz[pRoot] += sz[qRoot];
            }
        }
    };
}

#endif //LEETCODE_DEMO_UNIONFIND3_H
