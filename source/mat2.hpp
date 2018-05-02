#ifndef MAT2_HPP
#define MAT2_HPP
#include <string>

// Mat2 definition
struct Mat2
{
    // ...

    Mat2();
    Mat2(float _a, float _b, float _c, float _d);

    Mat2 &operator*=(Mat2 const &m);

    float a, b, c, d;

    // ...
};

Mat2 operator*(Mat2 const &m1, Mat2 const &m2);

#endif // MAT2_HPP