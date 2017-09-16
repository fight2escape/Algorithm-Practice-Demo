
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <iomanip>
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "SparseGraph.h"

using namespace std;

int main() {

    string  filename = "testG1.txt";
    int V = 8;
    cout<<fixed<<setprecision(2);

    DenseGraph<double> g1(V, false);
    ReadGraph<DenseGraph<double>,double> readGraph1(g1,filename);
    g1.show();

    SparseGraph<double> g2(V, false);
    ReadGraph<SparseGraph<double>,double> readGraph2(g2, filename);
    g2.show();

    return 0;
}