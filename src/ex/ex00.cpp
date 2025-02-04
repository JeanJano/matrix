#include "matrix.hpp"

void vec() {
    std::cout << "VECTOR" << std::endl << std::endl;

    Vector v({1., 2.});
    Vector u({5., 9.});

    std::cout << "v: ";
    v.printVector();
    std::cout << "u: ";
    u.printVector();
    std::cout << std::endl;

    std::cout << "v + u" << std::endl;
    v.add(u);
    v.printVector();
    std::cout << std::endl;

    std::cout << "v - u" << std::endl;
    v.sub(u);
    v.printVector();

    std::cout << std::endl;
    std::cout << "v * 2" << std::endl;
    v.scl(2);
    v.printVector();
}

void mtr() {
    std::cout << "MATRIX" << std::endl << std::endl;

    Matrix a({
        1., 2.,
        3., 4.
    });
    Matrix b ({
        7., 4.,
        -2., 2.
    });

    std::cout << "A: ";
    a.printMatrix();
    std::cout << "B: ";
    b.printMatrix();
}

void ex00() {
    std::cout << "ex 00:" << std::endl;
    // vec();
    mtr();
}