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
        void printVector();
        void toVector();

        void add(Vector &v);
        void sub(Vector &v);
        void scl(float n);

        Vector linear_combination(std::vector<Vector&> v_list, std::vector<float> n_list);

    private:
        std::vector<float> vector;
};

#endif