#include "matrix.hpp"

void ex05() {
    {
        Vector u({1, 0});
        Vector v({1, 0});
        float cos = angle_cos(u, v);
        u.print_vector("u");
        v.print_vector("v");
        std::cout << "cosine (u, v) = " << cos << std::endl;
    }

    {
        Vector u({1, 0});
        Vector v({0, 1});
        float cos = angle_cos(u, v);
        u.print_vector("u");
        v.print_vector("v");
        std::cout << "cosine (u, v) = " << cos << std::endl;
    }

    {
        Vector u({-1, 1});
        Vector v({1, -1});
        float cos = angle_cos(u, v);
        u.print_vector("u");
        v.print_vector("v");
        std::cout << "cosine (u, v) = " << cos << std::endl;
    }

    {
        Vector u({2, 1});
        Vector v({4, 2});
        float cos = angle_cos(u, v);
        u.print_vector("u");
        v.print_vector("v");
        std::cout << "cosine (u, v) = " << cos << std::endl;
    }

    {
        Vector u({1, 2, 3});
        Vector v({4, 5, 6});
        float cos = angle_cos(u, v);
        u.print_vector("u");
        v.print_vector("v");
        std::cout << "cosine (u, v) = " << cos << std::endl;
    }

    {
        Vector u({0, 0});
        Vector v({4, 5, 6});
        float cos = angle_cos(u, v);
        u.print_vector("u");
        v.print_vector("v");
        std::cout << "cosine (u, v) = " << cos << std::endl;
    }
}