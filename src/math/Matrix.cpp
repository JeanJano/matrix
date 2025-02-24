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


// utilite:
// - Résolution de systèmes d'équations linéaires
// - Calcul du rang d'une matrice
// - Calcul de l’inverse d’une matrice
// resume des etapes:
// 1 Pivoting → Trouver la meilleure ligne et l'échanger avec la ligne actuelle.
// 2 Normalisation → Transformer le pivot en 1.
// 3 Élimination sous le pivot → Mettre des 0 sous le pivot.
// 4 Réduction finale → Mettre des 0 au-dessus des pivots pour obtenir la forme échelonnée réduite.
Matrix Matrix::row_echelon() {
    Matrix r_echl(*this);
    int n = this->row;
    int m = this->col;

    int lead = 0;
    for (int r = 0; r < n; ++r) {
        if (lead >= m)
            break;
        int bestRow = r;
        for (int i = r + 1; i < n; ++i) {
            if (abs(r_echl.matrix[i * m + lead]) > abs(r_echl.matrix[bestRow * m + lead])) {
                bestRow = i;
            }
        }
        if (bestRow != r) {
            for (int col = 0; col < m; ++col) {
                swap(r_echl.matrix[r * m + col], r_echl.matrix[bestRow * m + col]);
            }
        }
        float pivot = r_echl.matrix[r * m + lead];
        if (abs(pivot) < 1e-6) {
            ++lead;
            --r;
            continue;
        }
        for (int col = 0; col < m; ++col) {
            r_echl.matrix[r * m + col] /= pivot;
        }
        for (int k = r + 1; k < n; ++k) {
            float factor = r_echl.matrix[k * m + lead];
            for (int col = 0; col < m; ++col) {
                r_echl.matrix[k * m + col] -= factor * r_echl.matrix[r * m + col];
            }
        }
        ++lead;
    }

    for (int r = n - 1; r >= 0; --r) {
        int pivotCol = -1;
        for (int col = 0; col < m; ++col) {
            if (abs(static_cast<float>(r_echl.matrix[r * m + col] - 1.0)) < 1e-6) {
                pivotCol = col;
                break;
            }
        }
        if (pivotCol == -1) continue;
        for (int i = 0; i < r; ++i) {
            float factor = r_echl.matrix[i * m + pivotCol];
            for (int col = 0; col < m; ++col) {
                r_echl.matrix[i * m + col] -= factor * r_echl.matrix[r * m + col];
            }
        }
    }

    return r_echl;
}

float Matrix::determinant() {
    if (!this->isSquare())
        throw "Matrix. determinant. matrix is not square";

    Matrix temp(*this);
    int n = row;
    float det = 1.0;
    int swapCount = 0;

    for (int i = 0; i < n; ++i) {
        int pivotRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(temp.matrix[k * n + i]) > abs(temp.matrix[pivotRow * n + i])) {
                pivotRow = k;
            }
        }
        if (abs(temp.matrix[pivotRow * n + i]) < 1e-6) {
            return 0.0;
        }
        if (pivotRow != i) {
            for (int col = 0; col < n; ++col) {
                swap(temp.matrix[i * n + col], temp.matrix[pivotRow * n + col]);
            }
            swapCount++;
        }
        for (int k = i + 1; k < n; ++k) {
            float factor = temp.matrix[k * n + i] / temp.matrix[i * n + i];
            for (int col = i; col < n; ++col) {
                temp.matrix[k * n + col] -= factor * temp.matrix[i * n + col];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        det *= temp.matrix[i * n + i];
    }
    if (swapCount % 2 != 0) {
        det = -det;
    }

    return det;
}

Matrix Matrix::inverse() {
    if (!this->isSquare())
        throw "Matrix. inverse. matrix is not square";

    float det = this->determinant();
    if (abs(det) < 1e-6) {
        throw "Matrix. inverse. Determinant can not be null";
    }

    int n = row;
    Matrix augmented(n, 2 * n, true);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmented.matrix[i * 2 * n + j] = this->matrix[i * n + j];
            augmented.matrix[i * 2 * n + (j + n)] = (i == j) ? 1.0 : 0.0;
        }
    }
    Matrix reduced = augmented.row_echelon();
    Matrix inverse(n, n, true);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse.matrix[i * n + j] = reduced.matrix[i * 2 * n + (j + n)];
        }
    }

    return inverse;
}

size_t Matrix::rank() {
    Matrix echelonForm = this->row_echelon();
    size_t rank = 0;

    for (int i = 0; i < row; ++i) {
        bool nonZeroRow = false;
        for (int j = 0; j < col; ++j) {
            if (abs(echelonForm.matrix[i * col + j]) > 1e-6) {
                nonZeroRow = true;
                break;
            }
        }
        if (nonZeroRow) ++rank;
    }

    return rank;
}
