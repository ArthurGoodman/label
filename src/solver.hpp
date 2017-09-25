#pragma once

#include <iostream>
#include <numeric>
#include <vector>

#include "matrix.hpp"

class Solver {
public:
    template <class T>
    static T solve(std::vector<Matrix<T>> q, std::vector<Matrix<T>> G, bool verbose = false) {
        assert(!G.empty());
        assert(q.size() == G.size() + 1);

        for (size_t i = 0; i < G.size(); i++) {
            if (verbose) {
                std::cout << "diag(q[" << i << "]) = \n" << Matrix<T>::diagonal(q[i]) << "\n";
                std::cout << "G[" << i << "] = \n" << G[i] << "\n";
            }

            G[i] = Matrix<T>::diagonal(q[i]) * G[i];

            if (verbose)
                std::cout << "diag(q[" << i << "]) * G[" << i << "] = \n" << G[i] << "\n";
        }

        Matrix<T> r = std::accumulate(++G.begin(), G.end(), G[0], std::multiplies<Matrix<T>>());

        if (verbose)
            std::cout << "*(G[i]) = \n" << r << "\n";

        r *= q.back();

        if (verbose) {
            std::cout << "q[" << q.size() - 1 << "] = \n" << q.back() << "\n";
            std::cout << "*(G[i]) * q[" << q.size() - 1 << "] = \n" << r << "\n";
        }

        return r.sum();
    }
};
