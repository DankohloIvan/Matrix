#include "Matrix.h"

int main() {
    Matrix<int> matrix_1(3, 3);
    Matrix<int> matrix_2(3, 3);
    std::cout << "Fill 1# matrix:\n";
    matrix_1.input();
    matrix_1.print();
    std::cout << "Fill 2# matrix:\n";
    matrix_2.input();
    matrix_2.print();
    std::cout << '\n';
    std::cout << "Operation +: \n";
    Matrix<int> summa = matrix_1 + matrix_2;
    summa.print();

    std::cout << "Operation -: \n";
    Matrix<int> difference = matrix_1 - matrix_2;
    difference.print();

    std::cout << "Operation *: \n";
    Matrix<int> product = matrix_1 * matrix_2;
    product.print();

    std::cout << "Operation /: \n";
    Matrix<int> division = matrix_1 / matrix_2;
    division.print();

    return 0;
}
