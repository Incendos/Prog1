#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},
    color_menu{Point{x_max()-70,40},70,20,Menu::vertical,"color"},
    menu_button{Point{x_max()-90,40}, 90, 30, "color menu", cb_menu},
    style_menu{Point{x_max()-220,40},70,20,Menu::vertical,"style"},
    style_menu_button{Point{x_max()-240,40},90,30,"style menu",cb_style_menu}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    xy_out.put("no point");
    
    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
    
    attach(color_menu);
    color_menu.hide();
    attach(menu_button);
    
    style_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});
    style_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
    style_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});
    style_menu.attach(new Button{Point{0,0},0,0,"dashdot",cb_dashdot});
    style_menu.attach(new Button{Point{0,0},0,0,"-..",cb_dashdotdot});
    
    attach(style_menu);
    style_menu.hide();
    attach(style_menu_button);

    attach(lines);
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

void Lines_window::red_pressed()
{
    change(Color::red);
    hide_menu();
}

void Lines_window::blue_pressed()
{
    change(Color::blue);
    hide_menu();
}

void Lines_window::black_pressed()
{
    change(Color::black);
    hide_menu();
}

void Lines_window::change(Color c)
{
    lines.set_color(c);
}

void Lines_window::solid_pressed()
{
    style_change(Line_style::solid);
    hide_style_menu();
}

void Lines_window::dash_pressed()
{
    style_change(Line_style::dash);
    hide_style_menu();
}

void Lines_window::dot_pressed()
{
    style_change(Line_style::dot);
    hide_style_menu();
}

void Lines_window::dashdot_pressed()
{
    style_change(Line_style::dashdot);
    hide_style_menu();
}

void Lines_window::dashdotdot_pressed()
{
    style_change(Line_style::dashdotdot);
    hide_style_menu();
}

void Lines_window::style_change(Line_style s)
{
    lines.set_style(s);
}

void Lines_window::cb_red(Address, Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
}

void Lines_window::cb_blue(Address, Address pw) 
{
    reference_to<Lines_window>(pw).blue_pressed();
}
    
void Lines_window::cb_black(Address, Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
}

void Lines_window::hide_menu()
{
    color_menu.hide();
    menu_button.show();
}

void Lines_window::menu_pressed()
{
    menu_button.hide();
    color_menu.show();
}

void Lines_window::cb_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).menu_pressed();
}

void Lines_window::cb_solid(Address, Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
}

void Lines_window::cb_dash(Address, Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
}

void Lines_window::cb_dashdot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dashdot_pressed();
}

void Lines_window::cb_dashdotdot(Address, Address pw)
{
    reference_to<Lines_window>(pw).dashdotdot_pressed();
}

void Lines_window::hide_style_menu()
{
    style_menu.hide();
    style_menu_button.show();
}

void Lines_window::style_menu_pressed()
{
    style_menu_button.hide();
    style_menu.show();
}

void Lines_window::cb_style_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).style_menu_pressed();
}