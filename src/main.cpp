#include "matrix.hpp"

int main() {
    std::cout << "hello matrix" << std::endl;

    try {
        ex00();
        // ex01();
    } catch (const char *e) {
        std::cerr << "error: " << e << std::endl;
    }

}