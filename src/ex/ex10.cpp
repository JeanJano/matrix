#include "matrix.hpp"

void ex10() {
    std::cout << "ROW ECHELON FORM" << std::endl << std::endl;
    {
        Matrix m({
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        });
        m.printMatrix("M");
        Matrix rM = m.row_echelon();
        rM.printMatrix("rM");
        std::cout << std::endl;
    }
    {
        Matrix m({
            {1, 2},
            {3, 4},
        });
        m.printMatrix("M");
        Matrix rM = m.row_echelon();
        rM.printMatrix("rM");
        std::cout << std::endl;
    }
    {
        Matrix m({
            {1, 2},
            {2, 4},
        });
        m.printMatrix("M");
        Matrix rM = m.row_echelon();
        rM.printMatrix("rM");
        std::cout << std::endl;
    }
    {
        Matrix m({
            {8, 5, -2, 4, 28},
            {4, 2.5, 20, 4, -4},
            {8, 5, 1, 4, 17}
        });
        m.printMatrix("M");
        Matrix rM = m.row_echelon();
        rM.printMatrix("rM");
        std::cout << std::endl;
    }
}