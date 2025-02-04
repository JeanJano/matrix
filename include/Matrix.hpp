#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include <vector>
# include <initializer_list>

class Matrix {
    public:
        Matrix();
        Matrix(std::initializer_list<float> list);

        int getShape();
        bool isSquare();
        void printMatrix();
        void toMatrix();

    private:
        std::vector<float> matrix;
};

#endif