#include "container.hpp"


template <class T>
Container<T>::Container(int row, int col) : rowLength(row), colLength(col){
    T empty_value;
    for (int i = 0; i < row; i++) {
        vector<T> temp;
        for (int j = 0; j < col; j++) {
            temp.push_back(empty_value);
        }
        matrix.push_back(temp);
    }
}

template <class T>
Container<T>::~Container(){
    Matrix.clear();
}