#include "matrix.hpp"

Vector linear_combination(std::vector<Vector> v_list, std::vector<float> n_list) {
    if (v_list.size() != n_list.size())
        throw "linear combination. not same list size";

    Vector b(v_list[0].getSize());

    for (std::vector<Vector>::size_type i = 0; i < v_list.size(); i++) {
        v_list[i].scl(n_list[i]);
    }

    for (std::vector<Vector>::size_type i = 0; i < v_list.size(); i++) {
        b.add(v_list[i]);
    }

    return b;
}

Matrix linear_combination(std::vector<Matrix> m_list, std::vector<float> n_list) {
    if (m_list.size() != n_list.size())
        throw "linear combination. not same list size";

    Matrix b(m_list[0].getShape());

    for (std::vector<Matrix>::size_type i = 0; i < m_list.size(); i++) {
        m_list[i].scl(n_list[i]);
    }

    for (std::vector<Matrix>::size_type i = 0; i < m_list.size(); i++) {
        b.add(m_list[i]);
    }

    return b;
}
