#include "matrix.hpp"

Vector cross_product(Vector &u, Vector &v) {
    if (u.getSize() != 3 || v.getSize() != 3)
        throw "cross_product. vector sizes different of 3";

    Vector product(3);
    float val = 0;

    val = u.getVector()[1] * v.getVector()[2] - u.getVector()[2] * v.getVector()[1];
    product.setValByIndex(val, 0);
    val = u.getVector()[2] * v.getVector()[0] - u.getVector()[0] * v.getVector()[2];
    product.setValByIndex(val, 1);
    val = u.getVector()[0] * v.getVector()[1] - u.getVector()[1] * v.getVector()[0];
    product.setValByIndex(val, 2);

    return product; 
}