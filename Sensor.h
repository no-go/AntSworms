#ifndef _SENSOR_H
#define _SENSOR_H 1

#include "Item.h"
#include "Color.h"

/**
 * for sensor values
 */
class Sensor : public Item {
public:
    float value;
    
    Sensor() {
        color = {255,155,80};
        value = 0.0;
    }
};

#endif