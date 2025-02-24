#include "matrix.hpp"

static void matrix_by_vector() {
    std::cout << "Matrix by Vector" << std::endl;
    {
        Matrix m({
            {1, 0}, 
            {0, 1}
        });
        Vector v({4, 2});
        m.printMatrix("M");
        v.print_vector("V");
        Vector mv = m.mul_vec(v);
        std::cout << "M.V = ";
        mv.print_vector();
        std::cout << std::endl;
    }

    {
        Matrix m({
            {2, 0}, 
            {0, 2}
        });
        Vector v({4, 2});
        m.printMatrix("M");
        v.print_vector("V");
        Vector mv = m.mul_vec(v);
        std::cout << "M.V = ";
        mv.print_vector();
        std::cout << std::endl;
    }

    {
        Matrix m({
            {2, -2}, 
            {-2, 2}
        });
        Vector v({4, 2});
        m.printMatrix("M");
        v.print_vector("V");
        Vector mv = m.mul_vec(v);
        std::cout << "M.V = ";
        mv.print_vector();
        std::cout << std::endl;
    }

    {
        Matrix m({
            {4, 5, 6}, 
            {6, 5, 4},
            {4, 6, 5}
        });
        Vector v({1, 2, 3});
        m.printMatrix("M");
        v.print_vector("V");
        Vector mv = m.mul_vec(v);
        std::cout << "M.V = ";
        mv.print_vector();
        std::cout << std::endl;
    }
}

static void matrix_by_matrix() {
    std::cout << "MATRIX BY MATRIX" << std::endl;
    {
        Matrix m1({
            {1, 0},
            {0, 1}
        });
        Matrix m2({
            {1, 0},
            {0, 1}
        });
        m1.printMatrix("m1");
        m2.printMatrix("m2");
        Matrix m = m1.mul_mat(m2);
        m.printMatrix();
        std::cout << std::endl;
    }
    {
        Matrix m1({
            {1, 0},
            {0, 1}
        });
        Matrix m2({
            {2, 1},
            {4, 2}
        });
        m1.printMatrix("m1");
        m2.printMatrix("m2");
        Matrix m = m1.mul_mat(m2);
        m.printMatrix();
        std::cout << std::endl;
    }
    {
        Matrix m1({
            {3, -5},
            {6, 8}
        });
        Matrix m2({
            {2, 1},
            {4, 2}
        });
        m1.printMatrix("m1");
        m2.printMatrix("m2");
        Matrix m = m1.mul_mat(m2);
        m.printMatrix();
        std::cout << std::endl;
    }
     {
        Matrix m1({
            {1, 2, 3},
            {4, 5, 6}
        });
        Matrix m2({
            {7, 8},
            {9, 10},
            {11, 12}
        });
        m1.printMatrix("m1");
        m2.printMatrix("m2");
        Matrix m = m1.mul_mat(m2);
        m.printMatrix();
        std::cout << std::endl;
    }
}

void ex07() {
    std::cout << "LINEAR MAP" << std::endl;
    matrix_by_vector();
    matrix_by_matrix();
}
