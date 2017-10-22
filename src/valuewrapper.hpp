#pragma once

#include <cstdint>

#include "operators.hpp"

namespace label {

template <
    class T,
    template <class> class TPlus = oper::plus,
    template <class> class TMult = oper::mult>
class ValueWrapper {
    using This = ValueWrapper<T, TPlus, TMult>;

public:
    ValueWrapper()
        : m_value{} {
    }

    ValueWrapper(T value)
        : m_value(value) {
    }

    ValueWrapper<T, TPlus, TMult> operator=(const T &value) {
        m_value = value;

        return *this;
    }

    This operator+(const ValueWrapper &other) const {
        return m_plus(m_value, other.m_value);
    }

    This operator*(const ValueWrapper &other) const {
        return m_mult(m_value, other.m_value);
    }

    This &operator+=(const ValueWrapper &other) {
        *this = *this + other;
        return *this;
    }

    This &operator*=(const ValueWrapper &other) {
        *this = *this * other;
        return *this;
    }

    operator T() const {
        return m_value;
    }

    static size_t argplus(const std::vector<This> &v) {
        return TPlus<T>::arg(unwrapVector(v));
    }

    static size_t argmult(const std::vector<This> &v) {
        return TMult<T>::arg(unwrapVector(v));
    }

    static This zero() {
        return TPlus<T>::zero;
    }

    // static This one() {
    //     return TMult<T>::zero;
    // }

private:
    static std::vector<T> unwrapVector(const std::vector<This> &v) {
        static constexpr auto unwrap = [](const This &t) -> T { return t; };

        std::vector<T> vt;
        std::transform(v.begin(), v.end(), std::back_inserter(vt), unwrap);
        return vt;
    }

private:
    T m_value;

    TPlus<T> m_plus;
    TMult<T> m_mult;
};

} // namespace label
