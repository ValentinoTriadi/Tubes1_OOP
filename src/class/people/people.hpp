#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include "../container/container.hpp"
#include "Keuangan/StatusKeuangan.hpp"
#include "../container/container.hpp"

class People{
    protected:
        /**
         * name of user
        */
        string name;

        /**
         * Container storage of user
        */
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
        People(const string&,int,int,int,int,int);
    
        People();

        /**
         * @brief Menghapus objek people
         */
        virtual ~People();

        /**
         *  @brief Mencetak penyimpanan yang dimiliki oleh people
         */
        void cetakPenyimpanan();

        /**
         *  @brief Makan
         */
        void makan();

        /**
         *  @brief Membeli
         */
        void membeli();

        /**
         *  @brief Menjual
         */
        void menjual();

        /**
         *  @brief Set container
         *  @param container container yang akan di set
         */
        [[nodiscard]] int GetWeight() const {return Weight;}

        /**
         *  @brief Get Keuangan
         *  @return Keuangan
         */
        [[nodiscard]] int GetKeuangan() {return Keuangan.GetMoney();}

        /**
         *  @brief Get Type
         *  @return Type
         */
        [[nodiscard]] int GetType() const {return Type;}

        /**
         *  @brief Get Name
         *  @return Name
         */
        [[nodiscard]] string GetName() const{return name;}

        /**
         *  @brief Set container
         *  @param container container yang akan di set
         */
        void setStorage(const Container&);

        /**
         *  @brief Get container
         *  @return container
         */
        [[nodiscard]] Container getStorage() const;

};

#endif