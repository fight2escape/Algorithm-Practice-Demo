//
// Created by Shinelon on 2017/9/15.
//

#ifndef LEETCODE_DEMO_UNIONFIND6_H
#define LEETCODE_DEMO_UNIONFIND6_H

#include <cassert>
// 路径压缩:压缩为两层
namespace UF6 {
    class UnionFind {
    private:
        int* parent;
        int* rank; // 表示以本节点为根的树的高度，最小为1
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[n];
            rank = new int[n];
            for(int i=0; i<n; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }
        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }
        int find(int p) {
            assert(p>=0 && p<count);
//            while(p != parent[p]) {
//                parent[p] = parent[parent[p]];
//                p = parent[p];
//            }
//            return p;
            if(p != parent[p]) {
                parent[p] = find(parent[p]);
            }
            return parent[p];
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
            if(rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            }else if(rank[pRoot] > rank[qRoot]){
                parent[qRoot] = pRoot;
            }else{
                // rank[pRoot] == rank[qRoot]
                parent[qRoot] = pRoot;
                rank[pRoot] += 1;
            }
        }
    };
}

#endif //LEETCODE_DEMO_UNIONFIND6_H
