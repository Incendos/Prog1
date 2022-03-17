/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x)
{
    return 1;
}

double slope(double x)
{
    return x/2;
}


double square(double x)
{
    return x*x;
}

double sloping_cos(double x)
{
    return cos(x) + slope(x);
}

int main()
{
const Point origo {300, 300};
const int minrange {-10};
const int maxrange {11};
const int npoints {400};
const int scale{20};

using namespace Graph_lib;

Simple_window win {Point{100,100}, 600, 600, "Function graphs."};

Axis x {Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
Axis y {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};

x.set_color(Color::red);
y.set_color(Color::red);

//  Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
Function konstans {one,minrange, maxrange, origo, npoints, scale, scale};
Function linear {slope, minrange, maxrange, origo, npoints, scale, scale};
Function parabola {square, minrange, maxrange, origo, npoints, scale, scale};
Function cosin { [] (double x) { return cos(x); }, minrange, maxrange, origo, npoints, scale, scale};
Function slopecos {sloping_cos, minrange, maxrange, origo, npoints, scale, scale};

Text labelkonstans {Point{100-20,300-20},"x/2"};

cosin.set_color(Color::blue);

win.attach(x);
win.attach(y);
win.attach(konstans);
win.attach(linear);
win.attach(labelkonstans);
win.attach(parabola);
win.attach(cosin);
win.attach(slopecos);
win.wait_for_button();
return 0;
}