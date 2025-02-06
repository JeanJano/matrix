#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include <vector>
# include <initializer_list>

class Matrix {
    public:
        Matrix();
        Matrix(std::initializer_list<std::initializer_list<float>> list);

        int *getShape();
        bool isSquare();
        void printMatrix();
        void toMatrix();

        void add(Matrix &m);
        void sub(Matrix &m);
        void scl(float n);

    private:
        void isValidMatrix(std::initializer_list<std::initializer_list<float>> list);

        std::vector<float> matrix;
        int *shape;
        int col;
        int row;
};

#endif