#include "Item.h"
#include "Direction.h"
#include "Color.h"
#include "Robug.h"
#include "World.h"

void Robug::wakeup(World * world) {
    int last = orient;
    //rob.orient = random() % 8;
    orient = (last + (1 - world->random() % 3)) % 8;
    world->set(x, y, world->background);
    move();
    world->set(x, y, color);
}

void Robug::move() {
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
