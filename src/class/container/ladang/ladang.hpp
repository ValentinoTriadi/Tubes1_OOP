#include "../container.hpp"
#include "../../item/farmEntity/farmEntity.hpp"
#include "../../item/farmEntity/plant/plant.hpp"
#include <set>
#include <map>


class Ladang : public Container {
    public:
            Ladang();
            Ladang(int row, int col);
            ~Ladang();
            void showPlant();

            std::map<std::string, int> getHarvest();

            friend std::ostream& operator<<(std::ostream& os, const Ladang& ladang);

        private:
            std::ostream& printRow(std::ostream& os, int i) const;
            bool isReadyToHarvest(Item* item) const;
};