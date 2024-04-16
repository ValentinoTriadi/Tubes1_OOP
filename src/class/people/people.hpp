#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include "../container/container.hpp"
#include "Keuangan/StatusKeuangan.hpp"
#include "../container/container.hpp"
#include "../exception/GameException.hpp"
#include "../exception/InputException.hpp"
#include "../toko/toko.hpp"
#include "../Manager/InputManager/InputManager.hpp"
#include <algorithm>

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
        People(string ,int,int,int,int,int);
    
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
         *  @param Multiplier used for season summer 
         */
        void menjual(float multiplier = 1);

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
         * (1) mayor
         * (2) farmer
         * (3) stockman
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

        /**
         *  @brief Get StatusKeuangan
         */
        [[nodiscard]] StatusKeuangan getStatusKeuangan() const;

        /**
         * Menghitung nilai non uang
         */
        void HitungNonUang();

        /**
         * @brief Kurangi uang
         */
        void KurangiUang(int);

        /**
         * @brief get name by code
        */
        virtual string getNameByCode(const string&) const = 0;

        /**
         * @brief Tambah uang
         */
        void TambahUang(int uang);
};

#endif