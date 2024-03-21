#include "roundRobin.hpp"
#include <iostream>

int main (){
    roundRobin<int> rr;
    rr.add(1);
    rr.add(2);
    rr.add(3);
    rr.add(4);
    rr.add(5);
    rr.add(6);

    std::cout << rr;
    rr.next();
    std::cout << rr;
    rr.add(7);
    std::cout << rr;
    rr.deleteFirst();
    std::cout << rr;
    rr.deleteFirst();
    std::cout << rr;
    

    return 0;
}