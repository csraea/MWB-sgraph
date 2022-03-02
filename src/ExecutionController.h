/**
 * @file
 * @author Oleksandr Korotetskyi <csraea@gmail.com>
 * @date 01/03/2022
 */

#ifndef EXECUTIONCONTROLLER_H
#define EXECUTIONCONTROLLER_H

#include "Sequential.h"
#include <chrono>
#include <iostream>
#include <stdlib.h>

class ExecutionController {

  private:
    Graph graph;  // graph to process

  public:
    ExecutionController() : graph(Graph()) {
        GetInputData();
    };

    ~ExecutionController() { };

    // solve the task
    void Solve(int argc, char **argv);

  private:
    // load graph data from stdin
    void GetInputData(void); 
    // get method of solving according to the command line argument
    auto GetMethod(const char *method);
    // print results of computation
    void PrintResults(const std::chrono::microseconds duration, const std::pair<size_t, size_t> res);
};

#endif
