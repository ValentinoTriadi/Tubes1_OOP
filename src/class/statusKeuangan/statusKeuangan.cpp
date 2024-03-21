#include "statusKeuangan.hpp"

StatusKeuangan::StatusKeuangan(){
    
}

StatusKeuangan::StatusKeuangan(int money, int nonUang) : Money(money), NonUang(nonUang){}

StatusKeuangan::~StatusKeuangan(){

}

void StatusKeuangan::hitungPajak(){
    //TODO: Implement Hitung Pajak
}

void StatusKeuangan::tambahUang(){
    //TODO: Implement Tambah Uang
}
void StatusKeuangan::kurangUang(){
    //TODO: Implement Kurang Uang
}