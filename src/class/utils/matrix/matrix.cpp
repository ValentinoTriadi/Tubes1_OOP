#include "matrix.hpp"

Matrix::Matrix() : row(0), col(0), cellKosong(0) {
    matrix.clear();
}

Matrix::Matrix(int row, int col) : row(row), col(col), cellKosong(row * col) {
    matrix.clear();
    for (int i = 0; i < row; i++) {
        vector<std::string> temp;
        for (int j = 0; j < col; j++) {
            temp.push_back(" ");
        }
        matrix.push_back(temp);
    }
}

Matrix::~Matrix() {
    matrix.clear();
}

string& Matrix::operator()(int i, int j) {
    return matrix[i][j];
}

void Matrix::setRow(int row) {
    this->row = row;
}

void Matrix::setCol(int col) {
    this->col = col;
}

int Matrix::getRow() const {
    return row;
}

int Matrix::getCol() const {
    return col;
}

void Matrix::printMatrix() const {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}