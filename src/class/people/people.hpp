#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include "Keuangan/StatusKeuangan.hpp"

class People{
    protected:
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