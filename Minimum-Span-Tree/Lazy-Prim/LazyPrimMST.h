//
// Created by Shinelon on 2017/9/16.
//

#ifndef ALGORITHM_PRACTICE_DEMO_LAZYPRIMMST_H
#define ALGORITHM_PRACTICE_DEMO_LAZYPRIMMST_H

#include "Edge.h"
#include "MinHeap.h"
#include <vector>

using namespace std;

template<typename Graph, typename Weight>
class LazyPrimMST{
private:
    Graph &G;
    MinHeap<Edge<Weight>> pq;
    bool *marked;
    vector<Edge<Weight>> mst;
    Weight mstWeight;

    void visited(int v) {
        marked[v] = true;

        typename Graph::adjIterator adj(G, v);
        for(Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
            if(!marked[e->other(v)]) {
                pq.insert(*e);
            }
        }
    }

public:
    LazyPrimMST(Graph &graph):G(graph), pq(MinHeap<Edge<Weight>>(graph.E())) {
        marked = new bool[graph.V()];
        for(int i=0; i<G.V(); i++) {
            marked[i] = false;
        }
        mst.clear();
        // Lazy Prim
        visited(0);
        while(!pq.isEmpty()) {
            Edge<Weight> e = pq.extractMin();
            if(marked[e.v()] == marked[e.w()]) {
                continue;
            }
            mst.push_back(e);
            if(!marked[e.v()]) {
                visited(e.v());
            }else{
                visited(e.w());
            }
        }
        // 计算权值
        mstWeight = 0;
        for(int i=0; i<mst.size(); i++) {
            mstWeight += mst[i].wt();
        }

    }

    ~LazyPrimMST() {
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges() {
        return mst;
    }

    Weight result() {
        return mstWeight;
    }
};

#endif //ALGORITHM_PRACTICE_DEMO_LAZYPRIMMST_H
//string  filename = "testG1.txt";
//int V = 8;
//cout<<fixed<<setprecision(2);
//
//SparseGraph<double> g(V, false);
//ReadGraph<SparseGraph<double>,double> readGraph2(g, filename);
//g.show();
//
//// Test Lazy Prim MST
//cout<<"Test Lazy Prim MST"<<endl;
//LazyPrimMST<SparseGraph<double>,double> lazyPrimMST(g);
//vector<Edge<double>> mst = lazyPrimMST.mstEdges();
//for( int i=0; i<mst.size(); i++) {
//cout<<mst[i]<<endl;
//}
//cout<<"The MST weight is: "<<lazyPrimMST.result()<<endl;
//
//cout<<endl;