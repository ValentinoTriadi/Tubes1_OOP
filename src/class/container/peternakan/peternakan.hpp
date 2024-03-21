#ifndef PETERNAKAN_HPP
#define PETERNAKAN_HPP
#include "../container.hpp"
#include "../../item/farmEntity/animal/animal.hpp"
class Peternakan : public Container<Animal>{
    public :
        Peternakan(int row, int col);
        ~Peternakan();
        void cetak() override;
        void hapusSlot(int row, int col) override;
};

#endif