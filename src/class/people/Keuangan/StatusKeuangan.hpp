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
     * @param money amount
     */
    explicit StatusKeuangan(int);

    /*
     * Fungsi untuk menghitung pajak yang harus dibayar.
     * Walikota tidak dikenai pajak sedikitpun.
     * Jika nilai pajak berupa nilai desimal, bulatkan ke angka terdekat.
     * @return nilai pajak yang harus dibayar saat ini
     */
    [[nodiscard]] int hitungPajak() const;

    /*
     *@param val amount of uang added
     */
    void tambahUang(int);

    /*
     * @param val amount of uang negated
     */
    void kurangUang(int);

    // Getter for money
    [[nodiscard]] int GetMoney() const{return money;}

};

#endif //STATUSKEUANGAN_H
