#include "Matrix.hpp"

Matrix::Matrix() {

}

Matrix::Matrix(const Matrix &cpy) {
    this->shape = new int[2];
    this->shape[0] = cpy.shape[0];
    this->shape[1] = cpy.shape[1];
    this->row = this->shape[0];
    this->col = this->shape[1];

    this->matrix = cpy.matrix;
}

Matrix::Matrix(int *shape) {
    int count = shape[0] * shape[1];
    for (int i = 0; i < count; i++) {
        this->matrix.push_back(0);
    }

    this->shape = new int[2];
    this->shape[0] = this->row = shape[0];
    this->shape[1] = this->col = shape[1];
}

Matrix::Matrix(int row, int col, bool init) {
    this->shape = new int[2];
    this->shape[0] = this->row = row;
    this->shape[1] = this->col = col;

    if (!init)
        return;
    int count = shape[0] * shape[1];
    for (int i = 0; i < count; i++) {
        this->matrix.push_back(0);
    }
}

Matrix::Matrix(std::initializer_list<std::initializer_list<float>> list) {

    this->isValidMatrix(list);

    this->col = 0;
    this->row = 0;
    this->shape = new int[2];

    for (const auto &innerList : list) {
        for (const auto &n : innerList) {
            this->matrix.push_back(n);
        }
        this->row++;
    }

    auto col = *list.begin();
    for (const auto &n : col) {
        (void)n;
        this->col++;
    }

    this->shape[0] = this->row;
    this->shape[1] = this->col;
}

Matrix::~Matrix() {
    if (this->shape) {
        delete[] this->shape;
        this->shape = nullptr;
    }
}

Matrix& Matrix::operator=(const Matrix &cpy) {
    if (this == &cpy)
        return *this;

    delete[] this->shape;

    this->shape = new int[2];
    this->shape[0] = cpy.shape[0];
    this->shape[1] = cpy.shape[1];
    this->row = this->shape[0];
    this->col = this->shape[1];

    this->matrix = cpy.matrix;

    return *this;
}

int *Matrix::getShape() {
    return this->shape;
}

bool Matrix::isSquare() {
    return (this->col == this->row);
}

void Matrix::printMatrix() {
    std::cout << "print matrix ..." << std::endl;
    std::cout << "[";
    int countRow = 1;
    int countCol = 1;
    for (const auto &n : this->matrix) {
        std::cout << n;
        if (countCol != this->col) 
            std::cout << ", ";
        if (countCol == this->col) {
            std::cout << "]" << std::endl;
            if (countRow != this->row)
                std::cout << "[";
            countRow++;
            countCol = 0;
        }
        countCol++;
    }
}

void Matrix::printMatrix(std::string name) {
    std::cout << name << ": ";
    this->printMatrix();
}

void Matrix::toMatrix() {

}

float &Matrix::at(int i, int j) {
    return this->matrix[i * this->col + j];
}

void Matrix::isValidMatrix(std::initializer_list<std::initializer_list<float>> list) {
    std::vector<int> col;

    for (const auto &innerList : list) {
        int countCol = 0;
        for (const auto &n : innerList) {
            (void)n;
            countCol++;
        }
        col.push_back(countCol);
    }
    int firstVal = col[0];

    for (const auto &n : col) {
        if (n != firstVal)
            throw "invalid matrix";
    }
}

void Matrix::add(Matrix &m) {
    for (std::vector<float>::size_type i = 0; i < this->matrix.size(); i++) {
        this->matrix[i] += m.matrix[i];
    }
}

void Matrix::sub(Matrix &m) {
    for (std::vector<float>::size_type i = 0; i < this->matrix.size(); i++) {
        this->matrix[i] -= m.matrix[i];
    }
}

void Matrix::scl(float n) {
    for (std::vector<float>::size_type i = 0; i < this->matrix.size(); i++) {
        this->matrix[i] *= n;
    }
}

Vector Matrix::mul_vec(Vector &v) {
    if (this->col != v.getSize())
        throw "Matrix. mul_vec. matrix col different of vector size";

    Vector vec(0);
    float vec_val = 0;
    int j = 0;

    for (std::vector<float>::size_type i = 0; i < this->matrix.size(); i++) {
        vec_val += this->matrix[i] * v.getVector()[j];
        j++;
        if (j == this->col) {
            vec.pushVal(vec_val);
            vec_val = 0;
            j = 0;
        }
    }

    return vec;
}

Matrix Matrix::mul_mat(Matrix &m) {
    if (this->row != m.col)
        throw "Matrix. mul_mat. matrix row different of matrix2 col";

    Matrix mat(this->row, m.col, false);
    mat.matrix.resize(this->row * m.col, 0);

    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < m.col; j++) {
            float sum = 0;
            for (int k = 0; k < this->col; k++) {
                sum += this->matrix[i * this->col + k] * m.matrix[k * m.col + j];
            }
            mat.matrix[i * m.col + j] = sum;
        }
    }

    return mat;
}

float Matrix::trace() {
    if (!this->isSquare())
        throw "Matrix. trace. matrix is not square";

    float trace = 0;

    for (std::vector<float>::size_type i = 0; i < this->matrix.size(); i += this->col + 1) {
        trace += this->matrix[i];
    }

    return trace;
}

Matrix Matrix::transpose() {
    Matrix tr(this->col, this->row, true);

    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            tr.matrix[j * this->row + i] = this->matrix[i * this->col + j];
        }
    }

    return tr;
}

Matrix Matrix::row_echelon() {
    Matrix r_echl(*this);
    int i = 0;
    int j = 0;
    int n = this->row;
    int m = this->col;

    while (i < n && j < m) {
        // Chercher un pivot (élément non nul dans la colonne j)
        if (r_echl.at(i, j) == 0) {
            // Chercher une ligne en dessous avec un pivot non nul
            int k = i + 1;
            while (k < n && r_echl.at(k, j) == 0) {
                ++k;
            }
            if (k < n) {
                // Échanger les lignes i et k
                for (int col = 0; col < m; ++col) {
                    std::swap(r_echl.at(i, col), r_echl.at(k, col));
                }
            } else {
                // Si aucun pivot non nul n'est trouvé, on passe à la colonne suivante
                ++j;
                continue;
            }
        }

        // 2. Normaliser la ligne i (diviser par le pivot)
        float pivot = r_echl.at(i, j);
        for (int col = 0; col < m; ++col) {
            r_echl.at(i, col) /= pivot;
        }

        // 3. Éliminer les éléments sous le pivot (i, j)
        for (int k = i + 1; k < n; ++k) {
            float factor = r_echl.at(k, j);
            for (int col = 0; col < m; ++col) {
                r_echl.at(k, col) -= factor * r_echl.at(i, col);
            }
        }

        // Passer à la ligne suivante et à la colonne suivante
        ++i;
        ++j;
    }

    // 4. Éliminer les éléments au-dessus des pivots (du bas vers le haut)
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            float factor = r_echl.at(j, i);
            for (int col = 0; col < m; ++col) {
                r_echl.at(j, col) -= factor * r_echl.at(i, col);
            }
        }
    }

    return r_echl;
}
