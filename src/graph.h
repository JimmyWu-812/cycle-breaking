#include <iostream>
#include <algorithm>
#include <vector>
#include "edge.h"
#include "djset.h"

using namespace std;

class Graph {
public:
    // n: number of vertices, m: number of edges
    int n, m, cost;
    // sorted in main.cpp
    vector<Edge> edgesList, edgesNotInMaxST;
    vector<vector<int>> adjMaxST;

    Graph(int n, int m, vector<Edge>& edgesList) {
        this->n = n;
        this->m = m;
        this->edgesList = edgesList;
        cost = 0;
        adjMaxST.resize(n);
    }

    void maxSTByKruskal(){
        cost = 0;
        DJSet djSet(n);
        Edge e;
        for(int k=0; k<n; k++){
            djSet.makeSet(k);
        }
        for(int k=edgesList.size()-1; k>=0; k--){
            e = edgesList[k];
            if(djSet.findSet(e.i) == djSet.findSet(e.j)){
                edgesNotInMaxST.push_back(e);
                cost += e.w;
            }
            else{
                djSet.unionSets(e.i, e.j);
                adjMaxST[e.i].push_back(e.j);// for directed
            }
        }
    }

    void addMoreEdges(){
        Edge e;
        for(int k=0; k<edgesNotInMaxST.size(); k++){
            e = edgesNotInMaxST[k];
            if(!DFS(e)){
                adjMaxST[e.i].push_back(e.j);
                edgesNotInMaxST.erase(edgesNotInMaxST.begin() + k);
                cost -= e.w;
            }
        }
    }

    // cycle detection
    bool DFS(Edge& e){
        vector<char> c(n, 'w');// color
        return DFSVisit(c, e.i, e.j);
    }

    // DFS subroutine
    bool DFSVisit(vector<char>& c, int i, int j){
        c[j] = 'g';
        int x;
        for(int k=0; k<adjMaxST[j].size(); k++){
            x = adjMaxST[j][k];
            if(x == i || (c[x] == 'w' && DFSVisit(c, i, x))){
                return true;
            }
        }
        return false;
    }
    
    // // cycle detection
    // bool DFS(){
    //     vector<char> c(n, 'w');// color
    //     for(int k=0; k<n; k++){
    //         if(c[k] == 'w'){
    //             if(DFSVisit(c, k)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    // // DFS subroutine
    // bool DFSVisit(vector<char>& c, int k){
    //     c[k] = 'g';
    //     int x;
    //     for(int l=0; l<adjMaxST[k].size(); l++){
    //         x = adjMaxST[k][l];
    //         if(c[x] == 'g'){
    //             return true;
    //         }
    //         else if(c[x] == 'w' && DFSVisit(c, x)){
    //             return true;
    //         }
    //     }
    //     c[k] = 'b';
    //     return false;
    // }
};

