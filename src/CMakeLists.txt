cmake_minimum_required(VERSION 3.27)
project(Tubes1_OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tubes1_OOP main.cpp
        class/gameData/gameData.cpp
        class/gameData/gameData.hpp
        class/item/item.cpp
        class/item/item.hpp
        class/item/building/building.cpp
        class/item/building/building.hpp
        class/item/farmEntity/farmEntity.cpp
        class/item/farmEntity/farmEntity.hpp
        class/item/farmEntity/animal/animal.cpp
        class/item/farmEntity/animal/animal.hpp
        class/item/farmEntity/plant/plant.cpp
        class/item/farmEntity/plant/plant.hpp
        class/item/product/product.cpp
        class/item/product/product.hpp
        class/Manager/GameManager/GameManager.hpp
        class/people/people.hpp
        class/people/farmer/farmer.cpp
        class/people/farmer/farmer.cpp
        class/people/farmer/farmer.hpp
        class/people/Keuangan/StatusKeuangan.hpp
        class/people/mayor/mayor.cpp
        class/people/mayor/mayor.hpp
        class/people/stockman/stockman.cpp
        class/people/stockman/stockman.hpp
        class/utils/matrix/matrix.cpp
        class/utils/matrix/matrix.hpp
        class/Manager/GameManager/GameManager.cpp
        class/people/Keuangan/StatusKeuangan.cpp
        class/container/container.cpp
        class/container/container.hpp
        class/people/people.cpp
        class/Manager/InputManager/InputManager.cpp
        class/Manager/StateManager/StateManager.cpp
)
