#ifndef VEC2_HPP
#define VEC2_HPP
#include <string>

//Vec2 class definition
struct Vec2
{
    Vec2();
    Vec2(float const& _x, float const& _y);
    
    // TODO Constructors
    std::string name;
    float x;
    float y;   
    
    std::string get_name() const;
 
    Vec2& operator+= (Vec2 const& v);
    Vec2& operator-= (Vec2 const& v);
    Vec2& operator*= (float s);
    Vec2& operator/= (float s);

};



#endif // VEC2_HPP