
#include <iostream>
#include <vector>
#include <ctime>
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "SparseGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"

using namespace std;

int main() {
    string filename = "testG2.txt";
    SparseGraph g = SparseGraph( 6 , false );
    ReadGraph<SparseGraph> readGraph1( g , filename );
    g.show();
    cout<<endl;

    Path<SparseGraph> dfs(g,0);
    cout<<"DFS : ";
    dfs.showPath(5);

    ShortestPath<SparseGraph> bfs(g, 0);
    cout<<"BFS : ";
    bfs.showPath(5);

//    DenseGraph g2(13, false);
//    ReadGraph<DenseGraph> readGraph2(g2, filename);
//    cout<<"test G2 in Sparse Graph:"<<endl;
////    g2.show();
//    Component<DenseGraph> component2(g2);
//    cout<<"count:"<<component2.count()<<endl;

    return 0;
}