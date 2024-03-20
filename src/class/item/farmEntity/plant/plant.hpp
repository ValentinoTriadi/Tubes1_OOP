#ifndef __PLANT_HPP__
#define __PLANT_HPP__

#include "../farmEntity.hpp"

class Plant : public FarmEntity {
    public:
        Plant();
        Plant(int, string, string, int, string, int, int);
        ~Plant();

        int getAge() const;
        void setAge(int);

        void print() const;

    private:
        int Age;

};

#endif