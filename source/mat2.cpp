#include "mat2.hpp"

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
    Mat2 result;

    result.a = m1.a * m2.a + m1.b * m2.c;
    result.b = m1.a * m2.b + m1.b * m2.d;
    result.c = m1.c * m2.a + m1.d * m2.c;
    result.d = m1.c * m2.b + m1.d * m2.d;

    return result;
}
