#include "matrix.hpp"

void ex09() {
    std::cout << "TRANSPOSE" << std::endl;

    {
        Matrix m({
            {1, 2, 3},
            {4, 5, 6}
        });
        m.printMatrix("M");
        Matrix mt = m.transpose();
        mt.printMatrix();
    }
    {
        Matrix m({
            {1, 2, 3},
            {4, 5, 6}, 
            {7, 8, 9}
        });
        m.printMatrix("M");
        Matrix mt = m.transpose();
        mt.printMatrix();
    }
}