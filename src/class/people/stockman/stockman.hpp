#ifndef STOCKMAN_HPP
#define STOCKMAN_HPP
#include "../people.hpp"
#include "../../container/peternakan/peternakan.hpp"
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
         Peternakan peternakan;
        /*
        * @brief Check If there is an animal in the storage
        * @return true if there is an animal in the storage, false if there is no animal in the storage
        */
        bool CheckHewan(const string&);
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
        Stockman(const string& , int, int, int, int, int, int, int);
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
        /**
         * @brief Set Peternakan
        */
        void setPeternakan(const Peternakan&);
};


#endif