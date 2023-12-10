#include <iostream>
#include <vector>
#include "Matrix.h"

int main() {
    try {
        Matrix<int> intMatrix(2, 2);
        intMatrix.inputMatrix();
        std::cout << "Entered integer matrix:\n";
        intMatrix.outputMatrix();

        Matrix<float> floatMatrix(2, 2);
        floatMatrix.inputMatrix();
        std::cout << "\nEntered float matrix:\n";
        floatMatrix.outputMatrix();

        // Addition
        Matrix<int> resultIntAddition = intMatrix + intMatrix;
        std::cout << "\nResult of integer matrix addition:\n";
        resultIntAddition.outputMatrix();

        // Multiplication
        Matrix<int> resultIntMultiplication = intMatrix * intMatrix;
        std::cout << "\nResult of integer matrix multiplication:\n";
        resultIntMultiplication.outputMatrix();

        // Matrix-Vector Multiplication
        std::vector<int> intVector = { 1, 2 };
        std::vector<int> resultIntMatrixVectorMultiplication = intMatrix * intVector;
        std::cout << "\nResult of integer matrix-vector multiplication:\n";
        for (const int& element : resultIntMatrixVectorMultiplication) {
            std::cout << element << " ";
        }
        std::cout << std::endl;

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
