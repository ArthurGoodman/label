#pragma once

#include <vector>

#include "matrix.hpp"

template <class T>
struct Task {
    std::vector<Matrix<T>> vertices;
    std::vector<Matrix<T>> edges;
};
