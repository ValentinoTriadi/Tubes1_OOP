#ifndef FARMER_HPP
#define FARMER_HPP
#include "../people.hpp"
#include "../../container/container.hpp"


class Farmer : public People {
    private:
        Container Ladang;
    public:
        Farmer();
        ~Farmer();
        void cetakLadang() const;
        void tanam();
        void panen();
        void pungutPajak();
};

#endif