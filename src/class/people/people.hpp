#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include "../container/container.hpp"
#include "Keuangan/StatusKeuangan.hpp"

class People{
    protected:
        Container storage;
        StatusKeuangan Keuangan;
        int Weight;
        int Type;
    
    public:
        /*
         * Membuat objek people dengan keuangan 0
         */
        People();

        /*
         * Menghapus objek people
         */
        ~People();

        /*
         *  Mencetak penyimpanan yang dimiliki oleh people
         */
        void cetakPenyimpanan();

        void makan();
        void membeli();
        void menjual();        
};


#endif