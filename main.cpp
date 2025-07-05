#include "Matrix.h"

int main() {
    Matrix<int> A(2, 3);
    Matrix<int> B(2, 3);

    A.fillRandom(1, 9);
    B.fillRandom(1, 9);

    std::cout << "Matrix A:\n";
    A.print();

    std::cout << "Matrix B:\n";
    B.print();

    Matrix<int> C = A + B;
    std::cout << "A + B:\n";
    C.print();

    std::cout << "Max in A: " << A.getMax() << "\n";
    std::cout << "Min in B: " << B.getMin() << "\n";

    return 0;
}
