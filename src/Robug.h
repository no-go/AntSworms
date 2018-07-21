#ifndef _ROBUG_H
#define _ROBUG_H 1

#include "Item.h"
#include "Direction.h"
#include "Color.h"
class World;
#include "World.h"

/**
 * a bug robot
 */
class Robug : public Item {
public:
    int orient;
    
    Robug() {
        x = 0;
        y = 0;
        orient = Direction::STOP;
        color = {80,80,80};
    }
    
    void wakeup(World * world);
    void move();
};

#endif