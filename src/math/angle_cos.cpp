#include "matrix.hpp"

float angle_cos(Vector &u, Vector &v) {
    if (v.getSize() != v.getSize()) 
        throw "angle_cos. vector different size";
    if (u.isZero() || v.isZero())
        throw "angle_cos. one or both vector are zero";
    float cos = 0;
    cos += u.dot(v);
    cos /= (u.norm() * v.norm());
    return cos;
}