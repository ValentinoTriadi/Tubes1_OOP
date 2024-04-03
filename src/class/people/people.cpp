#include "people.hpp"

#include <utility>


using namespace std;


People::People() : Keuangan(50,0), Weight(40), Type(0)
{
}

People::People(string nama, int weight, int Keuangan, int type, int n_penyimpanan, int m_penyimpanan) : Keuangan(Keuangan, 0), Weight(weight), Type(type), storage(n_penyimpanan, m_penyimpanan), name(std::move(nama))
{
}

People::~People() = default;

void People::cetakPenyimpanan()
{
    cout << storage << endl;
}

void People::makan()
{
    try {
        if (storage.getFoodTotal() == 0) {
            throw StorageEmptyException();
        }

        cout << "Pilih makanan dari penyimpanan" << endl;
        cetakPenyimpanan();
        pair<int, int> slot;
        while (true) {
            try {
                slot = DataConverter::GetSingleRowCol();
                break;
            } catch (GameException &e) {
                cout << e.what() << endl;
            }
        }

        if (slot.first < 0 || slot.first >= storage.getCol() || slot.second >= storage.getRow() || slot.second < 0) {
            throw IndexOutOfBoundException();
        }

        Item *makanan = storage(slot.second, slot.first);
        if (makanan == nullptr) {
            throw FoodEmptyException();
        }

        auto *product = dynamic_cast<Product *>(makanan);
        if (product == nullptr || product->getAddedWeight() == 0) {
            throw InvalidFoodTypeException();
        }

        Weight += product->getAddedWeight();

        storage.deleteItem(slot.second, slot.first);
        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
        cout << "Alhasil, berat badan kamu naik menjadi " << GetWeight() << endl;
    } catch (GameException& e){
        cout << e.what() << endl;
    }
}

Item People::membeli()
{
    try {
        cout << "Selamat datang di toko!!" << endl;
        cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;

        Toko::displayToko();

        cout << "Uang Anda : " << Keuangan.GetMoney() << endl;
        cout << "Slot penyimpanan tersedia:" << endl;

        InputManager::receiveIntInput("Barang ingin dibeli : ");
        int buy = InputManager::_inputData<int>;
        InputManager::receiveIntInput("Kuantitas : ");
        int quantity = InputManager::_inputData<int>;
        cout << endl;

        Item *itemtobuy = Toko::getItemAt(buy - 1);

        if (storage.getCellKosong() < quantity) {
            throw FullException("penyimpanan");
        } else if (Keuangan.GetMoney() < itemtobuy->getHarga() * quantity) {
            throw NotEnoughMoneyException();
        } else {
            cout << "Selamat Anda berhasil membeli " << quantity << " ";
            cout << itemtobuy->getNama();

            Keuangan.kurangUang(itemtobuy->getHarga() * quantity);
            cout << ". Uang Anda tersisa " << Keuangan.GetMoney() << " gulden" << endl;

            cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
            cetakPenyimpanan();

            cout << "Petak Slot: ";
            while (true) {
                vector<std::pair<int, int>> temp = DataConverter::GetMultipleRowCol();
                if (temp.size() == quantity) {
                    vector<std::pair<int, int>>::iterator it = temp.begin();
                    for (int i = 0; i < quantity; i++) {
                        storage.setItem(it->first, it->second, itemtobuy);
                        Toko::removeItems(itemtobuy);
                        it++;
                    }
                    break;
                } else {
                    cout << "Jumlah input slot tidak sesuai dengan quantity yang dibeli!\n";
                }
            }
            cout << "Barang berhasil disimpan!" << endl;
        }
        return *itemtobuy;
    } catch (GameException& e){
        cout << e.what() << endl;
    }
}

void People::menjual()
{
    try {
        cout << "Berikut merupakan penyimpanan Anda" << endl;
        cetakPenyimpanan();

        InputManager::receiveIntInput("Kuantitas barang yang ingin dijual : ");
        int quantity = InputManager::_inputData<int>;

        cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
        for (int i = 0; i < quantity; i++) {
            cout << "Petak ke-" << i + 1 << " : ";
            pair<int,int> petakIndex = DataConverter::GetSingleRowCol();
            Item *itemtosell = storage(petakIndex.second, petakIndex.first);
            storage.deleteItem(petakIndex.second, petakIndex.first);
            Toko::addItems(itemtosell);
        }
    } catch (GameException& e){
        cout << e.what() << endl;
    }
}

void People::setStorage(const Container &Setstorage)
{
    this->storage = Setstorage;
}

Container People::getStorage() const
{
    return storage;
}

StatusKeuangan People::getStatusKeuangan() const {
    return Keuangan;
}

void People::HitungNonUang() {
    int NonUang = Keuangan.GetNonUang();
    map<pair<string,int>, int> item = storage.getItems();
    for (auto & i : item) {
        NonUang += i.second;
    }
}
