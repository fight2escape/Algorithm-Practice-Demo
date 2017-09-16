//
// Created by Shinelon on 2017/9/15.
//

#ifndef ALGORITHM_PRACTICE_DEMO_PATH_H
#define ALGORITHM_PRACTICE_DEMO_PATH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;

template<typename Graph>
class Path{
private:
    Graph &G;
    int s;
    int *visited;
    int ccount;
    int *from;

    void dfs(int v) {
        visited[v] = true;
        typename Graph::adjIterator adj(G, v);
        for(int w = adj.begin(); !adj.end(); w = adj.next()){
            if(!visited[w]){

                from[w] = v;
                dfs(w);
            }
        }
    }

public:
    Path(Graph &graph, int s):G(graph) {
        visited = new int[G.V()];
        from = new int[G.V()];
        ccount = 0;
        for(int i=0; i<G.V(); i++) {
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;
        // 寻路算法
        dfs(s);
    }
    ~Path() {
        delete[] visited;
        delete[] from;
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

#endif //ALGORITHM_PRACTICE_DEMO_PATH_H
