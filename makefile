tile_test: tileTest.h tileTest.cpp
	g++ tileTest.cpp -o tile -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./tile

player_test: Player.h PlayerTest.cpp tileTest.h 
	g++ PlayerTest.cpp -o player -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./player

plant_inventory_test: PlayerPlantInv.h PlayerTest.cpp tile.h Plant.h BerryPlant.h
	g++ PlayerTest.cpp -o plant_inventory -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./plant_inventory

plant_image: Plant.h PlantTest.cpp tile.h
	g++ PlantTest.cpp -o plant_image -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./plant_image

rootPlant: RootPlantTest.cpp RootPlant.h Plant.h Plant.cpp tile.h 
	g++ RootPlantTest.cpp -o rootplant -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./rootplant

berryPlant: BerryPlantTest.cpp BerryPlant.h Plant.h Plant.cpp tile.h 
	g++ BerryPlantTest.cpp -o berry_plant_image -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./berry_plant_image

carrot: CarrotTest.cpp Carrot.h RootPlant.h Plant.h Plant.cpp tile.h 
	g++ CarrotTest.cpp -o carrot -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./carrot

potato: PotatoTest.cpp Potato.h RootPlant.h Plant.h Plant.cpp tile.h 
	g++ PotatoTest.cpp -o potato -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./potato

blueberry: BlueberryTest.cpp Blueberry.h BerryPlant.h Plant.h Plant.cpp tile.h 
	g++ BlueberryTest.cpp -o blueberry -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./blueberry

strawberry: StrawberryTest.cpp Strawberry.h BerryPlant.h Plant.h Plant.cpp tile.h 
	g++ StrawberryTest.cpp -o strawberry -I /include -L /lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./strawberry

plant_and_player_test: PlayerPlantInv.h PlayerTest.cpp tile.h Plant.h
	g++ PlayerTest.cpp -o plant_move -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./plant_move

text_test: TextboxTest.cpp TextBox.h tile.h Player.h
	g++ TextboxTest.cpp -o text -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./text

buymenu_test: BuyMenuTest.cpp Menu.h BuyMenu.h Player.h
	g++ BuyMenuTest.cpp -o buymenu -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./buymenu

menu_test: MenuTest.cpp menu.h tile.h Player.h
	g++ MenuTest.cpp -o menu -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./menu

# playerInteraction_test: PlayerInteractionTest.cpp PlayerInteraction.h tile.h Player.h Carrot.h
# 	clang++ PlayerInteractionTest.cpp -o playerInteraction -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
# 	./playerInteraction

inventory_test: InventoryTest.cpp Inventory.h Player.h tile.h BuyMenu.h
	g++ InventoryTest.cpp -o inventory -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./inventory

playerInteraction_test: PlayerInteractionTest.cpp PlayerInteraction.h tile.h Player.h Carrot.h
	clang++ PlayerInteractionTest.cpp -o playerInteraction -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./playerInteraction

day_test: DayTest.cpp Day.h tile.h Player.h
	clang++ DayTest.cpp -o day -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./day

sellmenu_test: SellMenuTest.cpp Menu.h BuyMenu.h Player.h SellMenu.h
	g++ SellMenuTest.cpp -o sellmenu -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./sellmenu

# has everything i.e. inventory, can plant plants, water plants, clock et.
everythingday_test: dayEverythingTest.cpp Day.h BuyMenu.h menu.h Player.h Strawberry.h Blueberry.h Carrot.h Potato.h RootPlant.h BerryPlant.h Plant.h tile.h InventoryItems.h
	clang++ dayEverythingTest.cpp -o everythingDay -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./everythingDay

inventoryImage_test: InventoryImageTest.cpp InventoryItems.h tile.h
	g++ InventoryImageTest.cpp -o inven -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./inven

menuTextTest: mainMenuTextTest.cpp Day.h BuyMenu.h menu.h Player.h Strawberry.h Blueberry.h Carrot.h Potato.h RootPlant.h BerryPlant.h Plant.h tile.h InventoryItems.h
	clang++ mainMenuTextTest.cpp -o menuText -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./menuText
