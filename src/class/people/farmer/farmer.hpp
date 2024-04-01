#ifndef FARMER_HPP
#define FARMER_HPP
#include "../people.hpp"
#include "../../container/container.hpp"


class Farmer : public People {
    private:
        Container Ladang;
    public:
        /**
         * @brief Construct a new Farmer object
         */
        Farmer();

        /**
         * Constructor untuk class Farmer
         * @param weight berat badan dari farmer
         * @param keuangan keuangan dari farmer
         * @param type tipe dari farmer
         * @param n_storage column storage yang dimiliki farmer
         * @param m_storage row storage yang dimiliki farmer
         * @param n_ladang column ladang yang dimiliki farmer
         * @param m_ladang row ladang yang dimiliki farmer
         */
        Farmer(int,int,int,int,int,int,int);

        /**
         * @brief Destroy the Farmer object
         */
        ~Farmer() override;

        void setLadang(const Container& ladang);

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
};

#endif