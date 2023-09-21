plant: Plant.cpp Plant.h
    g++ Plant.cpp -o plant -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
    ./plant

rootPlant: RootPlant.cpp RootPlant.h Plant.cpp Plant.h
    g++ RootPlant.cpp -o rootplant -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
    ./rootplant

berryPlant: BerryPlant.cpp BerryPlant.h Plant.cpp Plant.h
    g++ BerryPlant.cpp -o berryplant -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath -std=c++11 ./lib
    ./berryplant