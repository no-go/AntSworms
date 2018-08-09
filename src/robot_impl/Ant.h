#ifndef _ROBOT_ANT_H
#define _ROBOT_ANT_H 1

#include "../Robot.h"
#include "../Color.h"
class World;
#include "../World.h"

class Ant : public Robot {
public:
    Color lastColor;
    
    Ant();
    
    void wakeup(World * world);
};

#endif