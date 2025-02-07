#include "matrix.hpp"

static void vector() {
    std::cout << "VECTOR" << std::endl << std::endl;

    Vector v({1., 2.});
    Vector u({5., 9.});

    std::cout << "v: ";
    v.print_vector();
    std::cout << "u: ";
    u.print_vector();
    std::cout << std::endl;

    std::cout << "v + u" << std::endl;
    v.add(u);
    v.print_vector();
    std::cout << std::endl;

    std::cout << "v - u" << std::endl;
    v.sub(u);
    v.print_vector();

    std::cout << std::endl;
    std::cout << "v . 2" << std::endl;
    v.scl(2);
    v.print_vector();
}

static void matrix() {
    std::cout << "MATRIX" << std::endl << std::endl;

    Matrix a({
        {1., 2.},
        {3., 4.},
    });
    Matrix b({
        {7., 4.},
        {-2., 2.},
    });

    std::cout << "A: ";
    a.printMatrix();
    std::cout << "B: ";
    b.printMatrix();
    std::cout << std::endl;

    std::cout << "A + B: " << std::endl;
    a.add(b);
    std::cout << "A: ";
    a.printMatrix();
    std::cout << std::endl;

    std::cout << "A - B: " << std::endl;
    a.sub(b);
    std::cout << "A: ";
    a.printMatrix();
    std::cout << std::endl;

    std::cout << "A . 2: " << std::endl;
    a.scl(2);
    std::cout << "A: ";
    a.printMatrix();
    std::cout << std::endl;

}

void ex00() {
    std::cout << "ex 00:" << std::endl;
    vector();
    matrix();
}