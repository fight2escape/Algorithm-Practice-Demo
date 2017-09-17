//
// Created by Shinelon on 2017/9/17.
//

#ifndef ALGORITHM_PRACTICE_DEMO_DIJKSTRA_H
#define ALGORITHM_PRACTICE_DEMO_DIJKSTRA_H

#include <vector>
#include <stack>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

template<typename Graph, typename Weight>
class Dijkstra{
private:
    Graph &G;
    int s;
    Weight *distTo;
    bool *marked;
    vector<Edge<Weight>*> from;

public:
    Dijkstra(Graph &graph, int s):G(graph){
        this->s = s;
        distTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for(int i=0; i<G.V(); i++){
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }
        IndexMinHeap<Weight> ipq(G.V());
        // Dijkstra
        distTo[s] = Weight();
        from[s] = new Edge<Weight>(s, s, 0);
        marked[s] = true;
        ipq.insert(s, distTo[s]);
        while( !ipq.isEmpty() ){
            int v = ipq.extractMinIndex();
            typename Graph::adjIterator adj(G, v);
            for(Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()){
                int w = e->other(v);
                if( !marked[w] ){
                    if( from[w] == NULL || distTo[v] + e->wt() < distTo[w] ){
                        distTo[w] = distTo[v] + e->wt();
                        from[w] = e;
                        if( ipq.contain(w) ){
                            ipq.change(w, distTo[w]);
                        }else{
                            ipq.insert(w, distTo[w]);
                        }
                    }
                }
            }
        }
    }
    ~Dijkstra(){
        delete[] distTo;
        delete[] marked;
    }

    Weight shortestPathTo(int w){
        return distTo[w];
    }

    bool hasPathTo(int w){
        return marked[w];
    }

    void shortestPath(int w, vector<Edge<Weight>> &vec){
        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
        while(e->v() != e->w()){
            s.push(e);
            e = from[e->v()];
        }

        while(!s.empty()){
            e = s.top();
            vec.push_back(*e);
            s.pop();
        }
    }

    void showPath(int w){
        assert(w>=0 && w<G.V());
        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i].v()<<" -> ";
            if(i == vec.size()-1){
                cout<<vec[i].w()<<endl;
            }
        }
    }
};

#endif //ALGORITHM_PRACTICE_DEMO_DIJKSTRA_H
//string filename = "testG1.txt";
//int V = 5;
//
//SparseGraph<int> g(V, true);
//ReadGraph<SparseGraph<int>, int> readGraph(g, filename);
//
//cout<<"Test Dijkstra:"<<endl<<endl;
//Dijkstra<SparseGraph<int>, int> dij(g, 0);
//for(int i=1; i<V; i++){
//cout<<"Shortest Path to "<<i<<" : "<<dij.shortestPathTo(i)<<endl;
//dij.showPath(i);
//cout<<"--------------"<<endl;
//}