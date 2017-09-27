#include <iostream>

#include "jsonparser.hpp"
#include "solver.hpp"
#include "valuewrapper.hpp"

namespace label {

const char *file_name = "data.json";
bool verbose = true;

using ValueType = ValueWrapper<double, oper::max, oper::plus>;

void run() {
    Task<ValueType> task = parseJsonFile<ValueType>(file_name);
    std::cout << "Result = " << Solver::solve(task.m_vertices, task.m_edges, verbose) << std::endl;
}

} // namespace label

int main() {
    try {
        label::run();
    } catch (const std::runtime_error &e) {
        std::cout << "runtime error: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Something bad happened..." << std::endl;
    }

    return 0;
}
