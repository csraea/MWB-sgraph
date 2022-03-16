#include "ExecutionController.h"

auto ExecutionController::GetMethod(const char *arg){

    switch (arg[0]) {
        case (int)'s':     return &Sequential::Solve;
        case (int)'o':     return &OpenMP::Solve;
        default:           break;
    }

    std::cout << "Default Sequential method is chosen.\n";
    return &Sequential::Solve;
}

void ExecutionController::GetInputData(void) {

    // read the size of a graph
    std::cin >> this->graph.size;

    // set the color of all vertices to NONE as the default one
    this->graph.vertices.resize(this->graph.size, Vertice::NONE);

    // fill in the values of edges
    int32_t val;
    for (size_t i = 0; i < this->graph.size; i++) {
        for (size_t j = 0; j < this->graph.size; j++) {
            std::cin >> val;
            if (i < j) {
                this->graph.edges.emplace_back(std::make_pair(val, std::make_pair(j, i)));
                this->graph.value += val;
            }
        }
    }
}

void ExecutionController::Solve(int argc, char **argv) {
    
    auto func = GetMethod(argv[1]);

    Graph::DisplayGraphInfo(&(this->graph), false);

    // measure the execution time
    const auto start = std::chrono::high_resolution_clock::now();
    const auto res = func(&(this->graph));
    const auto stop = std::chrono::high_resolution_clock::now();

    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    PrintResults(duration, res);
}

void ExecutionController::PrintResults(const std::chrono::microseconds duration, const std::pair<size_t, size_t> res) {
    
    std::cout << "Max value of bipartite subgraph: " << res.first << std::endl;
    std::cout << "Number of recursions:            " << res.second << std::endl;
    std::cout << "Execution time (microseconds):   " << duration.count() << std::endl;
}