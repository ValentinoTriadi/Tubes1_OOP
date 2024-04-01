#include "people.hpp"

People::People() : Keuangan(50), Weight(40), Type(0)
{
}

People::People(const string &nama, int weight, int Keuangan, int type, int n_penyimpanan, int m_penyimpanan) : Keuangan(Keuangan), Weight(weight), Type(type), storage(n_penyimpanan, m_penyimpanan), name(nama)
{
}

People::~People() = default;

void People::cetakPenyimpanan()
{
    cout << storage << endl;
}

void People::makan()
{
    cout << "Pilih makanan dari penyimpanan" << endl;
    cetakPenyimpanan();

    // Nunggu input array davis
}

void People::membeli()
{
    cout << "Welcome traveller!!" << endl;
    cout << "Silahkan melihat barang-barang ku" << endl;

    // Nunggu shop class
    // Cetak barang-barang yang ada di shop

    cout << "Uang anda : " << Keuangan.GetMoney() << endl;
    cout << "Slot penyimpanan tersedia : " << storage.getCellKosong() << endl;

    cout << "Barang yang ingin dibeli : " << endl;

    // Nunggu input

    // TODO: Ganti menjadi shop class, hitung jumlah harga
    Item * item = new Item();
    int totalHarga = 0;

    // TODO: Exception jumlah storage dan uang

    Keuangan.kurangUang(totalHarga);
    cout << "Terima kasih telah membeli  " << 2 << " " << item->getNama() << "." << "Uang anda tersisa " << Keuangan.GetMoney() << endl;
}

void People::menjual()
{
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    cetakPenyimpanan();

    cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
    // Input matrix

    // TODO: Exception petak valid

    int jumlahHarga = 0;
    cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << jumlahHarga <<" gulden!" << endl;
}

void People::setStorage(const Container &storage)
{
    this->storage = storage;
}


Container People::getStorage() const{
    return storage;
}
