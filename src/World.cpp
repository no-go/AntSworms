#include <cstdio>
#include <cstdlib> // rand
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Image.H>
#include <FL/names.h>

using namespace std;

#include "Color.h"
#include "World.h"

Color World::background = {255, 255, 255, 255};

void World::updateAll() {
    for (auto & rob : robs) {
        rob.wakeup(this);
    }
    
    
    for (auto & poi : pois) {
        set(poi.x, poi.y, poi.color);
    }
    
    for (auto & sen : sensors) {
        set(sen.x, sen.y, sen.color);
    }
}

int World::random(int seed) {
    if (seed>0) srand(seed);
    return rand();
}

Color World::get(int x, int y, bool fromMiddle) {
    Color clr;
    if (fromMiddle) {
        x += _width/2;
        y += _height/2;
    }
    
    // the border stops, all dots are frozen
    if (x >= (_width-1)) x=_width-1;
    if (x < 1) x = 0;
    if (y >= (_height-1)) y=_height-1;
    if (y < 1) y = 0;
    
    clr.R = _pixbuf[3*(y*_width+x)];
    clr.G = _pixbuf[3*(y*_width+x)+1];
    clr.B = _pixbuf[3*(y*_width+x)+2];
    clr.A = _alpha[(y*_width+x)];
    return clr;
}

bool World::set(int x, int y, Color clr, bool fromMiddle) {
    bool isValid = true;
    if (fromMiddle) {
        x += _width/2;
        y += _height/2;
    }
    
    // the border stops, all dots are frozen
    if (x >= (_width-1)) {
        x=_width-1;
        isValid = false;
    }
    
    if (x < 1) {
        x = 0;
        isValid = false;
    }
    
    if (y >= (_height-1)) {
        y=_height-1;
        isValid = false;
    }
    
    if (y < 1) {
        y = 0;
        isValid = false;
    }
    
    _pixbuf[3*(y*_width+x)] = clr.R;
    _pixbuf[3*(y*_width+x)+1] = clr.G;
    _pixbuf[3*(y*_width+x)+2] = clr.B;
    _alpha[(y*_width+x)] = clr.A;
    return isValid;
}

void World::refresh(void) {
    if (_bild != nullptr) delete _bild;
    _bild = new Fl_RGB_Image((const unsigned char *) _pixbuf, _width, _height);
    image(*_bild);
    redraw();
}
