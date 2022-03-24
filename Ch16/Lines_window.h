#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	
	Lines_window(Point xy, int w, int h, const string& title );

private:
	Open_polyline lines;

	Button next_button;
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Button menu_button;
	Menu style_menu;
	Button style_menu_button;

	void change(Color c);
	void style_change(Line_style s);
	void hide_menu();
	void hide_style_menu();

	void red_pressed();
	void blue_pressed();
	void black_pressed();

	void solid_pressed();
	void dash_pressed();
	void dot_pressed();
	void dashdot_pressed();
	void dashdotdot_pressed();

	void menu_pressed();
	void style_menu_pressed();

	void next();
	void quit();

	static void cb_red(Address, Address pw);
	static void cb_blue(Address, Address pw);
	static void cb_black(Address, Address pw);

	static void cb_solid(Address, Address pw);
	static void cb_dash(Address, Address pw);
	static void cb_dot(Address, Address pw);
	static void cb_dashdot(Address, Address pw);
	static void cb_dashdotdot(Address, Address pw);


	static void cb_menu(Address, Address pw);
	static void cb_style_menu(Address, Address pw);
};