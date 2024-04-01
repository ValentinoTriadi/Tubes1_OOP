#ifndef STOCKMAN_HPP
#define STOCKMAN_HPP
#include "../people.hpp"
#include "../../container/container.hpp"
class Stockman : public People{
    private:
        Container Barn;
        Container Storage;
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