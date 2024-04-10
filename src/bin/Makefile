CXX = g++
CXXFLAGS = -std=c++17 -Wall


build: main container ladang peternakan gameData item building product farmEntity animal plant gameManager inputManager stateManager people farmer stockman mayor statusKeuangan toko dataConverter matrix
	$(CXX) $(CXXFLAGS) -o ../main main.o container.o ladang.o peternakan.o gameData.o item.o building.o product.o farmEntity.o animal.o plant.o gameManager.o inputManager.o stateManager.o people.o farmer.o stockman.o mayor.o statusKeuangan.o toko.o dataConverter.o matrix.o

main: ../main.cpp
	$(CXX) $(CXXFLAGS) -c $?

container: ../class/container/container.cpp
	$(CXX) $(CXXFLAGS) -c $?

ladang: ../class/container/ladang/ladang.cpp
	$(CXX) $(CXXFLAGS) -c $?

peternakan: ../class/container/peternakan/peternakan.cpp
	$(CXX) $(CXXFLAGS) -c $?

gameData: ../class/gameData/gameData.cpp
	$(CXX) $(CXXFLAGS) -c $?

item: ../class/item/item.cpp
	$(CXX) $(CXXFLAGS) -c $?

building: ../class/item/building/building.cpp
	$(CXX) $(CXXFLAGS) -c $?

product: ../class/item/product/product.cpp
	$(CXX) $(CXXFLAGS) -c $?

farmEntity: ../class/item/farmEntity/farmEntity.cpp
	$(CXX) $(CXXFLAGS) -c $?

animal: ../class/item/farmEntity/animal/animal.cpp
	$(CXX) $(CXXFLAGS) -c $?

plant: ../class/item/farmEntity/plant/plant.cpp
	$(CXX) $(CXXFLAGS) -c $?

gameManager: ../class/Manager/GameManager/GameManager.cpp
	$(CXX) $(CXXFLAGS) -c $?

inputManager: ../class/Manager/InputManager/InputManager.cpp
	$(CXX) $(CXXFLAGS) -c $?

stateManager: ../class/Manager/StateManager/StateManager.cpp
	$(CXX) $(CXXFLAGS) -c $?

people: ../class/people/people.cpp
	$(CXX) $(CXXFLAGS) -c $?

farmer: ../class/people/farmer/farmer.cpp
	$(CXX) $(CXXFLAGS) -c $?

stockman: ../class/people/stockman/stockman.cpp
	$(CXX) $(CXXFLAGS) -c $?

mayor: ../class/people/mayor/mayor.cpp
	$(CXX) $(CXXFLAGS) -c $?

statusKeuangan: ../class/people/Keuangan/StatusKeuangan.cpp
	$(CXX) $(CXXFLAGS) -c $?

toko: ../class/toko/toko.cpp
	$(CXX) $(CXXFLAGS) -c $?

dataConverter: ../class/utils/DataConverter/DataConverter.cpp
	$(CXX) $(CXXFLAGS) -c $?

matrix: ../class/utils/matrix/matrix.cpp
	$(CXX) $(CXXFLAGS) -c $?

clean:
	rm *.o
	rm main.exe


