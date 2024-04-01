#include "people.hpp"

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

}

void People::membeli()
{
}

void People::menjual()
{
}

