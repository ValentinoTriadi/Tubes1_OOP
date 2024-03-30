#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T>
class Matrix {
    public:
        /**
         * @brief Construct a new Matrix object
         */
        Matrix();
        /**
         * @brief Construct a new Matrix object
         * 
         * @param row 
         * @param col 
         */
        Matrix(int, int);
        /**
         * @brief Destroy the Matrix object
         */
        ~Matrix();

        /**
         * @brief Set the Row object
         * 
         * @param row 
         */
        void setRow(int);
        /**
         * @brief Set the Col object
         * 
         * @param col 
         */
        void setCol(int);
        /**
         * @brief Get the Row object
         * 
         * @return row 
         */
        int getRow() const;
        /**
         * @brief Get the Col object
         * 
         * @return col 
         */
        int getCol() const;

        /**
         * @brief Get the matrix object
         * 
         * @param i 
         * @param j 
         * @return T& 
         */
        T& operator()(int i, int j);

        /**
         * @brief Print the matrix object
         */
        virtual void printMatrix() const;

    private:
        int row;
        int col;
        vector<vector<T>> matrix;
        int cellKosong;
};

#endif