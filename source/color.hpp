#ifndef COLOR_HPP
#define COLOR_HPP
#include <algorithm>

using namespace std;
struct Color{

    Color(float _r, float _g, float _b):
    r{_r},
    g{_g},
    b{_b}
{
    r = max(r,0.0f) || min(r,1.0f);
    g = max(g,0.0f) || min(g,1.0f);
    b = max(b,0.0f) || min(b,1.0f);
    
};

    Color(float s):
    r{s},
    g{s},
    b{s}
{
    s = max(s,0.0f) || min(s,1.0f);
};

    float r,g,b;
};

#endif //COLOR_HPP