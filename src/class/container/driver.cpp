#include "container.hpp"

int main(){
    Container container(3,3);

    Plant* plant = new Plant(1, "P1A", "Padi", 1000, "Padi", 1, 1);
    container.setItem(0, 0, plant);

    Animal* animal = new Animal(2, "A1A", "Ayam", 1000, "Ayam", 1, 1);
    container.setItem(0, 1, animal);

    Animal* animal2 = new Animal(3, "A1A", "Ayam", 1000, "Ayam", 1, 1);
    container.setItem(1, 0, animal2);

    cout << container << endl;

    map<pair<string, int>, int> itemMap = container.getItems();

    for (auto it = itemMap.begin(); it != itemMap.end(); it++){
        cout << it->first.first << " " << it->first.second << " " << it->second << endl;
    }

    return 0;
    
}