#include "matrix.hpp"


template <class T>
Matrix<T>::Matrix() : row(0), col(0), cellKosong(0) {
    matrix.clear();
}
template <class T>
Matrix<T>::Matrix(int row, int col) : row(row), col(col), cellKosong(row * col) {
    matrix.clear();
    for (int i = 0; i < row; i++) {
        vector<std::string> temp;
        temp.reserve(col);
        for (int j = 0; j < col; j++) {
            temp.emplace_back(" ");
        }
        matrix.push_back(temp);
    }
}
template <class T>
Matrix<T>::~Matrix() {
    matrix.clear();
}

template<class T>
T& Matrix<T>::operator()(int i, int j) {
    return matrix[i][j];
}
template <class T>
void Matrix<T>::setRow(int Setrow) {
    this->row = Setrow;
}
template <class T>
void Matrix<T>::setCol(int Setcol) {
    this->col = Setcol;
}
template <class T>
int Matrix<T>::getRow() const {
    return row;
}
template <class T>
int Matrix<T>::getCol() const {
    return col;
}
template <class T>
void Matrix<T>::printMatrix() const {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}