#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"

class Circle{

public:
    Circle();
    Circle(Vec2 const& _center, float _radius);

    Vec2 get_center() const;
    float get_radius() const;

private:
    Vec2 center;
    float radius;
};

#endif // CIRCLE2_HPP