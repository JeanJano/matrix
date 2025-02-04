#include "Vector.hpp"

Vector::Vector() {

}

Vector::Vector(std::initializer_list<int> list) {
    for (int value: list) {
        std::cout << value << std::endl;
    }
}

int Vector::getSize() {
    return 0;
}

bool Vector::isSquare() {
    return false;
}

void Vector::printVector() {
    std::cout << "print vector ..." << std::endl;
    // std::cout << vector.front() << std::endl;
    // std::cout << vector[0] << vector[1] << std::endl;
}

void Vector::toVector() {
    
}