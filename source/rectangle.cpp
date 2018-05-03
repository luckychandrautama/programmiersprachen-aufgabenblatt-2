#include "rectangle.hpp"
#include <cmath>
#include <algorithm>

using namespace std;

Rectangle::Rectangle(Vec2 const& punkt1, Vec2 const& punkt2, Color const& _color):
min_{min(punkt1.x,punkt2.x),min(punkt1.y,punkt2.y)},
max_{max(punkt1.x,punkt2.x),max(punkt1.y,punkt2.y)},
col{_color}
{

}

float Rectangle::get_length() const{
    return fabs(min_.y - max_.y);
}

float Rectangle::get_width() const{
    return fabs(min_.x - max_.x);
}

Vec2 Rectangle::get_max() const{
    return max_;
}

Vec2 Rectangle::get_min() const{
    return min_;
}

float Rectangle::circumference() const{
    return 2*(get_width()+get_length());
}

Color Rectangle::get_color() const{
    return col;
}
