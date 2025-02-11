#include "matrix.hpp"

static bool isValidArg(float t) {
    if (t >= 0 && t <= 1) 
        return true;
    return false;
}

float lerp(float a, float b, float t) {
    if (!isValidArg(t)) throw "lerp. Invalid t";
    return ((1 - t) * a + t * b);
}

Vector lerp(Vector a, Vector b, float t) {
    if (!isValidArg(t)) throw "lerp. Invalid t";
    a.scl(1 - t);
    b.scl(t);
    a.add(b);
    return a;
}

Matrix lerp(Matrix a, Matrix b, float t) {
    if (!isValidArg(t)) throw "lerp. Invalid t";
    a.scl(1 - t);
    b.scl(t);
    a.add(b);
    return a;
}
