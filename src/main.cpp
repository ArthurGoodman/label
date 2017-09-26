#include <iostream>

#include "jsonparser.hpp"
#include "solver.hpp"
#include "valuewrapper.hpp"

int main(int argc, char **argv) {
    using ValueType = ValueWrapper<float, oper::plus, oper::mult>;

    Task<ValueType> task = parseJsonFile<ValueType>("../data.json");
    std::cout << "Result = " << Solver::solve(task.vertices, task.edges, true) << std::endl;

    return 0;
}
