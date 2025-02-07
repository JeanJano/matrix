#include "matrix.hpp"

static void vector() {
    Vector e1({1., 0., 0.});
    Vector e2({0., 1., 0.});
    Vector e3({0., 0., 1.});

    std::vector<Vector> v_list1;
    v_list1.push_back(e1);
    v_list1.push_back(e2);
    v_list1.push_back(e3);

    Vector v1({1., 2., 3.});
    Vector v2({0., 10., -100.});

    std::vector<Vector> v_list2;
    v_list2.push_back(v1);
    v_list2.push_back(v2);

    std::vector<float> n_list1;
    n_list1.push_back(10);
    n_list1.push_back(-2);
    n_list1.push_back(0.5);

    std::vector<float> n_list2;
    n_list2.push_back(10);
    n_list2.push_back(-2);

    std::cout << "list vector 1" << std::endl;
    e1.print_vector("A1");
    e2.print_vector("A2");
    e3.print_vector("A3");
    print_vector(n_list1, "coefficient");
    Vector b1 = linear_combination(v_list1, n_list1);
    std::cout << "B1 = ";
    b1.print_vector();
    std::cout << std::endl;

    std::cout << "list vector 2" << std::endl;
    v1.print_vector("A4");
    v2.print_vector("A4");
    print_vector(n_list1, "coefficient");
    Vector b2 = linear_combination(v_list2, n_list2);
    b2.print_vector("B2");
}

static void matrix() {
    Matrix m1({
        {0, 2},
        {1, 1}
    });
    Matrix m2({
        {3, 0},
        {1, 1}
    });
    std::vector<Matrix> m_list;
    m_list.push_back(m1);
    m_list.push_back(m2);

    std::vector<float> n_list;
    n_list.push_back(2);
    n_list.push_back(-1);

    std::cout << "list matrix" << std::endl;
    m1.printMatrix("A1");
    m2.printMatrix("A2");
    print_vector(n_list, "coefficient");
    Matrix b2 = linear_combination(m_list, n_list);
    b2.printMatrix("B2");
}

void ex01() {
    std::cout << "linear combination :" << std::endl << std::endl;

    vector();
    matrix();
}