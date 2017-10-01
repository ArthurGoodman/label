#include <iostream>

#include "jsonparser.hpp"
#include "solver.hpp"
#include "valuewrapper.hpp"

namespace label {

bool verbose = true;

using ValueType = ValueWrapper<double, oper::max, oper::plus>;

void run(const char *file_name) {
    Task<ValueType> task = parseJsonFile<ValueType>(file_name);
    std::cout << "Result = " << Solver::solve(task.m_vertices, task.m_edges, verbose) << std::endl;
}

} // namespace label

int main(int argc, const char **argv) {
    try {
        if (argc > 1)
            label::run(argv[1]);
        else
            throw std::runtime_error("no input file given\nUsage: label <input_file_name>");
    } catch (const std::runtime_error &e) {
        std::cout << "error: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Something bad happened..." << std::endl;
    }

    return 0;
}
