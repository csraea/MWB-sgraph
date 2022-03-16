#ifndef GRAPH_H
#define GRAPH_H

#include <stdint.h>
#include <iostream>
#include <vector>

enum class Vertice
{
    NONE,
    BLACK,
    WHITE
};

typedef std::vector<Vertice> VerticeCollection;

// a vector of possible edges (pairs of value and vertices) -> 100, (A, B)
typedef std::vector<std::pair<int32_t, std::pair<size_t, size_t>>> EdgeCollection;

class Graph
{
  public:
    int value = 0;                  // total value the graph (sum of all edges)      
    size_t size = 0;                // size of the graph (number of vertices)

    EdgeCollection edges;           // set of edges              
    VerticeCollection vertices;     // vertice colors

    Graph(){ };
    ~Graph(){ };

    // check if graph is bipartite
    static bool IsValid(const VerticeCollection &vertices, const EdgeCollection &edges)
    {
        for (const auto i : edges) {
            const auto verA = vertices.at(i.second.first);
            const auto verB = vertices.at(i.second.second);
            if (verA == verB) return !true;
            if (verA == Vertice::NONE || verB == Vertice::NONE) continue;
        }

        return true;
    }

    // compute the total value of a graph
    static size_t ComputeValue(const EdgeCollection &edges)
    {
        int32_t sum = 0;
        for (const auto i : edges) {
            sum += i.first;
        }

        return sum > 0 ? (size_t) sum : 0; // return vale if it is positive, else return 0
    }

    // print obtained graph info
    static void DisplayGraphInfo(const Graph *graph, bool inDetails=true)
    {
        std::cout << "Size of a graph:\t" << graph->size << std::endl;
        std::cout << "Graph total value:\t" << graph->value << std::endl;

        if(inDetails) {
            std::cout << "Edges:" << std::endl;
            for (const auto i : graph->edges) {
                std::cout << i.first << ", (" << i.second.first
                                     << ", " << i.second.second
                                     << ")" << std::endl;
            }
        }
        
    }
};

#endif // GRAPH_H