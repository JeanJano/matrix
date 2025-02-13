#include "Matrix.hpp"

Matrix::Matrix() {

}

Matrix::Matrix(const Matrix &cpy) {
    this->shape = new int[2];
    this->shape[0] = cpy.shape[0];
    this->shape[1] = cpy.shape[1];
    this->row = this->shape[0];
    this->col = this->shape[1];

    this->matrix = cpy.matrix;
}

Matrix::Matrix(int *shape) {
    int count = shape[0] * shape[1];
    for (int i = 0; i < count; i++) {
        this->matrix.push_back(0);
    }

    this->shape = new int[2];
    this->shape[0] = this->row = shape[0];
    this->shape[1] = this->col = shape[1];
}

Matrix::Matrix(std::initializer_list<std::initializer_list<float>> list) {

    this->isValidMatrix(list);

    this->col = 0;
    this->row = 0;
    this->shape = new int[2];

    for (const auto &innerList : list) {
        for (const auto &n : innerList) {
            this->matrix.push_back(n);
        }
        this->row++;
    }

    auto col = *list.begin();
    for (const auto &n : col) {
        (void)n;
        this->col++;
    }

    this->shape[0] = this->row;
    this->shape[1] = this->col;
}

Matrix::~Matrix() {
    if (this->shape) {
        delete[] this->shape;
        this->shape = nullptr;
    }
}

Matrix& Matrix::operator=(const Matrix &cpy) {
    if (this == &cpy)
        return *this;

    delete[] this->shape;

    this->shape = new int[2];
    this->shape[0] = cpy.shape[0];
    this->shape[1] = cpy.shape[1];
    this->row = this->shape[0];
    this->col = this->shape[1];

    this->matrix = cpy.matrix;

    return *this;
}

int *Matrix::getShape() {
    return this->shape;
}

bool Matrix::isSquare() {
    return false;
}

void Matrix::printMatrix() {
    std::cout << "print matrix ..." << std::endl;
    std::cout << "[";
    int countRow = 1;
    int countCol = 1;
    for (const auto &n : this->matrix) {
        std::cout << n;
        if (countCol != this->col) 
            std::cout << ", ";
        if (countCol == this->col) {
            std::cout << "]" << std::endl;
            if (countRow != this->row)
                std::cout << "[";
            countRow++;
            countCol = 0;
        }
        countCol++;
    }
}

void Matrix::printMatrix(std::string name) {
    std::cout << name << ": ";
    this->printMatrix();
}

void Matrix::toMatrix() {

}

void Matrix::isValidMatrix(std::initializer_list<std::initializer_list<float>> list) {
    std::vector<int> col;

    for (const auto &innerList : list) {
        int countCol = 0;
        for (const auto &n : innerList) {
            (void)n;
            countCol++;
        }
        col.push_back(countCol);
    }
    int firstVal = col[0];

    for (const auto &n : col) {
        if (n != firstVal)
            throw "invalid matrix";
    }
}

void Matrix::add(Matrix &m) {
    for (std::vector<float>::size_type i = 0; i < this->matrix.size(); i++) {
        this->matrix[i] += m.matrix[i];
    }
}

void Matrix::sub(Matrix &m) {
    for (std::vector<float>::size_type i = 0; i < this->matrix.size(); i++) {
        this->matrix[i] -= m.matrix[i];
    }
}

void Matrix::scl(float n) {
    for (std::vector<float>::size_type i = 0; i < this->matrix.size(); i++) {
        this->matrix[i] *= n;
    }
}

Vector Matrix::mul_vec(Vector &v) {
    if (this->col != v.getSize())
        throw "Matrix. mul_vec. matrix col different of vector size";

    Vector vec(v.getSize());

    for (int i = 0; i < v.getSize(); i++) {
        // vec.setValByIndex(, i);
        // Vector u(this->row);
        for (int j = 0; j < this->row; j++) {
            // u.setValByIndex(this->matrix[])
        }

    }


    return vec;
}
