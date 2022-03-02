#ifndef SEQUENTIAL_H
#define SEQUENTIAL_H

#include <algorithm>
#include <iostream>
#include <vector>
#include "Graph.h"

class Sequential
{

  public:
    Sequential(){};
    ~Sequential(){};

    // runs the solving
    static std::pair<size_t, size_t> Solve(Graph *graph);

  private:
    /*
     * vertices: info about colors of vertices
     * left:     a queue of sorted edges
     * used:     a set of used edges
     * 
     * Performs the very brute force recursion
    */
    static inline void DFS(VerticeCollection vertices, EdgeCollection left, EdgeCollection used);
};

#endif // SEQUENTIAL_H