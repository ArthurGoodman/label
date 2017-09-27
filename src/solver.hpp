#pragma once

#include <iostream>
#include <numeric>
#include <vector>

#include "matrix.hpp"

namespace label {

class Solver {
public:
    template <class T>
    static T solve(std::vector<Matrix<T>> q, std::vector<Matrix<T>> G, bool verbose = false) {
        assert(!G.empty());
        assert(q.size() == G.size() + 1);

        for (size_t i = 0; i < G.size(); i++) {
            if (verbose) {
                std::cout << "q[" << i << "] = \n" << q[i] << "\n";
                std::cout << "G[" << i << "] = \n" << G[i] << "\n";
            }

            G[i] = Matrix<T>::diag(q[i]) * G[i];

            if (verbose)
                std::cout << "G[" << i << "] := diag(q[" << i << "]) * G[" << i << "] = \n"
                          << G[i] << "\n";
        }

        Matrix<T> r = std::accumulate(++G.begin(), G.end(), G[0], std::multiplies<Matrix<T>>());

        if (verbose)
            std::cout << "*(G[i]) = \n" << r << "\n";

        r *= q.back();

        T sum = r.sum();

        if (verbose) {
            std::cout << "q[" << q.size() - 1 << "] = \n" << q.back() << "\n";
            std::cout << "R := *(G[i]) * q[" << q.size() - 1 << "] = \n" << r << "\n";
            std::cout << "+(R) = " << sum << "\n\n";
        }

        return sum;
    }
};

} // namespace label
