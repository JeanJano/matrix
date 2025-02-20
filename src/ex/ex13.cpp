#include "matrix.hpp"

void ex13() {
    {
        Matrix m({
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        });
        m.printMatrix("M");
        size_t rank = m.rank();
        std::cout << "rank = " << rank << std::endl;
        std::cout << std::endl;
    }

    {
        Matrix m({
            {1, 2, 0, 0},
            {2, 4, 0, 0},
            {-1, 2, 1, 1}
        });
        m.printMatrix("M");
        size_t rank = m.rank();
        std::cout << "rank = " << rank << std::endl;
        std::cout << std::endl;
    }

    {
        Matrix m({
            {8, 5, -2},
            {4, 7, 20},
            {7, 6, 1},
            {21, 18, 7}
        });
        m.printMatrix("M");
        size_t rank = m.rank();
        std::cout << "rank = " << rank << std::endl;
        std::cout << std::endl;
    }
}