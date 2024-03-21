#include "StatusKeuangan.hpp"

StatusKeuangan::StatusKeuangan(int uang) : money(uang){
}

int StatusKeuangan::hitungPajak() const{
    return NonUang;
}

void StatusKeuangan::tambahUang(int val){
    money += val;
}

void StatusKeuangan::kurangUang(int val){
    if(money < val){
        //TODO: implement miskin exception
    }
    money -= val;
}