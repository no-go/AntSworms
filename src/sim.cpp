#include <cstdlib> // atoi
#include <cstdio>
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Image.H>
#include <FL/names.h>

using namespace std;

#include "World.h"

//----------------------------------
#define SIM_SPEED 0.02
#define RANDOM_SEED 4211
#include "setups/test1.h"
//----------------------------------

void winUpdate(void *data) {
    static unsigned i = 0;
    World *o = (World*) data;
    o->updateAll();
    o->refresh();
    Fl::add_timeout(SIM_SPEED, winUpdate, data);
}

int main(int argc, char ** argv) {
    if (argc<3) {
        printf("%s <world width> <world height>\n", argv[0]);
        return 1;
    }
    int width = atoi(argv[1])*2;
    int height = atoi(argv[2])*2;

    Fl::visual(FL_RGB);
    Fl_Window win(width, height, "Robug Sworms");
    World * world = new World(0, 0, width, height);
    world->random(RANDOM_SEED);
    
    loadSetup(world);
    
    world->updateAll();
    world->refresh();
    
    Fl::add_timeout(2, winUpdate, world);
    win.end();
    Fl::visual(FL_DOUBLE|FL_INDEX);
    win.show();
    Fl::run();

    return 0;
}
