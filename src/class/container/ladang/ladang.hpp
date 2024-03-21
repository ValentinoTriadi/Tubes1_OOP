#ifndef LADANG_HPP
#define LADANG_HPP
#include "../container.hpp"
#include "../../item/farmEntity/plant/plant.hpp"

class Ladang : public Container<Plant>{
    public:
        Ladang(int row, int col);
        ~Ladang();
        void cetak() override;
        void hapusSlot(int row, int col) override;
};


#endif