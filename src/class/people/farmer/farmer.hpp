#ifndef FARMER_HPP
#define FARMER_HPP
#include "../people.hpp"

class Farmer :public People{
    private:
        // container Farm;
        // Penyimpanan Storage;
    public:
        Farmer();
        ~Farmer();
        void cetakLadang();
        void tanam();
        void panen();
        void pungutPajak();
};

#endif