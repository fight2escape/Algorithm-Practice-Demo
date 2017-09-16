//
// Created by Shinelon on 2017/9/16.
//

#ifndef ALGORITHM_PRACTICE_DEMO_SHORTESTPATH_H
#define ALGORITHM_PRACTICE_DEMO_SHORTESTPATH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

template<typename Graph>
class ShortestPath{
private:
    Graph &G;
    int s;
    int *visited;
    int ccount;
    int *from;
    int *ord;

public:
    ShortestPath(Graph &graph, int s):G(graph) {
        visited = new int[G.V()];
        from = new int[G.V()];
        ord = new int[G.V()];
        ccount = 0;
        for(int i=0; i<G.V(); i++) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }
        this->s = s;
        // BFS
        queue<int> q;
        q.push(s);
        visited[s] = true;
        ord[s] = 0;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            typename Graph::adjIterator adj(G, v);
            for(int w = adj.begin(); !adj.end(); w = adj.next()){
                if(!visited[w]){
                    q.push(w);
                    visited[w] = true;
                    from[w] = v;
                    ord[w] = ord[v]+1;
                }
            }
        }

    }
    ~ShortestPath() {
        delete[] visited;
        delete[] from;
        delete[] ord;
    }

    int count() {
        return ccount;
    }

    bool hasPath(int w) {
        assert(w>=0 && w<G.V());
        return visited[w];
    }

    void path(int w, vector<int> &vec) {
        stack<int> s;
        int p = w;
        while(p != -1) {
            s.push(p);
            p = from[p];
        }

        vec.clear();
        while(!s.empty()){
            int sTop = s.top();
            vec.push_back( sTop );
            s.pop();
        }
    }

    void showPath(int w) {
        vector<int> vec;
        path(w, vec);
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i];
            if(i >= vec.size()-1) {
                cout<<endl;
            }else{
                cout<<" -> ";
            }
        }
    }

};

#endif //ALGORITHM_PRACTICE_DEMO_SHORTESTPATH_H
