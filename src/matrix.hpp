#pragma once

#include <cassert>
#include <cstddef>
#include <sstream>
#include <string>
#include <vector>

template <class T>
class Matrix {
public:
    explicit Matrix() {
    }

    explicit Matrix(size_t rows, size_t cols)
        : m_rows(rows)
        , m_cols(cols)
        , m_data(rows * cols) {
        assert(rows > 0);
        assert(cols > 0);
    }

    static Matrix<T> zero(size_t rows, size_t cols) {
        Matrix m(rows, cols);
        std::fill(m.m_data.begin(), m.m_data.end(), T::zero());
        return m;
    }

    // static Matrix<T> one(size_t rows, size_t cols) {
    //     Matrix m(rows, cols);
    //     std::fill(m.m_data.begin(), m.m_data.end(), T::one());
    //     return m;
    // }

    // static Matrix<T> identity(size_t size) {
    //     Matrix m = zero(size, size);

    //     for (size_t i = 0; i < size; i++)
    //         m.at(i, i) = T::one();

    //     return m;
    // }

    static Matrix<T> diag(const Matrix &v) {
        assert(v.cols() == 1);

        Matrix m = zero(v.rows(), v.rows());

        for (size_t i = 0; i < v.rows(); i++)
            m.at(i, i) = v.at(i, 0);

        return m;
    }

    Matrix<T> operator*(const Matrix &m) const {
        assert(cols() == m.rows());

        Matrix result = Matrix::zero(rows(), m.cols());

        for (size_t i = 0; i < result.rows(); i++)
            for (size_t j = 0; j < result.cols(); j++)
                for (size_t k = 0; k < cols(); k++)
                    result.at(i, j) += at(i, k) * m.at(k, j);

        return result;
    }

    Matrix<T> operator*=(const Matrix &m) {
        *this = *this * m;
        return *this;
    }

    T at(size_t i, size_t j) const {
        return const_cast<Matrix *>(this)->at(i, j);
    }

    T &at(size_t i, size_t j) {
        assert(i < rows());
        assert(j < cols());

        return m_data.at(j + i * cols());
    }

    T sum() const {
        T s = T::zero();

        for (size_t i = 0; i < rows(); i++)
            for (size_t j = 0; j < cols(); j++)
                s += at(i, j);

        return s;
    }

    size_t rows() const {
        return m_rows;
    }

    size_t cols() const {
        return m_cols;
    }

    friend std::ostream &operator<<(std::ostream &s, const Matrix &m) {
        for (size_t i = 0; i < m.rows(); i++) {
            for (size_t j = 0; j < m.cols(); j++)
                s << m.at(i, j) << " ";

            s << std::endl;
        }

        return s;
    }

private:
    size_t m_rows, m_cols;
    std::vector<T> m_data;
};
