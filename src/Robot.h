#ifndef _ROBOT_H
#define _ROBOT_H 1

#include "Item.h"
#include "Direction.h"
#include "Color.h"
class World;
#include "World.h"

class Robot : public Item {
public:
    int orient;
    static Color color;
    
    Robot() {}
    virtual ~Robot() = 0;
    virtual void wakeup(World * world) = 0;

    void move();
};

#endif