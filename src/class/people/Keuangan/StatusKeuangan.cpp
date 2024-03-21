//
// Created by Ojan on 3/21/2024.
//

#include "StatusKeuangan.hpp"

StatusKeuangan::StatusKeuangan(const int uang) {
    money = uang;
    NonUang = 0;
}

int StatusKeuangan::hitungPajak() const {
    return (money + NonUang) - ktkp;
}

void StatusKeuangan::tambahUang(const int val) {
    money += val;
}

void StatusKeuangan::kurangUang(const int val) {
    money -= val;
}
