/*
    g++ Ch13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
			^main	
	./main
*/
#include "Simple_window.h"
#include "Graph.h"



double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;
    
    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    Lines grid;
    for(int i = 0; i <= 8; i++) //9*2 szakasz
    {
    	grid.add(Point(0,i*100),Point(800,i*100));
    	grid.add(Point(i*100,0),Point(i*100,800));
    }
    win.attach(grid);

    Vector_ref<Rectangle> rect;
    for(int i = 0; i < 8; i++)
    {
    	rect.push_back(new Rectangle{Point{i*100,i*100}, Point{i*100+100,i*100+100}});
    	rect[i].set_fill_color(Color::red);
    	rect[i].set_color(Color{Color::invisible});
    	win.attach(rect[i]);
    }

    Vector_ref<Image> kepek;
    for(int i = 0; i < 3; i++)
    {
    	kepek.push_back(new Image{Point{0,(i+1)*200},"pac.jpg"});
		win.attach(kepek[i]);
	}

	Image football {Point(700,0), "ball.jpg"};
	win.attach(football);
    win.wait_for_button();

	for(int i = 0; i < 7; i++)
	{
		football.move(0,100);
		win.wait_for_button();
	}

	return 0;
}
