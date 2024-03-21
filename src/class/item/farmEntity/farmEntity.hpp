#ifndef __FARMENTITY_HPP__
#define __FARMENTITY_HPP__

#include "../item.hpp"

class FarmEntity : public Item {
    public:
        FarmEntity();
        FarmEntity(int, const string &, const string &, int, string , int);

        virtual ~FarmEntity();

        [[nodiscard]] string getType() const;
        [[nodiscard]] int getHarvestLimit() const;

        void print() const override;

    private:
        const string Type{};
        const int HarvestLimit;
};

#endif