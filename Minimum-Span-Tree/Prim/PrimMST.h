//
// Created by Shinelon on 2017/9/16.
//

#ifndef ALGORITHM_PRACTICE_DEMO_PRIMMST_H
#define ALGORITHM_PRACTICE_DEMO_PRIMMST_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

template<typename Graph, typename Weight>
class PrimMST{
private:
    Graph &G;
    IndexMinHeap<Weight> ipq;
    vector<Edge<Weight>*> edgeTo;
    bool* marked;
    vector<Edge<Weight>> mst;
    Weight mstWeight;

    void visit(int v) {
        assert( !marked[v] );
        marked[v] = true;

        typename Graph::adjIterator adj(G,v);
        for(Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()) {
            int w = e->other(v);
            if( !marked[w] ) {
                if( !edgeTo[w] ) {
                    ipq.insert(w, e->wt());
                    edgeTo[w] = e;
                }else if(e->wt() < edgeTo[w]->wt()){
                    ipq.change(w, e->wt());
                    edgeTo[w] = e;
                }
            }
        }
    }

public:
    PrimMST(Graph &graph):G(graph), ipq(IndexMinHeap<double>(graph.V())) {
        marked = new bool[G.V()];
        for(int i=0; i<G.V(); i++) {
            marked[i] = false;
            edgeTo.push_back(NULL);
        }
        mst.clear();
        mstWeight = 0;
        // Prim
        visit(0);
        while( !ipq.isEmpty() ) {
            int v = ipq.extractMinIndex();
            assert( edgeTo[v] );
            mst.push_back( *edgeTo[v] );
            visit(v);
        }
        // 求权值
        for(int i=0; i<mst.size(); i++) {
            mstWeight += mst[i].wt();
        }
    }

    ~PrimMST() {
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges() {
        return mst;
    }

    Weight result() {
        return mstWeight;
    }
};

#endif //ALGORITHM_PRACTICE_DEMO_PRIMMST_H

//string  filename = "testG1.txt";
//int V = 8;
//cout<<fixed<<setprecision(2);
//
//SparseGraph<double> g(V, false);
//ReadGraph<SparseGraph<double>,double> readGraph2(g, filename);
//g.show();
//
//// Test Prim MST
//cout<<"Test Lazy Prim MST"<<endl;
//PrimMST<SparseGraph<double>,double> primMST(g);
//vector<Edge<double>> mst = primMST.mstEdges();
//for( int i=0; i<mst.size(); i++) {
//cout<<mst[i]<<endl;
//}
//cout<<"The MST weight is: "<<primMST.result()<<endl;
//
//cout<<endl;