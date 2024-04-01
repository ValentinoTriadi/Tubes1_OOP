#include "people.hpp"
#include "GameException.hpp"
#include "product.hpp"


People::People() : Keuangan(50), Weight(40), Type(0)
{

}

People::People(int weight, int Keuangan, int type, int n_penyimpanan, int m_penyimpanan) : Keuangan(Keuangan), Weight(weight), Type(type)
{
    storage = Container(n_penyimpanan, m_penyimpanan);
}
People::~People() = default;

void People::cetakPenyimpanan()
{
    cout << storage << endl;
}

void People::makan()
{
    // Perintah ini digunakan memakan makanan sesuai dengan ketentuan yang sudah dijelaskan di atas. Pertama, tampilkan terlebih dahulu penyimpanan sesuai dengan perintah CETAK_PENYIMPANAN. Setelah itu, program akan menerima input berupa slot dari penyimpanan yang akan digunakan sebagai makanan. Jika slot yang dipilih merupakanan makanan yang valid, slot tersebut	akan menjadi kosong. Ketika pemain memakan makanan, berat badan bertambah sesuai jenis makanan yang didefinisikan di berkas konfigurasi.Perintah tidak bisa dijalankan jika penyimpanan kosong.
    cout << "Pilih makanan dari penyimpanan" << endl;
    cetakPenyimpanan();

    cout << "Slot: ";
    string slot;
    cin >> slot;
    cout << endl;

    int row = slot[0] - 'A';
    int col = slot[1] - '0';

    Item* makanan = storage(row, col);
    if (makanan == nullptr) {
        throw FoodEmptyException();
    // } else if (makanan->GetType() == "MATERIAL_PLANT") {     // INI MASI BINGUNG
    //     throw InvalidFoodTypeException();
    }else{
        Product* product = dynamic_cast<Product*>(makanan);
        Weight += product->getAddedWeight();
        storage.deleteItem(row, col);
        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
        cout << "Alhasil, berat badan kamu naik menjadi" << GetWeight() << endl;
    }

}

void People::membeli()
{
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;

    // TODO : nampilin barang yang bisa dibeli dr toko

    cout << "Uang Anda : " << Keuangan.GetMoney() << endl;
    cout << "Slot penyimpanan tersedia:" << endl;

    cout << "Barang ingin dibeli : ";
    int buy;
    cin >> buy;
    cout << endl;
    cout << "Kuantitas : ";
    int quantity;
    cin >> quantity;
    cout << endl;

    // TODO : Validasi
    // - klo storage full, kasih exception
    // - klo uang ga cukup, kasih exception  --> if kuranguang(price)
    
    //ELSE
    cout << "Selamat Anda berhasil membeli " << quantity << " ";
    // cout << nama barang yang dibeli (pake .getName)
    cout << ". Uang Anda tersisa " << Keuangan.GetMoney() << " gulden" << endl;

    cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
    cetakPenyimpanan();

    cout << "Petak Slot: ";
    string slot;
    for (int i = 0; i < quantity; i++) {
        cin >> slot;
        cout << endl;
        int row = slot[0] - 'A';
        int col = slot[1] - '0';
        // TODO : storage.setItem(row, col, ITEM YANG DIBELI);
    }
    cout << "Barang berhasil disimpan!" << endl;

}

void People::menjual()
{
}

void People::SetContainer(const Container &container)
{
    storage = container;
}
