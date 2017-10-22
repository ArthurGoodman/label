#pragma once

#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

namespace label {
namespace oper {

template <class T>
struct or_ {
    T operator()(const T &lhs, const T &rhs) const {
        return lhs || rhs;
    }

    static T arg(const std::vector<T> &v, size_t &i) {
        std::runtime_error("operation 'argor' doesn't make sense");
    }

    static constexpr T zero = 0;
};

template <class T>
struct and_ {
    T operator()(const T &lhs, const T &rhs) const {
        return lhs && rhs;
    }

    static T arg(const std::vector<T> &v, size_t &i) {
        std::runtime_error("operation 'argand' doesn't make sense");
    }

    static constexpr T zero = 1;
};

template <class T>
struct min {
    T operator()(const T &lhs, const T &rhs) const {
        return std::min(lhs, rhs);
    }

    static T arg(const std::vector<T> &v, size_t &arg) {
        T min = std::numeric_limits<T>::max();

        for (size_t i = 0; i < v.size(); i++)
            if (v[i] < min) {
                min = v[i];
                arg = i;
            }

        return min;
    }

    static constexpr T zero = std::numeric_limits<T>::has_infinity
                                  ? std::numeric_limits<T>::infinity()
                                  : std::numeric_limits<T>::max() / 2;
};

template <class T>
struct max {
    T operator()(const T &lhs, const T &rhs) const {
        return std::max(lhs, rhs);
    }

    static T arg(const std::vector<T> &v, size_t &arg) {
        T max = std::numeric_limits<T>::min();

        for (size_t i = 0; i < v.size(); i++)
            if (v[i] > max) {
                max = v[i];
                arg = i;
            }

        return max;
    }

    static constexpr T zero = std::numeric_limits<T>::has_infinity
                                  ? -std::numeric_limits<T>::infinity()
                                  : std::numeric_limits<T>::min();
};

template <class T>
struct plus {
    T operator()(const T &lhs, const T &rhs) const {
        return lhs + rhs;
    }

    static T arg(const std::vector<T> &v, size_t &i) {
        std::runtime_error("operation 'argplus' doesn't make sense");
    }

    static constexpr T zero = 0;
};

template <class T>
struct mult {
    T operator()(const T &lhs, const T &rhs) const {
        return lhs * rhs;
    }

    static T arg(const std::vector<T> &v, size_t &i) {
        std::runtime_error("operation 'argmult' doesn't make sense");
    }

    static constexpr T zero = 1;
};

} // namespace oper
} // namespace label
