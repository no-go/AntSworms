#include <cstdlib> // atoi, rand
#include <cstdio>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Image.H>
#include <FL/names.h>

using namespace std;

#include "World.h"

World * world;

int main(int argc, char ** argv) {
    if (argc<3) {
        printf("%s <Bildbreite> <Bildhoehe>\n", argv[0]);
        return 1;
    }
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    Fl::visual(FL_RGB);
    Fl_Window win(width, height, "AntSworms");
    world = new World(0, 0, width, height);
    world->refresh();
    win.show();
    Fl::run();

    return 0;
}
