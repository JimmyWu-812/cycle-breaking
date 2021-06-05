#include <iostream>
#include <algorithm>
#include <list>
#include "set_liu.h"

using namespace std;

class DiGraph {
public:
    int numV;
    int numE;
    // edge_set store all the set from input file
    vector<Edge> edge_set;
    // use adjacent list to represent the graph
    list<int> *adj; 

    DiGraph(int v, int e) {
        numV = v;
        numE = e;
        adj = new list<int>[numV];
    }

    // these two function should appear in pair
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void removeEdge(int u) {
        adj[u].pop_back();
    }

    void Kruskal(vector<Edge>& rm_edge) {
        DisjointSet MST(numV);
        sort(edge_set.begin(), edge_set.end(), CompareEdge);

        for (vector<Edge>::iterator it = edge_set.begin(); it != edge_set.end(); ++it) {
            int u = it->u;
            int v = it->v;

            if (MST.Find(u) != MST.Find(v)) {
                // if u_set != v_set, then this edge is safe
                MST.Union(u, v);
                adj[u].push_back(v);
            }
            else {
                rm_edge.push_back(*it);
            }
        }
    }
    bool CycleVisit(int u, char *color, int size) {
        color[u] = 'g';
        for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
            if ((color[*it] == 'w') && CycleVisit(*it, color, size)) return true;
            else if (color[*it] == 'g') return true;
        }
        color[u] = 'b';
        return false;
    }

    // Detect cycle based on DFS, if detect GRAY, then return false
    bool isCyclic() {
        char* color = new char[numV];
        for (int i = 0; i < numV; ++i) {
            color[i] = 'w';
        }
        for (int i = 0; i < numV; ++i) {
            if (CycleVisit(i, color, numV)) {
                return true;
            }
        }
        return false;
    }

    int selectEdge(vector<Edge>& rm_edges) {
        // erase edge in a vector, do not increase itr
        // first add an edge into graph
        int min_cost = 0;
        for (vector<Edge>::iterator it = rm_edges.begin(); it != rm_edges.end();) {
            if (it->w <= 0) {
                min_cost += it->w;
                ++it;
                continue;
            }
            addEdge(it->u, it->v);
            if (isCyclic()) {
                removeEdge(it->u);
                min_cost += it->w;
                ++it;
            }
            else {
                rm_edges.erase(it);
            }
        }
        return min_cost;
    }

    ~DiGraph(){}
};

