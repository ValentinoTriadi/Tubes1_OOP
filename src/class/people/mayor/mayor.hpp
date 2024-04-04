
#ifndef MAYOR_HPP_
#define MAYOR_HPP_
#include "../people.hpp"
#include "../../gameData/gameData.hpp"
#include "../farmer/farmer.hpp"
#include "../stockman/stockman.hpp"
#include "../../utils/roundRobin/roundRobin.hpp"

class Mayor : public People {
public:
    /*
     * Membuat objek mayor.
     * @param nama nama dari mayor
     * @param weight berat badan dari mayor
     * @param keuangan keuangan dari mayor
     * @param n_storage column storage yang dimiliki mayor
     * @param m_storage row storage yang dimiliki mayor
     */
    Mayor(const string& nama, int weight, int keuangan, int n_storage, int m_storage);

    /*
     * Membangun bangunan baru menggunakan barang-barang yang ada di storage
     * Jika barang tidak cukup, maka bangunan tidak akan terbangun
     * Validasi bangunan melalui recipe yang ada di config
     */
    void bangun();

    /*
     * Menambahkan pemain baru
     */
    void tambahPemain(roundRobin<People *> *listPlayer);

    void PrintBuildingRecipe();

    string getNameByCode(const string &) const;

    static void TagihPajak(roundRobin<People *> *listPlayer);
};

#endif