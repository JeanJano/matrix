#include "matrix.hpp"

void ex04() {
    Vector a({0, 0, 0});
    Vector b({1, 2, 3});
    Vector c({1, 2});

    a.print_vector("A");
    std::cout << "norm Euclidean = " << a.norm() << " ";
    std::cout << "norm Taxicab = " << a.norm_1() << " ";
    std::cout << "norm supremum = " << a.norm_inf() << " ";
    std::cout << std::endl;

    b.print_vector("B");
    std::cout << "norm Euclidean = " << b.norm() << " ";
    std::cout << "norm Taxicab = " << b.norm_1() << " ";
    std::cout << "norm supremum = " << b.norm_inf() << " ";
    std::cout << std::endl;

    c.print_vector("C");
    std::cout << "norm Euclidean = " << c.norm() << " ";
    std::cout << "norm Taxicab = " << c.norm_1() << " ";
    std::cout << "norm supremum = " << c.norm_inf() << " ";
    std::cout << std::endl;

}