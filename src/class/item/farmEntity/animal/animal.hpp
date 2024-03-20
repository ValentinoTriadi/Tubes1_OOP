#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include "../farmEntity.hpp"

class Animal : public FarmEntity {
    public:
        Animal();
        Animal(int, string, string, int, string, int, int);
        ~Animal();

        int getWeight() const;
        
        void setWeight(int);

        void print() const;

    private:
        int Weight;

};


#endif