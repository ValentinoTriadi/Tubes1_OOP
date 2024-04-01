#include "stockman.hpp"

Stockman::Stockman(const int weight, const int Keuangan, const int Type , const int n_penyimpanan, const int m_penyimpanan, const int n_peternakan, const int m_peternakan) : People(weight, Keuangan, Type, n_penyimpanan, m_penyimpanan){
    Peternakan = Container(n_peternakan, m_peternakan);
};

Stockman::~Stockman() = default;

void Stockman::cetakPeternakan(){
    cout << Peternakan;
}

void Stockman::ternak(){
    // TODO: Check di penyimpanan ada hewan ga
    // TODO: throw eror kalo gada
    // TODO: tambah hewan di peternakan + pilih tempatnya
    // TODO: throw eror kalo udh diisi
    // SUCCESS
    // TODO: isi peternakan, ilangin storage
}

void Stockman::memberiPangan(){
    // TODO: Check di peternakan ada hewan ga
    // TODO: throw eror kalo gada atau salah pilih slot
    // TODO: check inventory ada makanan ga
    // TODO: throw eror kalo gaada, atau kalo pilih yg kosong atau pilih yg bukan tipenya
    // SUCCESS
    // TODO: tambahin berat
}

void Stockman::panen(){
    // TODO: Check yang siap di panen + tampilin
    // TODO: validasi input ( nomor hewan + jumlah + petak yg mana)
    // TODO: validasi inventory
    // SUCCESS
    // TODO: ilangin field + masukin inventory
}

void Stockman::pungutPajak(){
    // 
}
