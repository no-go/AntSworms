#ifndef _COLOR_H
#define _COLOR_H 1

struct Color{
    unsigned char R,G,B,A;
    
    bool equal(Color a) {
        return (R == a.R && G == a.G && B == a.B && A == a.A);
    }
};

#endif