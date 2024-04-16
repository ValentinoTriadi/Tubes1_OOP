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
        static bool CheckHewan(const string&);

    public:
        /**
         * @brief Construct a new Stockman object
         *
         * @param Name
         * @param weight
         * @param Keuangan
         * @param n_penyimpanan 
         * @param m_penyimpanan
         * @param n_peternakan
         * @param m_peternakan
        */
        Stockman(const string& , int, int, int, int, int, int);
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
        void memberiPangan(int season);
        /**
         * @brief Panen
        */
        void panen();
        /**
         * @brief Set Peternakan
        */
        void setPeternakan(const Peternakan&);

        /**
         * @brief Get Peternakan
        */
        [[nodiscard]] Peternakan getPeternakan() const;

        /**
         * @brief get name animal by code
        */
        [[nodiscard]] string getNameByCode(const string&) const override;

        /**
         * @brief mendapatkan gabungan string antara vector 1 dengan char
        */
        static string join(const vector<string>& vector1, const char *string);
};


#endif