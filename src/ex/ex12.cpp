#include "matrix.hpp"

void ex12() {
    {
        Matrix m({
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        });
        m.printMatrix("M");
        Matrix inverse = m.inverse();
        inverse.printMatrix("inverse");
        std::cout << std::endl;
    }
    {
        Matrix m({
            {2, 0, 0},
            {0, 2, 0},
            {0, 0, 2}
        });
        m.printMatrix("M");
        Matrix inverse = m.inverse();
        inverse.printMatrix("inverse");
        std::cout << std::endl;
    }
    {
        Matrix m({
            {8, 5, -2},
            {4, 7, 20},
            {7, 6, 1}
        });
        m.printMatrix("M");
        Matrix inverse = m.inverse();
        inverse.printMatrix("inverse");
        std::cout << std::endl;
    }
}