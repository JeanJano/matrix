#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <vector>
# include <initializer_list>
# include <string>
# include <cmath>
# include <algorithm>

float abs(float n);
float sqrt(float n);

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
        bool isZero();

        void add(Vector &v);
        void sub(Vector &v);
        void scl(float n);
        float dot(Vector& v);

        float norm();
        float norm_1();
        float norm_inf();

        std::vector<float> getVector();
        void setValByIndex(float val, int index);
        void pushVal(float val);

    private:
        std::vector<float> vector;
};

#endif