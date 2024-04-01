#include "farmer.hpp"

#include "../../item/farmEntity/plant/plant.hpp"

Farmer::Farmer() = default;

/**
 *  Mencetak Ladang dari petani
 */
void Farmer::cetakLadang() const {
    cout << ladang;
}

/**
 *  Menanam tanaman
 */
void Farmer::tanam() {
    // Pilih tanaman dari penyimpanan
    cout << "Pilih tanaman dari penyimpanan" << endl;
    cetakPenyimpanan();

    // Ambil input dari user simpan dalam variable slot
    // Input berformat char int (B10)
    cout << "Slot: ";
    string slot;
    cin >> slot;
    cout << endl;

    // Ubah input menjadi column dan row
    int row1 = slot[0] - 'A';
    int column1 = stoi(slot.substr(1, 2)) - 1;

    // Validasi
    // TODO: Exception handling

    // Akses item
    Item* tanaman = storage(row1,column1);

    cout << "Kamu memilih " << tanaman->getNama() << endl;

    // Ambil input petak yang akan ditanami
    cout << "Pilih petak tanah yang akan ditanami" << endl;
    cetakLadang();

    // Ambil input dari user simpan dalam variable slot
    // Input berformat char int (B10)
    cout << "Petak tanah: ";
    string petak;
    cin >> petak;
    cout << endl << endl;

    // Ubah input menjadi column dan row
    int row2 = petak[0] - 'A';
    int column2 = stoi(petak.substr(1, 2)) - 1;

    // Validasi
    // TODO : Exception handling

    ladang.setItem(row2,column2, tanaman);

    cout << "Cangkul, cangkul, cangkul yang dalam~!" << endl;
    cout << tanaman->getNama() << " berhasil ditanam!" << endl;

    storage.deleteItem(row1,column1);
}

void Farmer::panen() {
    cetakLadang();

    // TODO : Cetak barang yang bisa diambil

    cout << "Pilih tanaman tanah yang akan dipanen" << endl;

    // TODO : Cetak barang yang bisa diambil dan jumlahnya

    cout << "Nomor tanamn yang ingin dipanen: ";
    int nomor;
    cin >> nomor;
    cout << endl << endl;

    // TODO : Validasi input

    cout<< "Berapa petak yang ingin dipanen: ";
    int jumlah;
    cin >> jumlah;
    cout << endl << endl;

    // TODO : Validasi input

    cout << "Pilih petak yang ingin dipanen: " << endl;

    // TODO : Cetak petak yang bisa dipanen

    vector<Item*>tanaman;
    vector<pair<int,int>> petak;
    for (int i = 0; i < jumlah; i++) {
        cout << "Petak ke-" << i+1 << ": ";
        string slot;
        cin >> slot;
        cout << endl;

        // TODO : Validasi input

        int row = slot[0] - 'A';
        int column = stoi(slot.substr(1, 2)) - 1;

        tanaman.emplace_back(ladang(row,column));
        petak.emplace_back(row,column);
    }

    cout << jumlah << " petak tanaman " << tanaman[nomor-1]->getNama() << " pada petak ";
    for (int i = 0; i < jumlah; i++) {
        cout << petak[i].first << petak[i].second;
        if (i != jumlah-1) {
            cout << ", ";
        }
        ladang.deleteItem(petak[i].first,petak[i].second);
    }
    cout<<" telah dipanen!" << endl;
}

void Farmer::pungutPajak() {
    // Hitung nilai pajak non uang
    int pajak = 0;

}


Farmer::Farmer(const string& name, int weight, int Keuangan , int n_penyimpanan, int m_penyimpanan, int n_ladang, int m_ladang): People(name,weight, Keuangan, 2, n_penyimpanan, m_penyimpanan) {
    this->ladang = Ladang(n_ladang, m_ladang);
}

void Farmer::setLadang(const Ladang &ladang) {
    this->ladang = ladang;
}

Ladang Farmer::getLadang() const {
    return ladang;
}

Farmer::~Farmer() = default;