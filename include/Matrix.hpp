#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include <vector>
# include <initializer_list>

class Matrix {
    public:
        Matrix();
        Matrix(const Matrix &cpy);
        Matrix(int *shape);
        Matrix(std::initializer_list<std::initializer_list<float>> list);
        ~Matrix();

        Matrix& operator=(const Matrix& cpy);

        int *getShape();
        bool isSquare();
        void printMatrix();
        void printMatrix(std::string name);
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