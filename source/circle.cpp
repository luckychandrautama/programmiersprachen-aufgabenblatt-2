#include "circle.hpp"
#include <cmath>

Circle::Circle(Vec2 const& _center, float _radius):

center{_center},
radius{fabs(_radius)}
{

}

Vec2 Circle::get_center() const{
    
    return center;
}

float Circle::get_radius() const{
    return radius;
}