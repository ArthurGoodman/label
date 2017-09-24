#pragma once

#include <iostream>
#include <numeric>
#include <vector>

#include "matrix.hpp"

class Solver {
public:
    template <class T>
    static T solve(std::vector<Matrix<T>> q, std::vector<Matrix<T>> G) {
        assert(!G.empty());
        assert(q.size() == G.size() + 1);

        for (size_t i = 0; i < G.size(); i++)
            G[i] = Matrix<T>::diagonal(q[i]) * G[i];

        Matrix<T> r = std::accumulate(++G.begin(), G.end(), G[0], std::multiplies<Matrix<T>>());
        return (r * q.back()).sum();
    }
};
