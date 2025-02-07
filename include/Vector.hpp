#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <vector>
# include <initializer_list>
# include <string>

class Vector {
    public:
        Vector();
        Vector(const Vector& cpy);
        Vector(std::initializer_list<float> list);
        Vector(int size);
        ~Vector();

        Vector& operator=(const Vector& cpy);

        int getSize();
        void print_vector();
        void print_vector(std::string name);
        void toVector();

        void add(Vector &v);
        void sub(Vector &v);
        void scl(float n);

    private:
        std::vector<float> vector;
};

#endif