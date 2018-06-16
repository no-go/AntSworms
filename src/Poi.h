#ifndef _POI_H
#define _POI_H 1

#include <string>
#include "Sensor.h"
#include "Color.h"

/**
 * a very interesting point in the world with a name and some functions
 */
class Poi : public Sensor {
public:
    string name;
    
    Poi() {
        name = "food";
        color.R = 50;
        color.G = 50;
        color.B = 255;
        value = 20.0;
    }
};

#endif