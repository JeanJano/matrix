#include "vector"
#include "iostream"

void print_vector(std::vector<float> &v) {
    std::vector<float>::size_type count = 1;
    std::cout << "[";
    for (const auto& element : v) {
        std::cout << element;
        if (count != v.size())
            std::cout << ", ";
        count++;
    }
    std::cout << "]" << std::endl;
}

void print_vector(std::vector<float> &v, std::string name) {
    std::cout << name << ": ";
    print_vector(v);
}