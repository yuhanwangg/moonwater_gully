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

berryPlant: BerryPlant.cpp BerryPlant.h Plant.h Plant.cpp tile.h 
	g++ BerryPlant.cpp -o berry_plant_image -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./berry_plant_image

carrot: Carrot.cpp Carrot.h RootPlant.h Plant.h Plant.cpp tile.h 
	g++ Carrot.cpp -o carrot -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./carrot

potato: Potato.cpp Potato.h RootPlant.h Plant.h Plant.cpp tile.h 
	g++ Potato.cpp -o potato -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./potato

blueberry: Blueberry.cpp Blueberry.h BerryPlant.h Plant.h Plant.cpp tile.h 
	g++ Blueberry.cpp -o blueberry -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./blueberry

strawberry: Strawberry.cpp Strawberry.h BerryPlant.h Plant.h Plant.cpp tile.h 
	g++ Strawberry.cpp -o strawberry -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./strawberry

plant_and_player_test: Player_plantInv.h Player_driver.cpp tile.h Plant.h
	g++ Player_driver.cpp -o plant_move -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./plant_move

text_test: Textbox_driver.cpp Text_box.h tile.h Player.h
	g++ Textbox_driver.cpp -o text -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./text

buymenu_test: BuyMenu.cpp Menu.h BuyMenu.h Player.h
	g++ BuyMenu.cpp -o buymenu -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./buymenu

menu_test: Menu.cpp menu.h tile.h Player.h
	g++ Menu.cpp -o menu -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./menu

playerInteraction_test: PlayerInteraction.cpp PlayerInteraction.h tile.h Player.h Carrot.h
	clang++ PlayerInteraction.cpp -o playerInteraction -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./playerInteraction

inventory_test: Inventory.cpp Inventory.h Player.h tile.h BuyMenu.h
	g++ Inventory.cpp -o inventory -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./inventory

playerInteraction_test: PlayerInteraction.cpp PlayerInteraction.h tile.h Player.h Carrot.h
	clang++ PlayerInteraction.cpp -o playerInteraction -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./playerInteraction
