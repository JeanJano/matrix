#include "matrix.hpp"

void ex08() {
    std::cout << "TRACE" << std::endl;

    {
        Matrix m({
            {1, 0},
            {0, 1}
        });
        m.printMatrix("M");
        float t = m.trace();
        std::cout << "trace = " << t << std::endl << std::endl;
    }
    {
        Matrix m({
            {2, -5, 0},
            {4, 3, 7},
            {-2, 3, 4}
        });
        m.printMatrix("M");
        float t = m.trace();
        std::cout << "trace = " << t << std::endl << std::endl;
    }
    {
        Matrix m({
            {-2, -8, 4},
            {1, -23, 4},
            {0, 6, 4}
        });
        m.printMatrix("M");
        float t = m.trace();
        std::cout << "trace = " << t << std::endl << std::endl;
    }
}