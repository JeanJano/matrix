#include "matrix.hpp"

void ex06() {
    {
        Vector u({0, 0, 1});
        Vector v({1, 0, 0});
        u.print_vector("u");
        v.print_vector("v");
        Vector c = cross_product(u, v);
        c.print_vector("C");
        std::cout << std::endl;
    }
    {
        Vector u({1, 2, 3});
        Vector v({4, 5, 6});
        u.print_vector("u");
        v.print_vector("v");
        Vector c = cross_product(u, v);
        c.print_vector("C");
        std::cout << std::endl;
    }
    {
        Vector u({4, 2, -3});
        Vector v({-2, -5, 16});
        u.print_vector("u");
        v.print_vector("v");
        Vector c = cross_product(u, v);
        c.print_vector("C");
    }
}