#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include "edge.h"
#include "djset.h"

using namespace std;

class Graph {
public:
    // n: number of vertices, m: number of edges
    int n, m;
    // sorted in main.cpp
    vector<Edge> edgesList, edgesNotInMaxST;
    vector<int> *adjList;

    Graph(int n, int m, vector<Edge>& edgesList) {
        this->n = n;
        this->m = m;
        this->edgesList = edgesList;
        adjList = new vector<int>[n];
    }

    int maxSTByKruskal(){
        int cost = 0;
        DJSet djSet(n);
        for(int k=0; k<n; k++){
            djSet.makeSet(k);
        }
        for(int k=0; k<edgesList.size(); k++){
            Edge e = edgesList[k];
            if(djSet.findSet(e.i) == djSet.findSet(e.j)){
                edgesNotInMaxST.push_back(e);
                cost += e.w;
            }
            else{
                djSet.unionSets(e.i, e.j);
                adjList[e.i].push_back(e.j);// for directed
            }
        }
        return cost;
    }

    ~Graph(){}
};

