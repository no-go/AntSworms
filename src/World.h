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
#include "Robug.h"

class World : public Fl_Box {
    Fl_RGB_Image * _bild = nullptr;
    unsigned char *_pixbuf;
    int _width;
    int _height;

/*
    int handle(int e) {
        int ret = Fl_Box::handle(e);
        
        if (e == FL_PUSH) {
            if (Fl::event_button() == FL_LEFT_MOUSE) {
                updateAll();
                refresh();
            }
        }
        return(ret);
    }
*/

public:

    vector<Poi> pois;
    vector<Sensor> sensors;
    vector<Robug> robs;

    World(int X, int Y, int W, int H, const char*L=0) : Fl_Box(X,Y,W,H,L) {
        Color clr = {255, 255, 255};
        int x,y;
        
        _width = W;
        _height = H;
        _pixbuf = new unsigned char[_width*_height*3];
        
        for (x = 0; x < _width; ++x) {
            for(y = 0; y < _height; ++y) {
                set(x, y, clr, false);
            }
        }
    }
    
    
    ~World() {
        delete[] _pixbuf;
    }
    
    void updateAll() {
        Color col;
        col.R = 20;
        col.G = 255;
        col.B = 20;
        for (auto & rob : robs) {
            int last = rob.orient;
            //rob.orient = random() % 8;
            rob.orient = (last + (1 - random() % 3)) % 8;
            //rob.hey(this);
            set(rob.x, rob.y, col);
            rob.move();
            set(rob.x, rob.y, rob.color);
        }
        
        for (auto & poi : pois) {
            set(poi.x, poi.y, poi.color);
        }
        
        for (auto & sen : sensors) {
            set(sen.x, sen.y, sen.color);
        }
    }
    
    int random(int seed=0) {
        if (seed>0) srand(seed);
        return rand();
    }

    bool set(int x, int y, Color clr, bool fromMiddle=true) {
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
        return isValid;
    }
    
    void refresh(void) {
        if (_bild != nullptr) delete _bild;
        _bild = new Fl_RGB_Image((const unsigned char *) _pixbuf, _width, _height);
        image(*_bild);
        redraw();
    }
};

#endif