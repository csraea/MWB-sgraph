/**
 * @file
 * @author Oleksandr Korotetskyi <csraea@gmail.com>
 * @date 23/02/2022
 *
 * Main function.
 */

#include "ExecutionController.h"

int main(int argc, char **argv)
{
    ExecutionController ctrl = ExecutionController();
    ctrl.Solve(argc, argv);

    exit(EXIT_SUCCESS);
}