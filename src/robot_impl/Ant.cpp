#include "../Direction.h"
#include "../Color.h"
#include "../World.h"
#include "Ant.h"

Ant::Ant() {
    x = 0;
    y = 0;
    orient = Direction::STOP;
    lastColor = World::background;
}

void Ant::wakeup(World * world) {
    int last = orient;
    int lastx = x;
    int lasty = y;
    
    //rob.orient = random() % 8;
    orient = (last + (1 - world->random() % 3)) % 8;

    move();

    if (!lastColor.equal(Ant::color)) {
        if (lastColor.R >= 80) lastColor.R -= 80;
        if (lastColor.G >= 80) lastColor.G -= 80;
        if (lastColor.B >= 80) lastColor.B -= 80;
        world->set(lastx, lasty, lastColor);
    }
    lastColor = world->get(x, y);
    world->set(x, y, Ant::color);
}
