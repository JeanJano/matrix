#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <vector>
# include <initializer_list>

class Vector {
    public:
        Vector();
        Vector(std::initializer_list<int> list);
        int getSize();
        bool isSquare();
        void printVector();
        void toVector();

    private:
        std::vector<int> vector;
};

#endif