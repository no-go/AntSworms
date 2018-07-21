#include "Item.h"
#include "Direction.h"
#include "Color.h"
#include "Robug.h"
#include "World.h"

Robug::Robug() {
    x = 0;
    y = 0;
    orient = Direction::STOP;
    color = {185,0,0,255};
    lastColor = World::background;
}

void Robug::wakeup(World * world) {
    int last = orient;
    int lastx = x;
    int lasty = y;
    
    //rob.orient = random() % 8;
    orient = (last + (1 - world->random() % 3)) % 8;

    move();

    if (!lastColor.equal(color)) {
        if (lastColor.R > 0) lastColor.R -= 15;
        if (lastColor.G > 0) lastColor.G -= 15;
        if (lastColor.B > 0) lastColor.B -= 15;
        world->set(lastx, lasty, lastColor);
    }
    lastColor = world->get(x, y);
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
