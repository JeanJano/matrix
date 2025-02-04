#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <vector>
# include <initializer_list>

class Vector {
    public:
        Vector();
        Vector(std::initializer_list<float> list);

        int getSize();
        bool isSquare();
        void printVector();
        void toVector();

        void add(Vector &v);
        void sub(Vector &v);
        void scl(float n);

    private:
        std::vector<float> vector;
};

#endif