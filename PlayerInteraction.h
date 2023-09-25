#ifndef PLAYERINTERACTION_H
#define PLAYERINTERACTION_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
#include "Player.h"
#include "Plant.h"
#include "Carrot.h"
#include "Potato.h"
#include "Blueberry.h"
#include "Strawberry.h"
#include "tile.h"

class PlayerInteraction {
    protected:
        // std::vector<Carrot*> carrotVector;
        // std::vector<Potato*> potatoVector;


    public:
        PlayerInteraction() {};

        void seedPlant(int seedType, Player p, std::vector<tile*>* backgroundTiles) { // takes in an int which represents the seed type, takes in an object player, and a pointer to a vector of pointers to tiles (a pointer to background tiles)
            
            // changes the x and y coordinates of the player to valid tile positions
            int player_x = (floor(p.get_x()/50)*50);
            int player_y = (floor(p.get_y()/50)*50);
            
            // int player_x = p.get_x()/50;
            // player_x = player_x * 50;

            // int player_y = p.get_y()/50;
            // player_y = player_y * 50;

            for (int i = 0; i < 144; i++) {
                tile* currentTile = (*backgroundTiles)[i]; // Access the current tile pointer in the vector

                // determine which tile the player is on
                if (currentTile->get_x() == player_x && currentTile->get_y() == player_y){
                    if (currentTile->get_isPlantable() == true) {
                        // switch (seedType) {
                        //     case 1: // 1 is carrot seeds
                                
                                // create a new carrot tile (in the heap) with cooridnates of player position and set carrot as a pointer to the carrot tile
                                Carrot* carrot = new Carrot(player_x, player_y);
                                
                                // remove old tile from vector and replace with new carrot tile
                                delete currentTile;
                                // sets the current tile player is on to be a carrot tile
                                (*backgroundTiles)[i] = carrot;
                                break;
                    }
                }
            }
            return;
        };
};


                                // carrotVector.push_back(carrot);

                            //     break;
                            // case 2: // 2 is potato seeds
                            //     Potato potato(p.get_x(), p.get_y());
                            //     break;
                            // case 3: // 3 is strawberry seeds
                            //     Strawberry strawberry(p.get_x(), p.get_y());
                            //     break;
                            // case 4: // 4 is blueberry seeds
                            //     Blueberry blueberry(p.get_x(), p.get_y());
                            //     break;
                            // default:
                            //     break;
//                             // }
//                     }
//                 }
//             }

            
//         };

//         void harvestPlant(){
//                 return;
//                 };
//         void waterPlant() {
//             return;
//         };

//         return;
// };




#endif