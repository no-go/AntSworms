#include <cstdlib> // atoi
#include <cstdio>
#include <cmath> // floor

#include <mutex>
#include <atomic>
#include <condition_variable>

#include <thread>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Image.H>
#include <FL/names.h>

using namespace std;

// ---------------------------------------
#define INITITER 400
#define ABBRUCH 4.0
int width;
int height;
float * arr;
// ---------------------------------------

struct Color{ unsigned char R,G,B; };

class Semaphore {
private:
	std::mutex _mtx;
	std::condition_variable _cv;
	std::atomic<int> _count;
public:
	Semaphore(int count = 0) {
		_count = count;
	}
	void V() {
		std::unique_lock<std::mutex> lck(_mtx);
		_count++;
		_cv.notify_one();
	}
	void P() {
		std::unique_lock<std::mutex> lck(_mtx);
		while(_count == 0) _cv.wait(lck);
		_count--;
	}
};

double centerRe,centerIm;
double zoom,inZoom,outZoom;
int maxiter = INITITER;
double miniter;

double imageRelation;
Semaphore * s;

Color toColor(double id) {
	Color col;
	col.R = 0; col.G = 0; col.B = 0;
	if( id == maxiter ) return col;
	double hi,q,t,coef;
	
	id -= miniter;
	coef = 7.0 * (id/(maxiter-miniter));
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

void compute(int y) {
	int i,x;
	double zRe,zIm, cRe,cIm, newzRe,newzIm, quad, tmp1,tmp2;

	for (x = 0; x < width; ++x) {
		zRe = 0;
		zIm = 0;
		quad= 0;
		
		// aus x,y Koordinaten werden entsprechende Real,Imag Zahlen ermittelt
		tmp1 = zoom * imageRelation * ( x * 2.0/width -1);
		tmp2 = zoom *(1.0 - y * 2.0/height);
		cRe = tmp1 + centerRe;
		cIm = tmp2 + centerIm;
		
		for(i=0; i < maxiter && quad < ABBRUCH; ++i) {
			tmp1 = zRe*zRe;
			tmp2 = zIm*zIm;
			quad =tmp1 + tmp2;
			
			newzRe = tmp1 - tmp2 + cRe;
			newzIm = zRe * zIm * 2.0 + cIm;
			
			zRe = newzRe;
			zIm = newzIm;
		}
		if (i < miniter) miniter = i;
		arr[y*width+x] = (quad/ABBRUCH) +i;
	}
	
	s->V();
}

class MandelBox: public Fl_Box {
	Fl_RGB_Image * _bild;
	
	int handle(int e) {
		int ret = Fl_Box::handle(e);
		bool doit = false;
		
		if (e == FL_PUSH) {
			if (Fl::event_button() == FL_LEFT_MOUSE) {
				zoom *= inZoom;
				maxiter +=10;
				doit=true;
			} else if (Fl::event_button() == FL_RIGHT_MOUSE) {
				zoom *= outZoom;
				if (maxiter > INITITER) maxiter -=10;
				doit=true;
			}
		}
		
		if (doit == true) {
			centerRe += zoom * imageRelation * ( Fl::event_x() * 2.0/width -1);
			centerIm += zoom *(1.0 - Fl::event_y() * 2.0/height);
			miniter = maxiter;
			createImage();
		}
		return(ret);
	}
public:
	MandelBox(int X,int Y,int W,int H,const char*L=0) : Fl_Box(X,Y,W,H,L) {}
	
	void createImage(void) {
		Color clr;
		int x,y;
		unsigned char pixbuf[width*height][3];
		for(y=0; y < height; ++y) {
			thread t(compute, y);
			t.detach();
			s->P();
		}
		// Hier kann es sein, dass gezeichnet wird, obwohl noch thraeds rechnen +++++
		for (x = 0; x < width; ++x) {
			for(y=0; y < height; ++y) {
				clr = toColor(arr[y*width+x]);
				pixbuf[y*width+x][0] = clr.R;
				pixbuf[y*width+x][1] = clr.G;
				pixbuf[y*width+x][2] = clr.B;
			}
		}
		_bild = new Fl_RGB_Image((const unsigned char *) &pixbuf, width, height);
		image(*_bild);
		redraw();
	}
};

MandelBox * box;

// ---------------------------------------------------------------------
int main(int argc, char ** argv) {
// ---------------------------------------------------------------------
	if (argc<3) {
		printf("mandel <Bildbreite> <Bildhoehe>\n");
		return 1;
	}
	width = atoi(argv[1]);
	height = atoi(argv[2]);

	arr = new float[height * width];
	imageRelation = (float) width / (float) height;
	
	int cores = thread::hardware_concurrency();
	s = new Semaphore(cores);
	
	centerRe = -0.5;
	centerIm = 0.0;
	zoom = 1.0;
	inZoom = 0.75;
	outZoom = 1.25;
	
	Fl::visual(FL_RGB);
	Fl_Window win(width, height, "Mandelbrote");
	box = new MandelBox(0, 0, width, height);
	box->createImage();
	win.show();
	Fl::run();
	
	delete s;
	delete[] arr;
	return 0;
}
