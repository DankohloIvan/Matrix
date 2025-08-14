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
public:
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;

        data = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols]{};
        }
    }

    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;

        data = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }

        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        rows = other.rows;
        cols = other.cols;

        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }

        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void input() {
        for (int i = 0; i < rows; ++i) {
            std::cout << "Enter: " << i + 1 << '#' << " row:\n";
            for (int j = 0; j < cols; ++j) {
                std::cout << "    Enter: " << j + 1 << '#' << " column: ";
                std::cin >> data[i][j];
            }
        }
    }

    void fillRandom() {
        std::srand(std::time(0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = std::rand() % 100;
            }
        }
    }

    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            return Matrix<T>(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            return Matrix<T>(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix<T> operator/(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            return Matrix<T>(0, 0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] / other.data[i][j];
            }
        }
        return result;
    }

    T findMax() const {
        if (rows == 0 || cols == 0) {
            return T();
        }

        T maxVal = data[0][0];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] > maxVal)
                    maxVal = data[i][j];
            }
        }
        return maxVal;
    }

    T findMin() const {
        if (rows == 0 || cols == 0) {
            return T();
        }

        T minVal = data[0][0];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (data[i][j] < minVal)
                    minVal = data[i][j];
            }
        }
        return minVal;
    }

};
