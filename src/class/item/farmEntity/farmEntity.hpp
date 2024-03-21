#ifndef __FARMENTITY_HPP__
#define __FARMENTITY_HPP__

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
        */
        FarmEntity(const int, const string&, const string&, const int, const string&, const int);
        /**
         * Destructor
         *  !```Don't call this function directly```!
        */
        ~FarmEntity();



        //! GETTER !//

        /**
         * Get Type of FarmEntity
         * @return Type of FarmEntity
        */
        string getType() const;
        /**
         * Get Harvest Limit of FarmEntity
         * @return Harvest Limit of FarmEntity
        */
        int getHarvestLimit() const;


        //! Method !//

        /**
         * Print FarmEntity to the screen
        */
        virtual void print() const;

    private:
        const string Type;
        const int HarvestLimit;
};

#endif