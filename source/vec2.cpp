#include "vec2.hpp"
#include <iostream>

using namespace std;

Vec2::Vec2() : name{"default constructed"},
               x{0},
               y{0} {}

Vec2::Vec2(float const &_x, float const &_y) : name{"custom constructed"},
                                               x{_x},
                                               y{_y} {}

string Vec2::get_name() const
{
    return name;
}

Vec2 &Vec2::operator+=(Vec2 const &v)
{
    x += v.x;
    y += v.y;

    return *this;
}

Vec2 &Vec2::operator-=(Vec2 const &v)
{
    x -= v.x;
    y -= v.y;

    return *this;
}

Vec2 &Vec2::operator*=(float s)
{
    x = x * s;
    y = y * s;

    return *this;
}

Vec2 &Vec2::operator/=(float s)
{
    if (s != 0)
    {
        x /= s;
        y /= s;

        return *this;
    }

    else
    {
        cout << "Division by 0 unacceptable \n";
        cout << "Return original value \n";

        return *this;
    }
}

Vec2 operator+(Vec2 const &u, Vec2 const &v)
{
    Vec2 result;
    result.x = u.x + v.x;
    result.y = u.y + v.y;

    return result;
}

Vec2 operator-(Vec2 const &u, Vec2 const &v)
{
    Vec2 result;
    result.x = u.x - v.x;
    result.y = u.y - v.y;
    Vec2 operator*(float s, Vec2 const &v);

    return result;
}

Vec2 operator*(Vec2 const &u, float s)
{
    Vec2 result{u};

    result *= s;
    return result;
}

Vec2 operator/(Vec2 const &u, float s)
{
    Vec2 result;

    if (s != 0)
    {
        result.x = u.x / s;
        result.y = u.y / s;

        return result;
    }
    else
    {

        cout << "Division by 0 unacceptable \n";
        cout << "Return original value \n";

        return u;
    }
}

Vec2 operator*(float s, Vec2 const &v)
{
    return v*s;
}