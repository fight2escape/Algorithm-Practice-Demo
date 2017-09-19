//
// Created by Shinelon on 2017/9/19.
//

#ifndef ALGORITHM_PRACTICE_DEMO_BELLMANFORD_H
#define ALGORITHM_PRACTICE_DEMO_BELLMANFORD_H

#include <vector>
#include <stack>
#include "Edge.h"

template<typename Graph, typename Weight>
class BellmanFord{
private:
    Graph &G;
    int s;
    Weight* distTo;
    vector<Edge<Weight>*> from;
    bool hasNegativeCycle;

    bool detectNegativeCycle(){
        for(int i=0; i<G.V(); i++){
            typename Graph::adjIterator adj(G, i);
            for(Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()){
                if(!from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()]){
                    return true;
                }
            }
        }
        return false;
    }

public:
    BellmanFord(Graph &graph, int s):G(graph){
        this->s = s;
        distTo = new Weight[G.V()];
        for(int i=0; i<G.V(); i++){
            from.push_back(NULL);
        }
        // Bellman-Ford
        distTo[s] = Weight();
        for(int pass=1; pass<G.V(); pass++){
            // Relaxation
            for(int i=0; i<G.V(); i++){
                typename Graph::adjIterator adj(G, i);
                for(Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()){
                    if(!from[e->w()] || distTo[e->v()] + e->wt() < distTo[e->w()]){
                        distTo[e->w()] = distTo[e->v()] + e->wt();
                        from[e->w()] = e;
                    }
                }
            }
        }
        hasNegativeCycle = detectNegativeCycle();
    }

    ~BellmanFord(){
        delete[] distTo;
    }

    bool negativeCycle(){
        return hasNegativeCycle;
    }

    Weight shortestPathTo(int w){
        assert(w>=0 && w<G.V());
        assert( !hasNegativeCycle );
        return distTo[w];
    }

    void shortestPath(int w, vector<Edge<Weight>> &vec){
        assert(w>=0 && w<G.V());
        assert( ~hasNegativeCycle );
        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
        while( e->v() != this->s ){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);

        while( !s.empty() ){
            e = s.top();
            vec.push_back( *e );
            s.pop();
        }
    }

    void showPath(int w){
        assert( w>=0 && w<G.V());
        assert( !hasNegativeCycle );

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i].v()<<" -> ";
            if(i== vec.size()-1){
                cout<<vec[i].w()<<endl;
            }
        }
    }
};

#endif //ALGORITHM_PRACTICE_DEMO_BELLMANFORD_H
//string filename = "testG2.txt";
//int V = 5;
//SparseGraph<int> g(V, true);
//ReadGraph<SparseGraph<int>, int> readGraph(g, filename);
//
//cout<<"Test Bellman-Ford:"<<endl<<endl;
//BellmanFord<SparseGraph<int>,int> bellmanFord(g, 0);
//if(bellmanFord.negativeCycle()){
//cout<<"The graph contain negative cycle"<<endl;
//}else{
//for(int i=1; i<V; i++){
//cout<<"Shortest Path to "<<i<<" : "<<bellmanFord.shortestPathTo(i)<<endl;
//bellmanFord.showPath(i);
//cout<<"----------"<<endl;
//}
//}