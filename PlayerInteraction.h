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

            for (int i = 0; i < 144; i++) {
                tile* currentTile = (*backgroundTiles)[i]; // Access the current tile pointer in the vector

                // determine which tile the player is on
                if (currentTile->get_x() == player_x && currentTile->get_y() == player_y){
                    if (currentTile->get_isPlantable() == true) {
                        switch (seedType) {
                            case 1: // type 1 is carrot 
                            {
                                // create a new carrot tile (in the heap) with cooridnates of player position and set carrot as a pointer to the carrot tile
                                Carrot* carrot = new Carrot(player_x, player_y);
                                // remove old tile from vector and replace with new carrot tile
                                delete currentTile;
                                // sets the current tile player is on to be a carrot tile
                                (*backgroundTiles)[i] = carrot;
                                break;
                            }

                            case 2: // type 2 is potato
                            {
                                // create a new potato tile (in the heap) with cooridnates of player position and set potato as a pointer to the potato tile
                                Potato* potato = new Potato(player_x, player_y);
                                // remove old tile from vector and replace with new carrot tile
                                delete currentTile;
                                // sets the current tile player is on to be a carrot tile
                                (*backgroundTiles)[i] = potato;
                                break;
                            }

                            case 3: // type 3 is blueberry
                            {
                                // create a new bluebbery tile (in the heap) with cooridnates of player position and set blueberry as a pointer to the blueberry tile
                                Blueberry* blueberry = new Blueberry(player_x, player_y);
                                // remove old tile from vector and replace with new carrot tile
                                delete currentTile;
                                // sets the current tile player is on to be a carrot tile
                                (*backgroundTiles)[i] = blueberry;
                                break;
                            }

                            case 4: // type 4 is strawberry
                            {
                                // create a new strawberry tile (in the heap) with cooridnates of player position and set strawberry as a pointer to the strawberry tile
                                Strawberry* strawberry = new Strawberry(player_x, player_y);
                                // remove old tile from vector and replace with new carrot tile
                                delete currentTile;
                                // sets the current tile player is on to be a carrot tile
                                (*backgroundTiles)[i] = strawberry;
                                break;
                            }
                            
                            default:    
                                std::cout<< "error: could not plant as type was invalid" << std::endl;

                        }; 
                        break; // stops looping through for loop
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