#include "circle.hpp"
#include <cmath>

Circle::Circle(Vec2 const& _center, float _radius, Color const& _color):
center{_center},
radius{fabs(_radius)},
col{_color}
{

}

Vec2 Circle::get_center() const{
    
    return center;
}

float Circle::get_radius() const{
    return radius;
}

float Circle::circumference() const{

    return 2*M_PI*get_radius();
}

Color Circle::get_color() const{
    return col;
}

