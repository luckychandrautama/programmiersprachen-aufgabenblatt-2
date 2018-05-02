#include "vec2.hpp"
#include <iostream>

using namespace std;

Vec2::Vec2():
name{"default constructed"},
x{0},
y{0}{}

Vec2::Vec2(float const& _x, float const& _y):
name{"custom constructed"},
x {_x},
y {_y}{}

string Vec2::get_name() const{
    return name;
}

Vec2& Vec2:: operator+= (Vec2 const& v){
    this->x += v.x;
    this->y += v.y;
    
    return *this;
}

Vec2& Vec2:: operator-= (Vec2 const& v){
    x -= v.x;
    y -= v.y;
    
}

Vec2& Vec2:: operator*= (float s){
    this->x = this->x *s;
    this->y = this->y *s;
    
    return *this;
}

Vec2& Vec2:: operator/= (float s){
    if(s!=0){
        this->x /= s;
        this->y /= s;
    
        return *this;
    }
    
    else{
        cout<<"Division by 0 unacceptable \n";
        cout<<"Return original value \n";

        return *this;
    }
}
