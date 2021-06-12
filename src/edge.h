#include <iostream>

using namespace std;

class Edge {
public:
    int i, j, w;

    Edge(){}
    
    Edge(int i, int j, int w) {
        this->i = i;
        this->j = j;
        this->w = w;
    }
};

