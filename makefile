tileTest: tileTest.h tileTest.cpp
	g++ tileTest.cpp -o tile -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./tile

playerTest: Player.h PlayerTest.cpp tileTest.h 
	g++ PlayerTest.cpp -o player -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./player

plantInventoryTest: PlayerPlantInv.h PlayerTest.cpp tile.h Plant.h BerryPlant.h
	g++ PlayerTest.cpp -o plantInventory -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./plantInventory

plantImage: Plant.h PlantTest.cpp tile.h
	g++ PlantTest.cpp -o plantImage -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./plantImage

rootPlant: RootPlantTest.cpp RootPlant.h Plant.h tile.h 
	g++ RootPlantTest.cpp -o rootplant -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./rootplant

berryPlant: BerryPlantTest.cpp BerryPlant.h Plant.h tile.h 
	g++ BerryPlantTest.cpp -o berryPlantImage -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./berryPlantImage

carrot: CarrotTest.cpp Carrot.h RootPlant.h Plant.h tile.h 
	g++ CarrotTest.cpp -o carrot -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./carrot

potato: PotatoTest.cpp Potato.h RootPlant.h Plant.h tile.h 
	g++ PotatoTest.cpp -o potato -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./potato

blueberry: BlueberryTest.cpp Blueberry.h BerryPlant.h Plant.h tile.h 
	g++ BlueberryTest.cpp -o blueberry -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./blueberry

strawberry: StrawberryTest.cpp Strawberry.h BerryPlant.h Plant.h tile.h 
	g++ StrawberryTest.cpp -o strawberry -I /include -L /lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./strawberry

plantAndPlayerTest: PlayerPlantInv.h PlayerTest.cpp tile.h Plant.h
	g++ PlayerTest.cpp -o plantMove -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./plantMove

textTest: TextboxTest.cpp TextBox.h tile.h Player.h
	g++ TextboxTest.cpp -o text -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./text

buymenuTest: BuyMenuTest.cpp Menu.h BuyMenu.h Player.h
	g++ BuyMenuTest.cpp -o buymenu -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./buymenu

menuTest: MenuTest.cpp menu.h tile.h Player.h
	g++ MenuTest.cpp -o menu -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./menu

# playerInteractionTest: PlayerInteractionTest.cpp PlayerInteraction.h tile.h Player.h Carrot.h
# 	clang++ PlayerInteractionTest.cpp -o playerInteraction -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
# 	./playerInteraction

inventoryTest: InventoryTest.cpp Inventory.h Player.h tile.h BuyMenu.h
	g++ InventoryTest.cpp -o inventory -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./inventory

playerInteractionTest: PlayerInteractionTest.cpp PlayerInteraction.h tile.h Player.h Carrot.h
	clang++ PlayerInteractionTest.cpp -o playerInteraction -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./playerInteraction

dayTest: DayTest.cpp Day.h tile.h Player.h
	clang++ DayTest.cpp -o day -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./day

sellmenuTest: SellMenuTest.cpp Menu.h BuyMenu.h Player.h SellMenu.h
	g++ SellMenuTest.cpp -o sellmenu -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./sellmenu

# has everything i.e. inventory, can plant plants, water plants, clock et.
everythingdayTest: dayEverythingTest.cpp Day.h BuyMenu.h menu.h Player.h Strawberry.h Blueberry.h Carrot.h Potato.h RootPlant.h BerryPlant.h Plant.h tile.h InventoryItems.h
	clang++ dayEverythingTest.cpp -o everythingDay -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./everythingDay

inventoryImageTest: InventoryImageTest.cpp InventoryItems.h tile.h
	g++ InventoryImageTest.cpp -o inven -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./inven

menuTextTest: mainMenuTextTest.cpp Day.h BuyMenu.h menu.h Player.h Strawberry.h Blueberry.h Carrot.h Potato.h RootPlant.h BerryPlant.h Plant.h tile.h InventoryItems.h
	clang++ mainMenuTextTest.cpp -o menuText -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./menuText

killPlantsTest: mainKillPlantsTest.cpp Day.h BuyMenu.h menu.h Player.h Strawberry.h Blueberry.h Carrot.h Potato.h RootPlant.h BerryPlant.h Plant.h tile.h InventoryItems.h
	clang++ mainKillPlantsTest.cpp -o killPlants -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./killPlants

harvestPlantsTest: harvestTest.cpp Day.h BuyMenu.h menu.h Player.h Strawberry.h Blueberry.h Carrot.h Potato.h RootPlant.h BerryPlant.h Plant.h tile.h InventoryItems.h
	clang++ harvestTest.cpp -o harvestTest -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./harvestTest

walletTest: walletAndSaveTest.cpp Day.h BuyMenu.h menu.h Player.h Strawberry.h Blueberry.h Carrot.h Potato.h RootPlant.h BerryPlant.h Plant.h tile.h InventoryItems.h
	clang++ walletAndSaveTest.cpp -o harvestTest -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./harvestTest

saveTest: SaveGameTest.cpp SaveGame.h Day.h BuyMenu.h menu.h Player.h Strawberry.h Blueberry.h Carrot.h Potato.h RootPlant.h BerryPlant.h Plant.h tile.h InventoryItems.h
	clang++ SaveGameTest.cpp -o saveTest -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./saveTest


Play: Game.cpp Game.h Day.h BuyMenu.h menu.h Player.h Strawberry.h Blueberry.h Carrot.h Potato.h RootPlant.h BerryPlant.h Plant.h tile.h InventoryItems.h
	clang++ Game.cpp -o Game -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
	./Game

clean: 
	rm tile player plantInventory plantImage rootplant berryPlantImage carrot potato blueberry strawberry plantMove text buymenu menu inventory playerInteraction day sellmenu everythingDay inven menuText killPlants harvestTest saveTest Game

all:
	make rootPlant
	make berryPlant
	make carrot
	make potato
	make strawberry
	make blueberry