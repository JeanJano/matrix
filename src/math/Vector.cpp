#include "Vector.hpp"

Vector::Vector() {

}

Vector::Vector(const Vector& cpy) {
    this->vector = cpy.vector;
}

Vector::Vector(int size) {
    for (int i = 0; i < size; i++) {
        this->vector.push_back(0);
    }
}

Vector::Vector(std::initializer_list<float> list) {
    this->vector = list;
}

Vector::~Vector() {

}

Vector& Vector::operator=(const Vector& cpy) {
    if (this == &cpy)
        return *this;

    this->vector = cpy.vector;
}

int Vector::getSize() {
    return vector.size();
}

void Vector::print_vector() {
    std::vector<float>::size_type count = 1;
    std::cout << "[";
    for (const auto& element : this->vector) {
        std::cout << element;
        if (count != this->vector.size())
            std::cout << ", ";
        count++;
    }
    std::cout << "]" << std::endl;
}

void Vector::print_vector(std::string name) {
    if (name.size()) {
        std::cout << name << ": ";
    }
    this->print_vector();
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
