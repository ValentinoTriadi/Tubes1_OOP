#include "people.hpp"

People::People() : Keuangan(50), Weight(40)
{
}

People::People(int weight, int Keuangan, int type) : Keuangan(Keuangan), Weight(weight), Type(type), storage()
{
}
People::~People() = default;

void People::cetakPenyimpanan()
{
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

void People::SetContainer(const Container &container)
{
    storage = container;
}