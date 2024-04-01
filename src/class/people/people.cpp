#include "people.hpp"

int People::people_counter = 0;

People::People() : Keuangan(50), Weight(40), Type(0)
{
    id = people_counter;
    people_counter++;
}

People::People(const string &nama, int weight, int Keuangan, int type, int n_penyimpanan, int m_penyimpanan) : Keuangan(Keuangan), Weight(weight), Type(type), storage(n_penyimpanan, m_penyimpanan), name(nama)
{
    id = people_counter;
    people_counter++;
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
}

void People::membeli()
{
}

void People::menjual()
{
}

void People::setStorage(const Container &storage)
{
    this->storage = storage;
}


Container People::getStorage() const{
    return storage;
}
