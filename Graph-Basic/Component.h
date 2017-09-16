//
// Created by Shinelon on 2017/9/15.
//

#ifndef ALGORITHM_PRACTICE_DEMO_COMPONENT_H
#define ALGORITHM_PRACTICE_DEMO_COMPONENT_H

template<typename Graph>
class Component{
private:
    Graph &G;
    bool *visited;
    int ccount;
    int *id;

    void dfs(int v) {
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G, v);
        for(int w = adj.begin(); !adj.end(); w = adj.next()) {
            if(!visited[w]){
                dfs(w);
            }
        }
    }

public:
    Component(Graph &graph):G(graph) {
        visited = new bool[G.V()];
        ccount = 0;
        id = new int[G.V()];
        for(int i=0; i<G.V(); i++) {
            visited[i] = false;
            id[i] = -1;
        }
        for(int i=0; i<G.V(); i++) {
            if(!visited[i]) {
                dfs(i);
                ccount++;
            }
        }
    }
    ~Component() {
        delete[] visited;
        delete[] id;
    }

    int count() {
        return ccount;
    }

    bool isConnected(int v, int w){
        assert(v>=0 && v<G.V());
        assert(w>=0 && w<G.V());
        return id[v] == id[w];
    }
};

#endif //ALGORITHM_PRACTICE_DEMO_COMPONENT_H
//string filename = "testG1.txt";
//SparseGraph g1 = SparseGraph( 13 , false );
//ReadGraph<SparseGraph> readGraph1( g1 , filename );
//cout<<"test G1 in Sparse Graph:" << endl;
////    g1.show();
//Component<SparseGraph> component1(g1);
//cout<<"count:"<<component1.count()<<endl;
//cout<<endl;
//
//string filename2 = "testG2.txt";
//SparseGraph g11 = SparseGraph( 6 , false );
//ReadGraph<SparseGraph> readGraph2( g11 , filename2 );
//cout<<"test G2 in Sparse Graph:" << endl;
////    g1.show();
//Component<SparseGraph> component2(g11);
//cout<<"count:"<<component2.count()<<endl;
//cout<<endl;