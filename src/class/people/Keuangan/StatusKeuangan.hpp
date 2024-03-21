//
// Created by Ojan on 3/21/2024.
//

#ifndef STATUSKEUANGAN_H
#define STATUSKEUANGAN_H

class statusKeuangan {
private:
    int money = 0;
    int NonUang = 0;

public:
    /*
     * Membuat class status keuangan baru dengan parameter uang
     * set 0 untuk nonUang
     */
    explicit statusKeuangan(int uang);

    /*
     * Fungsi untuk menghitung pajak yang harus dibayar.
     * Walikota tidak dikenai pajak sedikitpun.
     * Jika nilai pajak berupa nilai desimal, bulatkan ke angka terdekat.
     * @return nilai pajak yang harus dibayar saat ini
     */
    int hitungPajak();

    /*
     *
     */
    void tambahUang(int val);

    /*
     *
     */
    void kurangUang(int val);

};

#endif //STATUSKEUANGAN_H
