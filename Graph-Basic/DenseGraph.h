//
// Created by Shinelon on 2017/9/15.
//

#ifndef ALGORITHM_PRACTICE_DEMO_DENSEGRAPH_H
#define ALGORITHM_PRACTICE_DEMO_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 稠密图-邻接矩阵
class DenseGraph {
private:
    int n, m;
    bool directed;
    vector<vector<bool>> g;

public:
    DenseGraph(int n, bool directed) {
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for(int i=0; i<n; i++) {
            g.push_back(vector<bool>(n, false));
        }
    }
    ~DenseGraph() {

    }

    int V() { return n; }
    int E() { return m; }

    void addEdge(int v, int w) {
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);
        if(hasEdge(v, w)){
            return;
        }
        g[v][w] = true;
        if(!directed) {
            g[w][v] = true;
        }
        m++;
    }

    bool hasEdge(int v, int w) {
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);
        return g[v][w];
    }

    void show() {
        for(int i=0; i<V(); i++) {
            cout<<i<<" :\t";
            for(int j=0; j<V(); j++) {
                if(g[i][j]){
                    cout<<j;
                }else{
                    cout<<g[i][j];
                }
                cout<<"\t";
            }
            cout<<endl;
        }
    }

    // 内部迭代器
    class adjIterator {
    private:
        DenseGraph &G;
        int v;
        int index;

    public:
        adjIterator(DenseGraph &graph, int v):G(graph) {
            this->v = v;
            this->index = 0;
        }

        int begin() {
            index = -1;
            return next();
        }

        int next() {
            for(index += 1; index < G.V(); index++){
                if(G.g[v][index]) {
                    return index;
                }
            }
            return -1;
        }

        bool end() {
            return index >= G.V();
        }
    };
};

#endif //ALGORITHM_PRACTICE_DEMO_DENSEGRAPH_H
//    vector<int> vec({1,2,3,4,5,6});
//    vector<int>::iterator iter;
//    for(iter=vec.begin(); iter!=vec.end(); iter++) {
//        cout<<*iter<<endl;
//    }
//    int N = 20;
//    int M = 100;
//    srand(time(NULL));
//    DenseGraph g1(N, 0);
//    for(int i=0; i<M; i++) {
//        int a = rand() % N;
//        int b = rand() % N;
//        g1.addEdge(a, b);
//    }
//    g1.show();
//    for(int v=0; v<N; v++) {
//        cout<<v<<" : ";
//        DenseGraph::adjIterator adj(g1, v);
//        for(int w = adj.begin(); !adj.end(); w = adj.next()) {
//            cout<<w<<" ";
//        }
//        cout<<endl;
//    }