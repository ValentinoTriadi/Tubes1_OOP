#ifndef STOCKMAN_HPP
#define STOCKMAN_HPP
#include "../people.hpp"
#include "../../container/penyimpanan/penyimpanan.hpp"
#include "../../container/peternakan/peternakan.hpp"
class Stockman : public People{
    private:
        Peternakan Barn;
        Penyimpanan Storage;
    public:
        Stockman();
        ~Stockman();
        void cetakPeternakan();
        void ternak();
        void memberiPangan();
        void panen();
        void pungutPajak();
};


#endif