#ifndef __FARMENTITY_HPP__
#define __FARMENTITY_HPP__

#include "../item.hpp"

class FarmEntity : public Item {
    public:
        FarmEntity();
        FarmEntity(int, string, string, int, string, int);
        ~FarmEntity();

        string getType() const;
        int getHarvestLimit() const;

        virtual void print() const;

    private:
        const string Type;
        const int HarvestLimit;
};

#endif