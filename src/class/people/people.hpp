#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include "Keuangan/StatusKeuangan.hpp"
#include "../container/container.hpp"

class People{
    protected:
        Container storage;
        /**
         * Money monitor of user
         * default = 50 gulden
        */
        StatusKeuangan Keuangan;
        /**
         * weight of user
         * default = 40 kg
        */
        int Weight;
        /**
         * type of user
         * (1) mayor
         * (2) farmer
         * (3) stockman
        */
        int Type;
    
    public:
        /**
         * @param weight saved the weight of user
         * @param Keuangan saved the money of user
         * @param Type type of user
        */
        People(int,int,int);
    
        People();

        ~People();

        /**/
        void cetakPenyimpanan();

        void makan();
        void membeli();
        void menjual();

        // getter for weight
        int GetWeight() {return Weight;}   

        // getter for Keuangan
        int GetKeuangan() {return Keuangan.GetMoney();}

        int GetType(){return Type;}

        void SetContainer(const Container&);


};


#endif