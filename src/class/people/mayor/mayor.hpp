
#ifndef MAYOR_HPP_
#define MAYOR_HPP_
#include "../people.hpp"

class Mayor : People {
private:
    // Penyimpanan Storage;
public:
    /*
     * Membuat objek mayor dengan storage kosong
     * dan keuangan 0
     */
    Mayor();

    /*
     * Membangun bangunan baru menggunakan barang-barang yang ada di storage
     * Jika barang tidak cukup, maka bangunan tidak akan terbangun
     * Validasi bangunan melalui recipe yang ada di config
     */
    void bangun();
};

#endif