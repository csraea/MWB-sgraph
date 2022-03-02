#include "Sequential.h"

static size_t recNum = 0;   // total num of recursions performed
static size_t maxVal = 0;   // the maximal possible value of weighted subgraph (solution)

std::pair<size_t, size_t> Sequential::Solve(Graph *graph)
{
    std::sort(std::begin(graph->edges), std::end(graph->edges), [](const auto &a, const auto &b)
              { return a.first > b.first; });

    EdgeCollection tmp;
    DFS(graph->vertices, graph->edges, tmp);

    return std::make_pair(maxVal, recNum);
}

void Sequential::DFS(VerticeCollection vertices, EdgeCollection left, EdgeCollection used)
{
    // check if it is a valid bipartite graph
    if (!Graph::IsValid(vertices, used)) { return; }

    recNum++;

    const auto remVal = Graph::ComputeValue(left);
    const auto curVal = Graph::ComputeValue(used);

    // check the current state space
    if (maxVal >= (curVal + remVal) || left.size() == 0) {
        // the very heuristic
        if (maxVal < curVal) { maxVal = curVal; }
        return;
    }

    // color the first vertice of the corresponding edge (from those which left)
    const auto test = left[0];
    const auto verA = test.second.first;
    const auto verB = test.second.second;

    // delete the edge which is currently being processed from the set of remaining ones
    left.erase(left.begin());

    // first possibility of coloring
    VerticeCollection tmpVer1(vertices);
    EdgeCollection tmpLeft1(left);
    EdgeCollection tmpUsed1(used);

    tmpUsed1.push_back(test);
    tmpVer1.at(verA) = Vertice::WHITE;
    tmpVer1.at(verB) = Vertice::BLACK;
    if (Graph::IsValid(tmpVer1, tmpUsed1)) {
        DFS(tmpVer1, tmpLeft1, tmpUsed1);
    }

    // second possibility of coloring
    VerticeCollection tmpVer2(vertices);
    EdgeCollection tmpLeft2(left);
    EdgeCollection tmpUsed2(used);

    tmpUsed2.push_back(test);
    tmpVer2.at(verA) = Vertice::BLACK;
    tmpVer2.at(verB) = Vertice::WHITE;
    if (Graph::IsValid(tmpVer2, tmpUsed2)) { 
        DFS(tmpVer2, tmpLeft2, tmpUsed2);
    }

    // the edge is not added to the final solution
    DFS(vertices, left, used);
}