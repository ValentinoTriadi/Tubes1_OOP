#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T>
class Matrix {
    public:
        Matrix();
        Matrix(int, int);
        ~Matrix();

        void setRow(int);
        void setCol(int);
        int getRow() const;
        int getCol() const;

        T& operator()(int i, int j);

        virtual void printMatrix() const;

    private:
        int row;
        int col;
        vector<vector<T>> matrix;
        int cellKosong;
};

#endif