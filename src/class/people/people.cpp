#include "people.hpp"
#include "GameException.hpp"
#include "product.hpp"


People::People() : Keuangan(50), Weight(40), Type(0)
{

}

People::People(int weight, int Keuangan, int type, int n_penyimpanan, int m_penyimpanan) : Keuangan(Keuangan), Weight(weight), Type(type), storage(n_penyimpanan, m_penyimpanan)
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

    cout << "Slot: ";
    string slot;
    cin >> slot;
    cout << endl;

    int row = slot[0] - 'A';
    int col = slot[1] - '0';

    Item* makanan = storage(row, col);
    if (makanan == nullptr) {
        throw FoodEmptyException();
    // TODO : else if (makanan->getType() != FOOD)
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


    if(storage.getCellKosong() < quantity){
        throw StorageFullException();
    // TODO : else if Keuangan.GetMoney < ...getPrice() * quantity)
    }else{
        cout << "Selamat Anda berhasil membeli " << quantity << " ";
        // TODO : cout << nama barang yang dibeli (pake .getName)

        // TODO : Keuangan.kurangUang(quantity * ...getPrice())
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


}

void People::menjual()
{
    // TODO : nunggu yg class Toko jadi dulu
}

