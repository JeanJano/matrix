#include "matrix.hpp"

static void nb() {
    float l1 = lerp(0, 1, 0);
    float l2 = lerp(0, 1, 1);
    float l3 = lerp(0, 1, 0.5);
    float l4 = lerp(21, 42, 0.3);

    std::cout << "lerp(0, 1, 0) = " << l1 << std::endl;
    std::cout << "lerp(0, 1, 1) = " << l2 << std::endl;
    std::cout << "lerp(0, 1, 0.5) = " << l3 << std::endl;
    std::cout << "lerp(21, 42, 0.3) = " << l4 << std::endl;
}

static void vector() {
    Vector a({2, 1});
    Vector b({4, 2});
    Vector l1 = lerp(a, b, 0.3);
    std::cout << "lerp([2, 1], [4, 2], 0.3) = ";
    l1.print_vector();
}

static void matrix() {
    Matrix a({{2, 1}, {3, 4}});
    Matrix b({{20, 10}, {30, 40}});
    Matrix l1 = lerp(a, b, 0.5);
    std::cout << "lerp([[2., 1.], [3., 4.]], [20., 10.], [30., 40.]], 0.5) = ";
    l1.printMatrix();
}

void ex02() {
    nb();
    vector();
    matrix();
}