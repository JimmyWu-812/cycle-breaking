#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "edge.h"
#include "graph.h"

using namespace std;

int main(int argc, char* argv[]){

    fstream fin(argv[1]), fout;
    char graphType;
    int V, E;
    fin >> graphType;
    fin >> V;
    fin >> E;
    vector<Edge> edges, sortedEdges;

    int vi, vf, w;
    while (fin >> vi >> vf >> w) {
        Edge edge(vi, vf, w);
        edges.push_back(edge);
    }
    fin.close();

    // counting sort
    int i, count[201] = {0};
    for(i=0; i<E; i++){
        count[edges[i].w + 100]++;
    }
    for(i=0; i<=200; i++){
        count[i+1] += count[i];
    }
    for(i=E-1; i>=0; i--){
        sortedEdges[count[edges[i].w] - 1] = edges[i];
        count[edges[i].w]--;
    }

    Graph graph(V, E, sortedEdges);

    // fout.open(argv[2],ios::out);
    // fout << M[N-1][0] << endl;
    // for(int i=result.size()-1; i>=0; i--){
    //     fout << result[i] << " " << chords[result[i]] << endl;
    // }
    // fout.close();

    return 0;
}