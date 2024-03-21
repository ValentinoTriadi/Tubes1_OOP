#ifndef PENYIMPANAN_HPP
#define PENYIMPANAN_HPP
#include "../container.hpp"
#include "../../item/item.hpp"
class Penyimpanan : public Container<Item>{
    public:
        Penyimpanan(int row, int col);
        ~Penyimpanan();
        void cetak();
        void hapusSlot(int row, int col);
};


#endif