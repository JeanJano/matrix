#include "Vector.hpp"

Vector::Vector() {

}

Vector::Vector(std::initializer_list<float> list) {
    this->vector = list;
}

int Vector::getSize() {
    return vector.size();
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

//error si pas la meme taille de liste
//scale chaque vector et les additionner
Vector Vector::linear_combination(std::vector<Vector&> v_list, std::vector<float> n_list) {

}
