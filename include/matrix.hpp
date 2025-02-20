#ifndef __MATRIX__HPP
# define __MATRIX__HPP

# include "Matrix.hpp"
# include "Vector.hpp"

void print_vector(std::vector<float> &v);
void print_vector(std::vector<float> &v, std::string name);

Vector linear_combination(std::vector<Vector> v_list, std::vector<float> n_list);
Matrix linear_combination(std::vector<Matrix> m_list, std::vector<float> n_list);

float lerp(float a, float b, float t);
Vector lerp(Vector a, Vector b, float t);
Matrix lerp(Matrix a, Matrix b, float t);

float angle_cos(Vector &u, Vector &v);

Vector cross_product(Vector &u, Vector &v);

void ex00();
void ex01();
void ex02();
void ex03();
void ex04();
void ex05();
void ex06();
void ex07();
void ex08();
void ex09();
void ex10();
void ex11();
void ex12();
void ex13();

#endif