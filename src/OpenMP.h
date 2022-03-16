#ifndef OPENMP_H
#define OPENMP_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <omp.h>
#include "Graph.h"

class OpenMP
{

  public:
    OpenMP(){};
    ~OpenMP(){};

    // runs the solving
    static std::pair<size_t, size_t> Solve(Graph *graph);

  private:
    /*
     * vertices: info about colors of vertices
     * left:     a queue of sorted edges
     * used:     a set of used edges
     * 
     * Performs OpenMP parallelism
    */
    static inline void DFS(VerticeCollection vertices, EdgeCollection left, EdgeCollection used);
};

#endif // OPENMP_H