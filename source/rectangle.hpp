#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class Rectangle{

public:
    Rectangle();
    Rectangle(Vec2 const& punkt1, Vec2 const& punkt2, Color const& _color);
    
    float get_length() const;
    float get_width() const;
    
    Vec2 get_max() const;
    Vec2 get_min() const;

    float circumference() const;
    Color get_color() const;
            
private:
    Vec2 min_, max_;
    Color col;
};


#endif