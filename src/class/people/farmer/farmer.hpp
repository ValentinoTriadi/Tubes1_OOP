#ifndef FARMER_HPP
#define FARMER_HPP
#include "../people.hpp"
#include "../../container/ladang/ladang.hpp"
#include "../../container/penyimpanan/penyimpanan.hpp" 
class Farmer : People{
    private:
        Ladang Farm;
        Penyimpanan Storage;
    public:
        Farmer();
        ~Farmer();
        void cetakLadang();
        void tanam();
        void panen();
        void pungutPajak();
};

#endif