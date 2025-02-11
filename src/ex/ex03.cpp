#include "matrix.hpp"

void ex03() {
    std::cout << "DOT PRODUCT" << std::endl;
    {
        Vector a({0, 0});
        Vector b({1, 1});
        float d = a.dot(b);
        a.print_vector("A");
        b.print_vector("B");
        std::cout << "A . B = " << d << std::endl << std::endl;
    }

    {
        Vector a({1, 1});
        Vector b({1, 1});
        float d = a.dot(b);
        a.print_vector("A");
        b.print_vector("B");
        std::cout << "A . B = " << d << std::endl << std::endl;
    }

    {
        Vector a({-1, 6});
        Vector b({3, 2});
        float d = a.dot(b);
        a.print_vector("A");
        b.print_vector("B");
        std::cout << "A . B = " << d << std::endl;
    }


}