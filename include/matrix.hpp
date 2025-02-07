#ifndef __MATRIX__HPP
# define __MATRIX__HPP

# include "Matrix.hpp"
# include "Vector.hpp"

void print_vector(std::vector<float> &v);
void print_vector(std::vector<float> &v, std::string name);

Vector linear_combination(std::vector<Vector> v_list, std::vector<float> n_list);
Matrix linear_combination(std::vector<Matrix> m_list, std::vector<float> n_list);

void ex00();
void ex01();

#endif