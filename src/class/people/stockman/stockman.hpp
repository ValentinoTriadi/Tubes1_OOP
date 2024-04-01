#ifndef STOCKMAN_HPP
#define STOCKMAN_HPP
#include "../people.hpp"
#include "../../container/container.hpp"
/**
 * @param weight
 * @param Keuangan
 * @param Type
 * @param n_penyimpanan 
 * @param m_penyimpanan
 * @param n_peternakan
 * @param m_peternakan
*/
class Stockman : public People{
    private:
        Container Peternakan;
    public:
        /**
         * @brief Construct a new Stockman object
         * 
         * @param weight
         * @param Keuangan
         * @param Type
         * @param n_penyimpanan 
         * @param m_penyimpanan
         * @param n_peternakan
         * @param m_peternakan
        */
        Stockman(int, int, int, int, int, int, int);
        /**
         * @brief Destroy the Stockman object
        */
        ~Stockman();
        /**
         * @brief Cetak Peternakan
        */
        void cetakPeternakan();
        /**
         * @brief Ternak
        */
        void ternak();
        /**
         * @brief Memberi Pangan
        */
        void memberiPangan();
        /**
         * @brief Panen
        */
        void panen();
        /**
         * @brief Pungut Pajak
        */
        void pungutPajak();
};


#endif