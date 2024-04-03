#ifndef FARMER_HPP
#define FARMER_HPP
#include "../people.hpp"
#include "../../container/ladang/ladang.hpp"




class Farmer : public People {
    private:
        Ladang ladang;
        /*
        * @brief Check If there is an plant in the storage
        * @return true if there is an plant in the storage, false if there is no plant in the storage
        */
        bool CheckTumbuhan(const string&);
    public:
        /**
         * @brief Construct a new Farmer object
         */
        Farmer();

        /**
         * Constructor untuk class Farmer
         * @param nama nama dari farmer
         * @param weight berat badan dari farmer
         * @param keuangan keuangan dari farmer
         * @param type tipe dari farmer
         * @param n_storage column storage yang dimiliki farmer
         * @param m_storage row storage yang dimiliki farmer
         * @param n_ladang column ladang yang dimiliki farmer
         * @param m_ladang row ladang yang dimiliki farmer
         */
        Farmer(const string&, int,int,int,int,int,int);

        /**
         * @brief Destroy the Farmer object
         */
        ~Farmer() override;

        /**
         * @brief Cetak ladang yang dimiliki farmer
         */
        void cetakLadang() const;

        /**
         * @brief Tanam tanaman pada ladang
         */
        void tanam();

        /**
         * @brief Panen tanaman pada ladang
         */
        void panen();

        /**
         * @brief Pungut pajak dari petani
         */
        void pungutPajak();

        /**
         * @brief Set ladang yang dimiliki farmer
         * @param ladang ladang yang dimiliki farmer
         */
        void setLadang(const Ladang &ladang);

        /**
         * Get Ladang yang dimiliki farmer
         */
        [[nodiscard]] Ladang getLadang() const;

        /**
         * @brief get name plant by code
        */
        string getNameByCode(const string&) const override;
};

#endif