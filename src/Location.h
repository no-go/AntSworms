#ifndef _LOCATION_H
#define _LOCATION_H 1

#include <string>
#include "Item.h"
#include "Color.h"

class Location : public Item {
public:
    string name;
    float value;
    
    Location() {
        color = {255,155,80,255};

        name = "food";
        color.R = 50;
        color.G = 50;
        color.B = 255;
        color.A = 255;
        value = 20.0;
    }
};

#endif