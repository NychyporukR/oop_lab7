#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> matrix;

public:
    Matrix(int rows, int cols);
    void inputMatrix();
    void outputMatrix() const;

    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    std::vector<T> operator*(const std::vector<T>& vec) const;
};


template <typename T>
Matrix<T>::Matrix(int rows, int cols) : matrix(rows, std::vector<T>(cols)) {}

template <typename T>
void Matrix<T>::inputMatrix() {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            std::cout << "Enter element at position (" << i << ", " << j << "): ";
            std::cin >> matrix[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::outputMatrix() const {
    for (const auto& row : matrix) {
        for (const T& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (matrix.size() != other.matrix.size() || matrix[0].size() != other.matrix[0].size()) {
        throw std::invalid_argument("Matrix dimensions do not match for addition.");
    }

    Matrix<T> result(matrix.size(), matrix[0].size());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (matrix[0].size() != other.matrix.size()) {
        throw std::invalid_argument("Matrix dimensions are not suitable for multiplication.");
    }

    Matrix<T> result(matrix.size(), other.matrix[0].size());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < other.matrix[0].size(); ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < matrix[0].size(); ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

template <typename T>
std::vector<T> Matrix<T>::operator*(const std::vector<T>& vec) const {
    if (matrix[0].size() != vec.size()) {
        throw std::invalid_argument("Matrix and vector dimensions are not suitable for multiplication.");
    }

    std::vector<T> result(matrix.size(), 0);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            result[i] += matrix[i][j] * vec[j];
        }
    }
    return result;
}

#endif



