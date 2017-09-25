#pragma once

#include <cstdint>

#include "operators.hpp"

template <
    class T,
    template <class> class TPlus = oper::plus,
    template <class> class TMult = oper::mult>
class ValueWrapper {
    using This = ValueWrapper<T, TPlus, TMult>;

public:
    ValueWrapper() {
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

    static This zero() {
        return TPlus<T>::zero;
    }

    static This one() {
        return TMult<T>::zero;
    }

private:
    T m_value;

    TPlus<T> m_plus;
    TMult<T> m_mult;
};
