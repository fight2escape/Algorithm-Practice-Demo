//
// Created by Shinelon on 2017/9/17.
//

#ifndef ALGORITHM_PRACTICE_DEMO_KRUSKALMST_H
#define ALGORITHM_PRACTICE_DEMO_KRUSKALMST_H

#include <vector>
#include "Edge.h"
#include "MinHeap.h"
#include "UnionFind.h"

using namespace std;

template<typename Graph, typename Weight>
class KruskalMST{
private:
    vector<Edge<Weight>> mst;
    Weight mstWeight;

public:
    KruskalMST(Graph &graph){
        // 对边进行排序
        MinHeap<Edge<Weight>> pq( graph.E());
        for(int i=0; i<graph.V(); i++) {
            typename Graph::adjIterator adj( graph, i );
            for(Edge<Weight> *e = adj.begin(); !adj.end(); e = adj.next()) {
                if(e->v() < e->w()){
                    pq.insert(*e);
                }
            }
        }
        // 利用并查集判断是否为环，逐一对边进行筛选
        UnionFind uf(graph.V());
        while( !pq.isEmpty() && mst.size() < graph.V()-1){
            Edge<Weight> e = pq.extractMin();
            if( uf.isConnected(e.v(), e.w())){
                continue;
            }
            mst.push_back(e);
            uf.unionElements(e.v(), e.w());
        }
        // 计算权重
        mstWeight = 0;
        for(int i=0; i<mst.size(); i++){
            mstWeight += mst[i].wt();
        }
    }

    ~KruskalMST(){

    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    }

    Weight result(){
        return mstWeight;
    }
};

#endif //ALGORITHM_PRACTICE_DEMO_KRUSKALMST_H
//string filename = "testG1.txt";
//int V = 8;
//cout<<fixed<<setprecision(2);
//
//SparseGraph<double> g(V, false);
//ReadGraph<SparseGraph<double>,double> readGraph(g, filename);
//
//cout<<"Test Kruskal MST:"<<endl;
//KruskalMST<SparseGraph<double>,double> kruskalMST(g);
//vector<Edge<double>> mst = kruskalMST.mstEdges();
//for(int i=0; i<mst.size(); i++){
//cout<<mst[i]<<endl;
//}
//cout<<"The MST weight is:"<<kruskalMST.result()<<endl;
