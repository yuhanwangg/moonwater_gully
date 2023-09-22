tile_test: tile_test.h tile_driver.cpp
	g++ tile_driver.cpp -o tile -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./tile

player_test: Player.h Player_driver.cpp tile_test.h 
	g++ Player_driver.cpp -o player -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./player

plant_inventory_test: Player_plantInv.h Player_driver.cpp tile.h Plant.h BerryPlant.h
	g++ Player_driver.cpp -o plant_inventory -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./plant_inventory

plant_image: Plant.h Plant.cpp tile.h
	g++ Plant.cpp -o plant_image -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./plant_image

rootPlant: RootPlant.cpp RootPlant.h Plant.h Plant.cpp tile.h 
	g++ RootPlant.cpp -o rootplant -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./rootplant

berryplant2: BerryPlant2.cpp BerryPlant.h Plant.h Plant.cpp tile.h 
	g++ BerryPlant2.cpp -o berry_plant_image -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./berry_plant_image

carrot: Carrot.cpp Carrot.h RootPlant.cpp RootPlant.h Plant.h Plant.cpp tile.h 
	g++ Carrot.cpp -o carrot -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./carrot