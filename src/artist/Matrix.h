#pragma once

#include <initializer_list>
#include <cassert>

template <typename T, unsigned Rows, unsigned Columns>
class Matrix {
public:
    T mat[Rows][Columns] = {};

    Matrix() {
        for (int i = 0; i < Rows; ++i)
            for (int j = 0; j < Columns; ++j)
                mat[i][j] = 0;
    }

    Matrix(const std::initializer_list<std::initializer_list<T>>& initList) {
        assert(initList.size() <= Rows && "Too many rows in initializer list!");

        int i = 0;
        for (const auto& row : initList) {
            assert(row.size() <= Columns && "Too many columns in a row!");
            int j = 0;
            for (const auto& x : row) {
                mat[i][j] = x;
                j++;
            }
            i++;
        }
    }

    Matrix(const std::initializer_list<T>& initList) {
        assert(initList.size() <= Rows && "Too many elements in initializer list for a vector!");

        unsigned i = 0;
        for (const auto& x : initList) {
            mat[i][0] = x;
            i++;
        }
    }

    template <unsigned OtherColumns>
    Matrix<T, Rows, OtherColumns> operator*(const Matrix<T, Columns, OtherColumns>& other) const {
        Matrix<T, Rows, OtherColumns> result;

        for (unsigned i = 0; i < Rows; ++i) {
            for (unsigned j = 0; j < OtherColumns; ++j) {
                for (unsigned k = 0; k < Columns; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    T& operator()(unsigned row, unsigned col) {
        assert(row < Rows && col < Columns && "Index out of bounds!");
        return mat[row][col];
    }
};

template <typename T, unsigned Dim>
using Vector = Matrix<T, Dim, 1>;
