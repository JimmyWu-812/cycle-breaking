#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "graph.h"

using namespace std;

// void countingSort(vector<Edge>& edgesList, int m){
//     vector<Edge> sortedEdgesList;
//     sortedEdgesList.resize(m);
//     int i, count[201] = {0};
//     for(i=0; i<m; i++){
//         count[edgesList[i].w + 100]++;
//     }
//     if(count[101] == m){
//         // unweigted undirected
//         return;
//     }
//     for(i=0; i<=200; i++){
//         count[i+1] += count[i];
//     }
//     for(i=m-1; i>=0; i--){
//         sortedEdgesList[count[edgesList[i].w + 100] - 1] = edgesList[i];
//         count[edgesList[i].w + 100]--;
//     }
//     edgesList = sortedEdgesList;
// }

bool CompareEdge(Edge e, Edge f) {
    return (e.w < f.w);
}

int main(int argc, char* argv[]){

    fstream fin(argv[1]), fout;
    // n: number of vertices, m: number of edges
    int n, m;
    // edge (i,j) with weight w
    int i, j, w;
    int cost;
    // 'u' for undireted, 'd' for directed
    char graphType;
    vector<Edge> edgesList;

    fin >> graphType;
    fin >> n;
    fin >> m;
    while (fin >> i >> j >> w) {
        Edge e(i, j, w);
        edgesList.push_back(e);
    }
    fin.close();

    sort(edgesList.begin(), edgesList.end(), CompareEdge);
    // countingSort(edgesList, m);
    Graph graph(n, m, edgesList);

    graph.maxSTByKruskal();

    fout.open(argv[2],ios::out);
    if(graphType == 'u'){
        fout << graph.cost << endl;
        for(int k=0; k<graph.edgesNotInMaxST.size(); k++){
            fout << graph.edgesNotInMaxST[k].i << " "
                << graph.edgesNotInMaxST[k].j << " "
                << graph.edgesNotInMaxST[k].w << endl;
        }
    }
    else if(graphType == 'd'){
        graph.addMoreEdges();
        fout << graph.cost << endl;
        for(int k=0; k<graph.edgesNotInMaxST.size(); k++){
            fout << graph.edgesNotInMaxST[k].i << " "
                << graph.edgesNotInMaxST[k].j << " "
                << graph.edgesNotInMaxST[k].w << endl;
        }
    }
    fout.close();

    return 0;
}