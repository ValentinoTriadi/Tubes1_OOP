
#ifndef MAYOR_HPP_
#define MAYOR_HPP_
#include "../people.hpp"

class Mayor : public People {
public:
    /*
     * Membuat objek mayor.
     */
    Mayor(const string& nama, int weight, int keuangan, int type, int n_storage, int m_storage);

    /*
     * Membangun bangunan baru menggunakan barang-barang yang ada di storage
     * Jika barang tidak cukup, maka bangunan tidak akan terbangun
     * Validasi bangunan melalui recipe yang ada di config
     */
    void bangun();

    void tambahPemain();
};

#endif