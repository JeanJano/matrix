#include "Vector.hpp"

Vector::Vector() {

}

Vector::Vector(std::initializer_list<float> list) {
    this->vector = list;
}

int Vector::getSize() {
    return vector.size();
}

bool Vector::isSquare() {
    return false;
}

void Vector::printVector() {
    std::cout << "[" << vector[0] << ", " << vector[1] << "]" << std::endl;
}

void Vector::toVector() {
    
}

void Vector::add(Vector &v) {
    for (int i = 0; i < this->getSize(); i++) {
        this->vector[i] += v.vector[i];
    }
}

void Vector::sub(Vector &v) {
    for (int i = 0; i < this->getSize(); i++) {
        this->vector[i] -= v.vector[i];
    }
}

void Vector::scl(float n) {
    for (int i = 0; i < this->getSize(); i++) {
        this->vector[i] *= n;
    }
}
