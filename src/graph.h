#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include "edge.h"

using namespace std;

class Graph {
public:
    int V, E;
    vector<Edge> edges;
    list<int> *Adj; 

    Graph(int v, int e, vector<Edge>& sortedEdges) {
        V = v;
        E = e;
        edges = sortedEdges;
        Adj = new list<int>[V];
    }

    // these two function should appear in pair
    // void addEdge(int u, int v) {
    //     adj[u].push_back(v);
    // }

    // void removeEdge(int u) {
    //     adj[u].pop_back();
    // }

    // void Kruskal(vector<Edge>& rm_edge) {
    //     DisjointSet MST(numV);
    //     sort(edge_set.begin(), edge_set.end(), CompareEdge);

    //     for (vector<Edge>::iterator it = edge_set.begin(); it != edge_set.end(); ++it) {
    //         int u = it->u;
    //         int v = it->v;

    //         if (MST.Find(u) != MST.Find(v)) {
    //             // if u_set != v_set, then this edge is safe
    //             MST.Union(u, v);
    //             adj[u].push_back(v);
    //         }
    //         else {
    //             rm_edge.push_back(*it);
    //         }
    //     }
    // }
    // bool CycleVisit(int u, char *color, int size) {
    //     color[u] = 'g';
    //     for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
    //         if ((color[*it] == 'w') && CycleVisit(*it, color, size)) return true;
    //         else if (color[*it] == 'g') return true;
    //     }
    //     color[u] = 'b';
    //     return false;
    // }

    // // Detect cycle based on DFS, if detect GRAY, then return false
    // bool isCyclic() {
    //     char* color = new char[numV];
    //     for (int i = 0; i < numV; ++i) {
    //         color[i] = 'w';
    //     }
    //     for (int i = 0; i < numV; ++i) {
    //         if (CycleVisit(i, color, numV)) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // int selectEdge(vector<Edge>& rm_edges) {
    //     // erase edge in a vector, do not increase itr
    //     // first add an edge into graph
    //     int min_cost = 0;
    //     for (vector<Edge>::iterator it = rm_edges.begin(); it != rm_edges.end();) {
    //         if (it->w <= 0) {
    //             min_cost += it->w;
    //             ++it;
    //             continue;
    //         }
    //         addEdge(it->u, it->v);
    //         if (isCyclic()) {
    //             removeEdge(it->u);
    //             min_cost += it->w;
    //             ++it;
    //         }
    //         else {
    //             rm_edges.erase(it);
    //         }
    //     }
    //     return min_cost;
    // }

    Graph(){}
};

