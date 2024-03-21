//
// Created by Ojan on 3/21/2024.
//

#ifndef STATUSKEUANGAN_H
#define STATUSKEUANGAN_H

class StatusKeuangan {
private:
    int money = 0;
    int NonUang = 0;
    static int ktkp;

public:
    /*
     * Membuat class status keuangan baru dengan parameter uang
     * set 0 untuk nonUang
     */
    explicit StatusKeuangan(int uang);

    /*
     * Fungsi untuk menghitung pajak yang harus dibayar.
     * Walikota tidak dikenai pajak sedikitpun.
     * Jika nilai pajak berupa nilai desimal, bulatkan ke angka terdekat.
     * @return nilai pajak yang harus dibayar saat ini
     */
    [[nodiscard]] int hitungPajak() const;

    /*
     * Menambahkan uang ke dalam status keuangan
     */
    void tambahUang(int val) ;

    /*
     * Mengurangi uang dari status keuangan
     */
    void kurangUang(int val) ;

};

#endif //STATUSKEUANGAN_H