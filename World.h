#include <cstdio>
#include <cstdlib> // rand

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Image.H>
#include <FL/names.h>

using namespace std;

#include "Color.h"
#define RANDOM_SEED 4711

class World: public Fl_Box {
    Fl_RGB_Image * _bild = nullptr;
    unsigned char *_pixbuf;
    int _width;
    int _height;

    int handle(int e) {
        int ret = Fl_Box::handle(e);
        
        if (e == FL_PUSH) {
            if (Fl::event_button() == FL_LEFT_MOUSE) {
                refresh();
            }
        }
        return(ret);
    }
    
public:
    World(int X, int Y, int W, int H, const char*L=0) : Fl_Box(X,Y,W,H,L) {
        Color clr;
        int x,y;
        srand(RANDOM_SEED);
        
        _width = W;
        _height = H;
        _pixbuf = new unsigned char[_width*_height*3];
        
        for (x = 0; x < _width; ++x) {
            for(y = 0; y < _height; ++y) {
                clr = palette(0);
                set(x, y, clr);
            }
        }
    }
    
    ~World() {
        delete[] _pixbuf;
    }
    
    int random() {
        return rand();
    }

    
    void set(int x, int y, Color clr) {
        _pixbuf[3*(y*_width+x)] = clr.R;
        _pixbuf[3*(y*_width+x)+1] = clr.G;
        _pixbuf[3*(y*_width+x)+2] = clr.B;
    }

    void refresh(void) {
        Color clr;
        int x,y;
        
        for (x = 0; x < _width; ++x) {
            for(y = 0; y < _height; ++y) {
                clr = palette(this->random()%33);
                set(x, y, clr);
            }
        }
        if (_bild != nullptr) delete _bild;
        _bild = new Fl_RGB_Image((const unsigned char *) _pixbuf, _width, _height);
        image(*_bild);
        redraw();
    }
};
