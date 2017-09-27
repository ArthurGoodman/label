#include "algorithm.hpp"

#include "jsonparser.hpp"
#include "solver.hpp"
#include "valuewrapper.hpp"

namespace label {

void Algorithm::run(const std::string &fileName, bool verbose) {
    using ValueType = ValueWrapper<double, oper::max, oper::plus>;

    Task<ValueType> task = parseJsonFile<ValueType>(fileName);
    std::cout << "Result = " << Solver::solve(task.vertices, task.edges, verbose) << std::endl;
}

} // namespace label
