#ifndef __PLANT_HPP__
#define __PLANT_HPP__

#include "../farmEntity.hpp"

class Plant final : public FarmEntity {
    public:
        Plant();
        Plant(int, string, string, int, string, int, int);
        ~Plant() override;

        [[nodiscard]] int getAge() const;
        void setAge(int);

        void print() const override;

    private:
        int Age;

};

#endif