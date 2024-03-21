#ifndef __PLANT_HPP__
#define __PLANT_HPP__

#include "../farmEntity.hpp"

class Plant : public FarmEntity {
    public:

        //! CTOR, DTOR !//

        /**
         * Default Constructor
         * Usage: ```Plant plant;```
        */
        Plant();
        /**
         * Constructor
         * @param Id ID of Plant
         * @param Code Code of Plant
         * @param Name Name of Plant
         * @param Price Price of Plant
         * @param Type Type of Plant
         * @param HarvestLimit Harvest Limit of Plant (Minimum Age or Weight to Harvest)
         * @param Age Age of Plant
        */
        Plant(const int, const string&, const string&, const int, const string&, const int, const int);
        /**
         * Destructor
         * !```Don't call this function directly```!
        */
        ~Plant();


        //! GETTER, SETTER !//

        /**
         * Get Age of Plant
         * @return Age of Plant
        */
        int getAge() const;
        /**
         * Set Age of Plant
         * @param Age Age of Plant
        */
        void setAge(int);


        //! Method !//

        /**
         * Print Plant to the screen
        */
        void print() const;

    private:
        int Age;

};

#endif