#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include "../farmEntity.hpp"

class Animal final : public FarmEntity {
    public:
        Animal();
        Animal(int, const string &, const string &, int, const string &, int, int);
        ~Animal() override;

        [[nodiscard]] int getWeight() const;
        
        void setWeight(int);

        void print() const override;

    private:
        int Weight;
        string code_;
};


#endif