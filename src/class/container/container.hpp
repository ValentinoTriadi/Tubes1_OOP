#ifndef __CONTAINER_HPP__
#define __CONTAINER_HPP__
#include <vector>

using namespace std;
template <class T>
class Container{
    private:
        int rowLength;
        int colLength;
        vector<vector<T>> Matrix;
    public:
        Container(int row, int col);
        ~Container();
        virtual void cetak() = 0;
        virtual void hapusSlot(int row, int col) = 0;
};

#endif
