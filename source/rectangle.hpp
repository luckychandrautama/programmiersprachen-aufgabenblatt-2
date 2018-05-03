#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"

class Rectangle{

public:
    Rectangle(Vec2 const& _min, Vec2 const& _max);
    
    float get_length() const;
    float get_width() const;
    
    Vec2 get_max() const;
    Vec2 get_min() const;
            
private:
    Vec2 min_, max_;
};


#endif