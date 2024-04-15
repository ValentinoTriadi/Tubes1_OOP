#include "people.hpp"

#include <utility>

using namespace std;

People::People() : Keuangan(50, 0), Weight(40), Type(0)
{
}

People::People(string nama, int weight, int Keuangan, int type, int n_penyimpanan, int m_penyimpanan) : Keuangan(Keuangan, type), Weight(weight), Type(type), storage(n_penyimpanan, m_penyimpanan), name(std::move(nama))
{
}

People::~People() = default;

void People::cetakPenyimpanan()
{
    cout << storage << endl;
}

void People::makan()
{
    try
    {
        if (storage.getFoodTotal() == 0)
        {
            throw StorageEmptyException();
        }

        cout << "Pilih makanan dari penyimpanan" << endl;
        cetakPenyimpanan();
        pair<int, int> slot;
        while (true)
        {
            try
            {
                slot = DataConverter::GetSingleRowCol("Slot : ");
                break;
            }
            catch (GameException &e)
            {
                cout << e.what() << endl;
            }
        }

        if (slot.first < 0 || slot.first >= storage.getCol() || slot.second >= storage.getRow() || slot.second < 0)
        {
            throw IndexOutOfBoundException();
        }

        Item *makanan = storage(slot.second, slot.first);
        if (makanan == nullptr)
        {
            throw FoodEmptyException();
        }

        Product *product = dynamic_cast<Product *>(makanan);
        if (product == nullptr || product->getAddedWeight() == 0)
        {
            throw InvalidFoodTypeException();
        }

        Weight += product->getAddedWeight();

        storage.deleteItem(slot.second, slot.first);
        cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
        cout << "Alhasil, berat badan kamu naik menjadi " << GetWeight() << endl;
    }
    catch (GameException &e)
    {
        cout << e.what() << endl;
    }
}

void People::membeli()
{
    try
    {
        cout << "Selamat datang di toko!!\n";
        cout << "Berikut merupakan hal yang dapat Anda Beli\n";

        Toko::displayToko();

        cout << "Uang Anda : " << Keuangan.GetMoney() << " gulden.\n";
        cout << "Slot penyimpanan tersedia: " << storage.getCellKosong() << " petak\n";

        InputManager::receiveIntInput("Barang ingin dibeli : ");
        int buy = InputManager::_inputData<int>;

        Item *itemtobuy = Toko::getItemAt(buy - 1);
        if (itemtobuy == nullptr)
        {
            throw ItemNotFoundException("");
        }
        int quantityMax = Toko::getListToko()[itemtobuy];

        try
        {
            InputManager::QuantityValidation(quantityMax, "Kuantitas yang ingin dibeli");
        }
        catch (InputException e)
        {
            cout << e.what() << endl;
            return;
        }

        int quantity = InputManager::_inputData<int>;

        if (storage.getCellKosong() < quantity)
        {
            throw FullException("penyimpanan");
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

            while (true)
            {
                try
                {
                    cetakPenyimpanan();
                    vector<pair<int, int>> petak = DataConverter::GetMultipleRowCol(quantity, "petak : ");
                    int temp = quantity;
                    for (int i = 0; i < temp; i++)
                    {
                        // Validasi petak index
                        if (petak[i].second < 0 || petak[i].second >= storage.getCol() || petak[i].first >= storage.getRow() || petak[i].first < 0)
                        {
                            throw IndexOutOfBoundException();
                        }

                        if (storage(petak[i].second, petak[i].first) != nullptr)
                        {
                            throw NotEmptyCellException(DataConverter::itos(petak[i].second, petak[i].first));
                        }

                        storage.setItem(petak[i].second, petak[i].first, itemtobuy);
                        quantity--;
                    }
                    cout << "Barang berhasil disimpan!" << endl;
                    break;
                }
                catch (GameException &e)
                {
                    cout << e.what() << endl;
                }
            }
        }
    }
    catch (GameException &e)
    {
        cout << e.what() << endl;
    }
}

void People::menjual()
{
    int total = 0;
    try
    {
        cout << "Berikut merupakan penyimpanan Anda" << endl;
        cetakPenyimpanan();

        try
        {
            InputManager::QuantityValidation(storage.getItems().size(), "Jumlah Barang yang ingin dibeli: ");
        }
        catch (InputException e)
        {
            std::cout << e.what() << endl;
            return;
        }
        int quantity = InputManager::_inputData<int>;

        if (quantity > (int)storage.getItems().size())
        {
            throw NotEnoughItemException();
        }

        cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
        for (int i = 0; i < quantity; i++)
        {
            try
            {
                pair<int, int> petakIndex = DataConverter::GetSingleRowCol("Petak ke-" + to_string(i + 1) + " : ");

                // Validasi petak index
                if (petakIndex.first < 0 || petakIndex.first >= storage.getCol() || petakIndex.second >= storage.getRow() || petakIndex.second < 0)
                {
                    throw IndexOutOfBoundException();
                }

                Item *itemtosell = storage(petakIndex.second, petakIndex.first);

                if (itemtosell == nullptr)
                {
                    throw StorageEmptyException();
                }

                storage.deleteItem(petakIndex.second, petakIndex.first);
                total += itemtosell->getHarga();
                Toko::addItems(itemtosell);
            }
            catch (GameException &e)
            {
                cout << e.what() << endl;
                i--;
            }
        }

        Keuangan.tambahUang(total);
        cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << total << " gulden!" << endl;
    }
    catch (GameException &e)
    {
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

StatusKeuangan People::getStatusKeuangan() const
{
    return Keuangan;
}

void People::HitungNonUang()
{
    int NonUang = Keuangan.GetNonUang();
    map<pair<string, int>, int> item = storage.getItems();
    for (std::pair<const std::pair<std::string, int>, int> &i : item)
    {
        NonUang += i.second;
    }
    Keuangan.SetNonUang(NonUang);
}

string People::getNameByCode(const string &code) const
{
    return name;
}

void People::KurangiUang(int uang) {
    Keuangan.kurangUang(uang);
}

void People::TambahUang(int uang) {
    Keuangan.tambahUang(uang);
}
