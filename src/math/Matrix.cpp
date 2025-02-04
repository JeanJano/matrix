#include "Matrix.hpp"

Matrix::Matrix() {

}

Matrix::Matrix(std::initializer_list<float> list) {
    this->matrix = list;
}

int Matrix::getShape() {
    return 0;
}

bool Matrix::isSquare() {
    return false;
}

void Matrix::printMatrix() {
    for (int i = 0; i < this->matrix.size(); i++) {
        std::cout << this->matrix[i] << std::endl;
    }
    std::cout << "print matrix ..." << std::endl;
}

void Matrix::toMatrix() {

}
