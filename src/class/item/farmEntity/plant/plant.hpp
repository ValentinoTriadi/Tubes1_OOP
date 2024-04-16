#ifndef PLANT_HPP_
#define PLANT_HPP_

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
        Plant(int Id, const string& Code, const string& Name, int Price, const string& Types, int HarvestLimit, int Age);
        /**
         * Copy Constructor
        */
        Plant(const Plant&);
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

        void grow();


        //! Method !//

        /**
         * Print Plant to the screen
        */
        void print() const override;

    private:
        int Age;

};

#endif