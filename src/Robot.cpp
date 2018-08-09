#include "Direction.h"
#include "Color.h"
#include "Robot.h"

Color Robot::color = {235,0,0,255};

void Robot::move() {
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
