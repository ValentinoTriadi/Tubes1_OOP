#ifndef __PLANT_HPP__
#define __PLANT_HPP__

#include "../farmEntity.hpp"

class Plant final : public FarmEntity {
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
        Plant(int, string, string, int, string, int, int);
        /**
         * Destructor
         * !```Don't call this function directly```!
        */
        ~Plant() override;


        //! GETTER, SETTER !//

        /**
         * Get Age of Plant
         * @return Age of Plant
        */
        [[nodiscard]] int getAge() const;
        /**
         * Set Age of Plant
         * @param Age Age of Plant
        */
        void setAge(int);


        //! Method !//

        /**
         * Print Plant to the screen
        */
        void print() const override;

    private:
        int Age;

};

#endif