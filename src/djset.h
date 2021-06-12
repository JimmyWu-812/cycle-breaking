#include <iostream>

using namespace std;

class DJSet {
public:
    // p: parent of elements, r: rank of elements
    vector<int> p, r;

    DJSet(int n){
        p.resize(n);
        r.resize(n);
    }

    void makeSet(int x) {
        p[x] = x;
        r[x] = 0;
    }

    int findSet(int x) {
        if (x != p[x]) {
            p[x] = findSet(p[x]);
        } 
        return p[x];
    }

    void unionSets(int x, int y) {
        // representatives
        int xRep = findSet(x), yRep = findSet(y);
        if(xRep == yRep){
            return;
        }
        if (r[xRep] > r[yRep]){
            p[yRep] = xRep;
        }
        else {
            p[xRep] = yRep;
            if (r[xRep] == r[yRep]){
                r[yRep]++;
            }
        }
    }
};