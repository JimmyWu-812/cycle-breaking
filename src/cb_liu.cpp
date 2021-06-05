#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <time.h>
#include <sys/resource.h> 
#include <assert.h>
#include "digraph_liu.h"

using namespace std;

long get_mem_usage() {
    struct rusage mysuage;
    getrusage(RUSAGE_SELF, &mysuage);
    return mysuage.ru_maxrss;
}

int main(int argc, char* argv[])
{
    if(argc != 3) {
       std::cout << "usage: cb <input_file> <output_file>\n";
       return 0;
    }

    //// read the input data //// 
    clock_t start = clock();

    char buffer[200];
    fstream fin(argv[1]);
    fstream fout;
    fout.open(argv[2],ios::out);
    char type;
    long numV;
    long numE;
    long min_cost = 0;
    long count = 0;
    fin >> type;
    fin >> numV;
    fin >> numE;

    int u, v, w;
    DiGraph digraph(numV, numE);
    while ((fin >> u >> v >> w) && count < numE) {
        ++count;
        Edge e = {u, v, w};
        digraph.edge_set.push_back(e);
    }
    vector<Edge> rm_edge;
    digraph.Kruskal(rm_edge);

    if (type == 'u') {
        for (vector<Edge>::iterator it = rm_edge.begin(); it != rm_edge.end(); ++it) {
            min_cost += it->w;
        }
        fout << min_cost << '\n';
        for (vector<Edge>::iterator it = rm_edge.begin(); it != rm_edge.end(); ++it) {
            fout << it->u << " " << it->v << " " << it->w << "\n";
        }
    }
    else if (type == 'd') {
        
        // cout << "before: " << rm_edge.size() << "\n";
        min_cost = digraph.selectEdge(rm_edge);
        // cout << "after: " << rm_edge.size() << "\n";

        fout << min_cost << '\n';
        for (vector<Edge>::iterator it = rm_edge.begin(); it != rm_edge.end(); ++it) {
            fout << it->u << " " << it->v << " " << it->w << "\n";
        }
    }
    else cout << "Type is not among 'u' and 'v'" << endl;

#ifdef DEBUG
    cout << "min_cost: " << min_cost << "\n";
    clock_t end = clock();
    std::cout << "Total memory usage: " << get_mem_usage() << "\n";
    std::cout << "Total time usage: " << double(end-start)/CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}

