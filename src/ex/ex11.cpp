#include "matrix.hpp"

void ex11() {
    {
        Matrix m({
            {1, -1},
            {-1, 1}
        });
        m.printMatrix("M");
        float determinant = m.determinant();
        std::cout << "determinant = " << determinant << std::endl << std::endl;
    }

    {
        Matrix m({
            {2, 0, 0},
            {0, 2, 0},
            {0, 0, 2}
        });
        m.printMatrix("M");
        float determinant = m.determinant();
        std::cout << "determinant = " << determinant << std::endl << std::endl;
    }

    {
        Matrix m({
            {8, 5, -2},
            {4, 7, 20},
            {7, 6, 1}
        });
        m.printMatrix("M");
        float determinant = m.determinant();
        std::cout << "determinant = " << determinant << std::endl << std::endl;
    }

    {
        Matrix m({
            {8, 5, -2, 4},
            {4, 2.5, 20, 4},
            {8, 5, 1, 4},
            {28, -4, 17, 1}
        });
        m.printMatrix("M");
        float determinant = m.determinant();
        std::cout << "determinant = " << determinant << std::endl << std::endl;
    }
}