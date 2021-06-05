#include <iostream>

using namespace std;

class Edge {
public:
    int vi, vf, w;

    Edge(int vii, int vff, int ww) {
        vi = vii;
        vf = vff;
        w = ww;
    }

    ~Edge(){}
};

