#pragma once

#include <algorithm>
#include <limits>

namespace label {
namespace oper {

template <class T>
struct or_ {
    T operator()(const T &lhs, const T &rhs) const {
        return lhs || rhs;
    }

    static constexpr T zero = 0;
};

template <class T>
struct and_ {
    T operator()(const T &lhs, const T &rhs) const {
        return lhs && rhs;
    }

    static constexpr T zero = 1;
};

template <class T>
struct min {
    T operator()(const T &lhs, const T &rhs) const {
        return std::min(lhs, rhs);
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

    static constexpr T zero = std::numeric_limits<T>::has_infinity
                                  ? -std::numeric_limits<T>::infinity()
                                  : std::numeric_limits<T>::min();
};

template <class T>
struct plus {
    T operator()(const T &lhs, const T &rhs) const {
        return lhs + rhs;
    }

    static constexpr T zero = 0;
};

template <class T>
struct mult {
    T operator()(const T &lhs, const T &rhs) const {
        return lhs * rhs;
    }

    static constexpr T zero = 1;
};

} // namespace oper
} // namespace label

