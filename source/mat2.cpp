#include "mat2.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Mat2::Mat2() : a{1},
               b{0},
               c{0},
               d{1}
{
}

Mat2::Mat2(float _a, float _b, float _c, float _d) : a{_a},
                                                     b{_b},
                                                     c{_c},
                                                     d{_d}
{
}

Mat2 &Mat2::operator*=(Mat2 const &m)
{
    a = a * m.a + b * m.c;
    b = a * m.b + b * m.d;
    c = c * m.a + d * m.c;
    d = c * m.b + d * m.d;

    return *this;
}

Mat2 operator*(Mat2 const &m1, Mat2 const &m2)
{
    Mat2 result{m1};

    result *= m2;

    return result;
}

float Mat2::det() const
{

    float result = a * d - b * c;
    return result;
}

Vec2 operator*(Mat2 const &m, Vec2 const &v)
{
    Vec2 result{m.a * v.x + m.b * v.y, m.c * v.x + m.d * v.y};
    return result;
}

Vec2 operator*(Vec2 const &v, Mat2 const &m)
{
    cout << "Wrong order. return [matrix]*[vector] \n";
    return m * v;
}

Mat2 transpose(Mat2 const &m)
{
    Mat2 trans{m.a, m.c*-1, m.b*-1, m.d};
    return trans;
}

Mat2 inverse(Mat2 const &m)
{
    if (m.det() != 0)
    {
        Mat2 result{transpose(m).a / m.det(), transpose(m).b / m.det(), transpose(m).c / m.det(), transpose(m).d / m.det()};
        return result;
    }
    else
    {
        cout << "determinant is zero. Inversion not possible \n";
        return m;
    }
}

Mat2 make_rotation_mat2(float phi)
{
    Mat2 result{cos(phi), -sin(phi), sin(phi), cos(phi)};
    return result;
}