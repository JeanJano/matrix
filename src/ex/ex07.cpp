#include "matrix.hpp"

void ex07() {
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
    }
}
