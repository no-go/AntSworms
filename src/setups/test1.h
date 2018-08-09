#include <vector>

using namespace std;

#include "../World.h"
#include "../Location.h"
#include "../Tile.h"
#include "../robot_impl/Ant.h"

#define ANTS 800

void loadSetup(World * world) {
    Location poi1,poi2;
    poi1.x = 7;
    poi1.y = 8;
    poi2.x = -5;
    poi2.y = -2;
    world->locations.push_back(poi1);
    world->locations.push_back(poi2);
    
    for (int i=0; i<ANTS; ++i) {
        world->robots.push_back(new Ant());
    }
    return;
}
