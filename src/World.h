#ifndef _WORLD_H
#define _WORLD_H 1

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

#include "Poi.h"
#include "Sensor.h"
class Robug;
#include "Robug.h"

class World : public Fl_Box {
    Fl_RGB_Image * _bild = nullptr;
    unsigned char *_pixbuf;
    unsigned char *_alpha;
    int _width;
    int _height;

public:

    static Color background;
    vector<Poi> pois;
    vector<Sensor> sensors;
    vector<Robug> robs;

    World(int X, int Y, int W, int H, const char*L=0) : Fl_Box(X,Y,W,H,L) {
        int x,y;
        
        _width = W;
        _height = H;
        _pixbuf = new unsigned char[_width*_height*3];
        _alpha = new unsigned char[_width*_height];
        
        for (x = 0; x < _width; ++x) {
            for(y = 0; y < _height; ++y) {
                set(x, y, World::background, false);
            }
        }
    }
    
    
    ~World() {
        delete[] _pixbuf;
    }
    
    void updateAll();
    
    int random(int seed=0);
    
    Color get(int x, int y, bool fromMiddle=true);

    bool set(int x, int y, Color clr, bool fromMiddle=true);
    
    void refresh(void);
};

#endif