#include <cmath> // floor

#define MAXCOLOR 32.0

struct Color{ unsigned char R,G,B; };

Color palette(double id) {
    Color col;
    col.R = 255; col.G = 255; col.B = 255;
    if (id == 0) return col;
    if (id < 0) {
        col.R = 0; col.G = 0; col.B = 0;
        return col;
    }
    if (id > MAXCOLOR) id = ((int)id)%((int)MAXCOLOR+1);
    
    double hi,q,t,coef;

    coef = 7.0 * (id/MAXCOLOR);
    hi = floor(coef);
    t = coef - hi;
    q = 1 - t;

    if (hi == 0.0) {
        col.R = 0;
        col.G = t*255; //immer mehr green und blau -> dunkelblau zu cyan
        col.B = t*127 + 128;
    } else if (hi == 1.0) {
        col.R = t*255; //immer mehr rot -> cyan zu weiss
        col.G = 255;
        col.B = 255;
    } else if (hi == 2.0) {
        col.R = 255;
        col.G = 255;
        col.B = q*255; // immer weniger blau -> weiss zu gelb
    } else if (hi == 3.0) {
        col.R = 255;
        col.G = q*127 + 128; // immer weniger green -> gelb zu orange
        col.B = 0;
    } else if (hi == 4.0) {
        col.R = q*127 + 128; // orange wird dunkler -> orange zu braun
        col.G = q*63 + 64;
        col.B = 0;
    } else if (hi == 5.0) {
        col.R = 128;
        col.G = 64;
        col.B = t*128; // mehr blau -> braun zu violett
    } else if (hi == 6.0) {
        col.R = q*128; // weniger rot und green -> violett wird dunkelblau
        col.G = q*64;
        col.B = 128;
    }
    return col;
}