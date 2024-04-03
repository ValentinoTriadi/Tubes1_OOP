#include "people.hpp"

#include <utility>

using namespace std;

People::People() : Keuangan(50, 0), Weight(40), Type(0)
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
    try
    {
        if (storage.getFoodTotal() == 0)
            throw StorageEmptyException();
    }
    catch (StorageEmptyException &e)
    {
        cout << e.what() << endl;
        return;
    }

    cout << "Pilih makanan dari penyimpanan" << endl;
    cetakPenyimpanan();
    pair<int, int> slot;
    Item *makanan;

    while (true)
    {
        try
        {
            slot = DataConverter::GetSingleRowCol();
            makanan = storage(slot.first, slot.second);
            if (makanan == nullptr)
            {
                throw FoodEmptyException();
            }
            break;
        }
        catch (GameException &e)
        {
            cout << e.what() << endl;
        }
        catch (InputException e)
        {
            cout << e.what() << endl;
        }
    }

    Product product = dynamic_cast<Product &>(*makanan);

    try
    {
        if (product.getType() != "PRODUCT_MATERIAL_PLANT")
            throw InvalidFoodTypeException();
    }
    catch (InvalidFoodTypeException &e)
    {
        cout << e.what() << endl;
    }

    Weight += product.getAddedWeight();
    storage.deleteItem(slot.first, slot.second);
    cout << "Dengan lahapnya, kamu memakanan hidangan itu" << endl;
    cout << "Alhasil, berat badan kamu naik menjadi" << GetWeight() << endl;
}

Item People::membeli()
{
    Item *itemtobuy;
    try
    {
        cout << "Selamat datang di toko!!" << endl;
        cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;

        Toko::displayToko();

        map<Item *, int> Items_in_Toko = Toko::getListItemToko();
        int amountOfItems = Items_in_Toko.size();

        cout << "Uang Anda : " << Keuangan.GetMoney() << endl;
        cout << "Slot penyimpanan tersedia:" << endl;

        int buy, quantity;

        // Validate Items Input, might Result as Exception
        InputManager::MembeliInputValidationPickingItems(amountOfItems);
        buy = InputManager::_inputData<int>;
        itemtobuy = Toko::getItemAt(buy - 1);

        // Validate Quantity Input, might Result as Exception
        int max_quantity = Items_in_Toko[itemtobuy];
        InputManager::QuantityValidation(max_quantity);
        quantity = InputManager::_inputData<int>;

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
            cout << ". Uang Anda tersisa " << Keuangan.GetMoney() << " gulden" << endl;

            cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
            cetakPenyimpanan();

            cout << "Petak Slot: ";
            pair<int, int> slot;
            for (int i = 0; i < quantity; i++)
            {
                slot = DataConverter::GetSingleRowCol();
                storage.setItem(slot.first, slot.second, itemtobuy);
                Toko::removeItems(itemtobuy);
            }
            cout << "Barang berhasil disimpan!" << endl;
        }
        return *itemtobuy;
    }
    catch (GameException &e)
    {
        cout << e.what() << endl;
    }
    catch (InputException e)
    {
        cout << e.what() << endl;
    }
    return *itemtobuy;
}

void People::menjual()
{
    try
    {
        cout << "Berikut merupakan penyimpanan Anda" << endl;
        cetakPenyimpanan();

        // Ambil Slot yang terisi
        int maxSlot = (storage.getCol() * storage.getRow()) - storage.getCellKosong();

        cout << "Kuantitas barang yang ingin dijual : ";

        // Cek Kuantitas yang di masukkan Valid atau tidak
        InputManager::QuantityValidation(maxSlot);
        int quantity = InputManager::_inputData<int>;

        pair<int, int> slot;
        cout << "Silahkan pilih petak yang ingin Anda jual!" << endl;
        for (int i = 0; i < quantity; i++)
        {
            cout << "Petak ke-" << i + 1 << " : ";
            slot = DataConverter::GetSingleRowCol();
            Item *itemtosell = storage(slot.first, slot.second);
            storage.deleteItem(slot.first, slot.second);
            Toko::addItems(itemtosell);
        }
    }
    catch (InputException e)
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
    for (auto &i : item)
    {
        NonUang += i.second;
    }
}

void People::pungutPajak(int jumlah)
{
    if (jumlah > GetKeuangan())
    {
        getStatusKeuangan().kurangUang(GetKeuangan());
    }
    else
    {
        getStatusKeuangan().kurangUang(jumlah);
    }
}

string People::getNameByCode(const string &code) const
{
    return name;
}