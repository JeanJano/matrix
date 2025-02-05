#include "Matrix.hpp"

Matrix::Matrix() {

}

Matrix::Matrix(std::initializer_list<std::initializer_list<float>> list) {

    if (!this->isValidMatrix(list)) return;

    this->col = 0;
    this->row = 0;
    this->shape = (int *)malloc(2 * sizeof(int));

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

void Matrix::toMatrix() {

}

//todo retourner une erreur
bool Matrix::isValidMatrix(std::initializer_list<std::initializer_list<float>> list) {
    std::vector<int> col;

    for (const auto &innerList : list) {
        int countCol = 0;
        for (const auto &n : innerList) {
            countCol++;
        }
        col.push_back(countCol);
    }
    int firstVal = col[0];

    for (const auto &n : col) {
        if (n != firstVal)
         std::cout << "il y a un probleme chef";
    }
    return true;
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
