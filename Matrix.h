#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;

    void allocateMemory() {
        data = new T * [rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols];
    }

    void freeMemory() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        allocateMemory();
    }

    ~Matrix() {
        freeMemory();
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        allocateMemory();
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            freeMemory();
            rows = other.rows;
            cols = other.cols;
            allocateMemory();
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    data[i][j] = other.data[i][j];
        }
        return *this;
    }

    void fillFromInput() {
        std::cout << "Enter elements:\n";
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j) {
                std::cout << "[" << i << "][" << j << "]: ";
                std::cin >> data[i][j];
            }
    }

    void fillRandom(T minVal = 0, T maxVal = 100) {
        std::srand(static_cast<unsigned>(std::time(0)));
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = static_cast<T>(minVal + rand() % (maxVal - minVal + 1));
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                std::cout << data[i][j] << " ";
            std::cout << '\n';
        }
    }

    T getMax() const {
        T maxVal = data[0][0];
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (data[i][j] > maxVal)
                    maxVal = data[i][j];
        return maxVal;
    }

    T getMin() const {
        T minVal = data[0][0];
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (data[i][j] < minVal)
                    minVal = data[i][j];
        return minVal;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
            }
        return result;
    }

    Matrix operator/(T scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] / scalar;
        return result;
    }
};
