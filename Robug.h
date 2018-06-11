#ifndef _ROBUG_H
#define _ROBUG_H 1

#include "Item.h"
#include "Direction.h"
#include "Color.h"

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
    
    //void hey(World * world) {}
    
    void move() {
        
        if (orient == Direction::N) {
            y++;
        } else if (orient == Direction::NE) {
            x++;
            y++;
        } else if (orient == Direction::E) {
            x++;
        } else if (orient == Direction::SE) {
            x++;
            y--;
        } else if (orient == Direction::S) {
            y--;
        } else if (orient == Direction::SW) {
            x--;
            y--;
        } else if (orient == Direction::W) {
            x--;
        } else if (orient == Direction::NW) {
            x--;
            y++;
        }
    }
};

#endif