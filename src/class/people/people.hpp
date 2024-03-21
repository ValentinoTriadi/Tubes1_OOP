#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include "Keuangan/StatusKeuangan.hpp"
#include "../container/container.hpp"

class People{
    protected:
        Container storage;
        StatusKeuangan Keuangan;
        int Weight;
        int Type;
    
    public:
    
        People();

        ~People();

        /**/
        void cetakPenyimpanan();

        void makan();
        void membeli();
        void menjual();        
};


#endif