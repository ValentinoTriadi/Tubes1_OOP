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
    if (storage.getFoodTotal() == 0) {
        cout << "Storage is empty." << endl;
        return;
    }

    cout << "Pilih makanan dari penyimpanan" << endl;
    cetakPenyimpanan();
    pair<int, int> slot = DataConverter::GetSingleRowCol();

    if (slot.first < 0 || slot.first >= storage.getCol() || slot.second >= storage.getRow() || slot.second < 0) {
        cout << "Index out of bounds." << endl;
        return;
    }

    Item *makanan = storage(slot.second, slot.first);
    if (makanan == nullptr) {
        cout << "Food is empty." << endl;
        return;
    }

    auto* product = dynamic_cast<Product*>(makanan);
    if (product == nullptr || product->getAddedWeight() == 0) {
        cout << "Invalid food type." << endl;
        return;
    }

    Weight += product->getAddedWeight();
    storage.deleteItem(slot.second, slot.first);
    cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
    cout << "Alhasil, berat badan kamu naik menjadi " << GetWeight() << endl;
}

void People::membeli()
{
    try {
        cout << "Selamat datang di toko!!\n";
        cout << "Berikut merupakan hal yang dapat Anda Beli\n";

        Toko::displayToko();

        cout << "Uang Anda : " << Keuangan.GetMoney() << " gulden.\n";
        cout << "Slot penyimpanan tersedia: " << storage.getCellKosong() << " petak\n";

        cout << "Barang ingin dibeli : ";

        InputManager::receiveIntInput();
        int buy = InputManager::_inputData<int>;

        Item *itemtobuy = Toko::getItemAt(buy - 1);
        if (itemtobuy == nullptr)
        {
            throw ItemNotFoundException("");
        }

        cout << "Kuantitas : ";
        InputManager::receiveIntInput();
        int quantity = InputManager::_inputData<int>;

        if (storage.getCellKosong() < quantity)
        {
            throw StorageFullException();
        }
        else if (Keuangan.GetMoney() < itemtobuy->getHarga() * quantity)
        {
            throw NotEnoughMoneyException();
        }
        else
        {
            cout << "Selamat Anda berhasil membeli " << quantity << " ";
            cout << itemtobuy->getNama();

            Keuangan.kurangUang(itemtobuy->getHarga() * quantity);
            cout << ". Uang Anda tersisa " << Keuangan.GetMoney() << " gulden\n";

            cout << "Pilih slot untuk menyimpan barang yang Anda beli!\n";


            while (true){
                try {
                    cetakPenyimpanan();
                    vector<pair<int, int>> petak = DataConverter::GetMultipleRowCol(quantity);
                    int temp = quantity;
                    for (int i = 0; i < temp; i++)
                    {
                        // Validasi petak index
                        if (petak[i].second < 0 || petak[i].second >= storage.getCol() || petak[i].first >= storage.getRow() || petak[i].first < 0) {
                            throw IndexOutOfBoundException();
                        }

                        if (storage(petak[i].second, petak[i].first) != nullptr)
                        {
                            throw NotEmptyCellException(DataConverter::itos(petak[i].second , petak[i].first));
                        }

                        storage.setItem(petak[i].second, petak[i].first, itemtobuy);
                        quantity--;
                    }
                    cout << "Barang berhasil disimpan!" << endl;
                    break;
                } catch (GameException &e) {
                    cout << e.what() << endl;
                }
            }
        }
    } catch (GameException &e) {
        cout << e.what() << endl;
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
    for (int i = 0; i < quantity; i++)
    {
        cout << "Petak ke-" << i + 1 << " : ";
        string slot;
        cin >> slot;
        cout << endl;
        int row = slot[0] - 'A';
        int col = stoi(slot.substr(1, 2)) - 1;
        Item *itemtosell = storage(row, col);
        storage.deleteItem(row, col);
        Toko::addItems(itemtosell);
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
