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

plant_and_player_test: Player_plantInv.h Player_driver.cpp tile.h Plant.h
	g++ Player_driver.cpp -o plant_move -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./plant_move

text_test: Textbox_driver.cpp Text_box.h tile.h Player.h
	g++ Textbox_driver.cpp -o text -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./text

buymenu_test: BuyMenu.cpp BuyMenu.h Player.h tile.h
	g++ BuyMenu.cpp -o menu -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./menu