#ifndef FARMENTITY_HPP_
#define FARMENTITY_HPP_

#include "../item.hpp"

class FarmEntity : public Item {
    public:
        //! CTOR, DTOR !//

        /**
         * Default Constructor
         * Usage: ```FarmEntity farmEntity;```
        */
        FarmEntity();
        /**
         * Constructor
         * @param Id ID of FarmEntity
         * @param Code Code of FarmEntity
         * @param Name Name of FarmEntity
         * @param Price Price of FarmEntity
         * @param Type Type of FarmEntity
         * @param HarvestLimit Harvest Limit of FarmEntity (Minimum Age or Weight to Harvest)
         * @param ItemType Type of Item (0: Product, 1: Animal, 2: Plant)
        */
        FarmEntity(int, const string &, const string &, int, string , int, int);
        /**
         * Destructor
         *  !```Don't call this function directly```!
        */
        ~FarmEntity() override;



        //! GETTER !//

        /**
         * Get Type of FarmEntity
         * @return Type of FarmEntity
        */
        [[nodiscard]] string getType() const;
        /**
         * Get Harvest Limit of FarmEntity
         * @return Harvest Limit of FarmEntity
        */
        [[nodiscard]] int getHarvestLimit() const;


        //! Method !//

        /**
         * Print FarmEntity to the screen
        */
        void print() const override;

    private:
        const string Type{};
        const int HarvestLimit;
};

#endif