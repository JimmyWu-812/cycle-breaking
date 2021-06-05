#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

bool CompareEdge(Edge e1, Edge e2) {
    return (e1.w > e2.w);
}

class DisjointSet {
public:
    /*
    1. ranking, add smaller forest under larger forest
    2. path compression
    */
    int* rank;
    int* parent;
    int n;

    DisjointSet(int n) {
        parent = new int [n];
        rank = new int [n];
        this->n = n;
        MakeSet();
    }
    
    void MakeSet() {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    void Union(int x, int y) {
        // UNION by RANK
        int x_root = Find(x);
        int y_root = Find(y);

        if (x_root == y_root) return;
        
        if (rank[x_root] > rank[y_root]) parent[y_root] = x_root;
        else {
            parent[x_root] = y_root;
            if (rank[x_root] == rank[y_root]) rank[y_root]++;
        }
    }

    int Find(int x) {
        // PATH COMPRESSION
        // recursively call Find on its parent 
        // and move i's node directly under the 
        // representative of this set
        if (parent[x] != x) {
            parent[x] = Find(parent[x]);
        } 
        return parent[x];
    }

    ~DisjointSet() {
        delete [] rank;
        delete [] parent;
    }
};