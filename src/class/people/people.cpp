#include "people.hpp"
#include "GameException.hpp"
#include "product.hpp"
#include "toko.hpp"

using namespace std;


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

    cout << "Slot: ";
    string slot;
    cin >> slot;
    cout << endl;

    int row = slot[0] - 'A';
    int col = stoi(slot.substr(1, 2)) - 1;

    Item* makanan = storage(row, col);
    if(makanan == nullptr){
        throw FoodEmptyException();
    }
    Product product = dynamic_cast<Product&>(*makanan);

    if(product.getType() == "PRODUCT_MATERIAL_PLANT"){
        throw InvalidFoodTypeException();
    }else{
        Weight += product.getAddedWeight();
        storage.deleteItem(row, col);
        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
        cout << "Alhasil, berat badan kamu naik menjadi" << GetWeight() << endl;
    }

}

Item People::membeli()
{
    cout << "Selamat datang di toko!!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;

    Toko::displayToko();

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

    Item* itemtobuy = Toko::getItemAt(buy-1);

    if(storage.getCellKosong() < quantity){
        throw StorageFullException();
    }else if(Keuangan.GetMoney() < itemtobuy->getHarga()*quantity){
        throw NotEnoughMoneyException();
    }else{
        cout << "Selamat Anda berhasil membeli " << quantity << " ";
        cout << itemtobuy->getNama();

        Keuangan.kurangUang(itemtobuy->getHarga()*quantity);
        cout << ". Uang Anda tersisa " << Keuangan.GetMoney() << " gulden" << endl;

        cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
        cetakPenyimpanan();

        cout << "Petak Slot: ";
        string slot;
        for (int i = 0; i < quantity; i++) {
            cin >> slot;
            cout << endl;
            int row = slot[0] - 'A';
            int col = stoi(slot.substr(1, 2)) - 1;
            storage.setItem(row, col, itemtobuy);
            Toko::removeItems(itemtobuy);
        }
        cout << "Barang berhasil disimpan!" << endl;
    }

}

void People::menjual()
{
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    cetakPenyimpanan();

    cout << "Kuantitas barang yang ingin dijual : ";
    int quantity;
    cin >> quantity;
    cout << endl;

    cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
    for(int i=0; i<quantity; i++){
        cout << "Petak ke-" << i+1 << " : ";
        string slot;
        cin >> slot;
        cout << endl;
        int row = slot[0] - 'A';
        int col = stoi(slot.substr(1, 2)) - 1;
        Item* itemtosell = storage(row, col);
        storage.deleteItem(row, col);
        Toko::addItems(itemtosell);
    }
}

void People::setStorage(const Container &Setstorage)
{
    this->storage = Setstorage;
}


Container People::getStorage() const{
    return storage;
}
