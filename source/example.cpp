#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "rectangle.hpp"
#include "circle.hpp"

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  Vec2 punkt1{200.00f,560.00f};
  Vec2 punkt2{134.00f,450.00f};
  Vec2 punkt3{350.0f,350.0f};

  Color test {0.5f,0.7f,1.0f};
  Color white {1.0}; 

  Color overload {0.3f,0.3f, 0.8f};
  
  Circle cir1 {punkt3, 300.00f, white};
  Circle cir2 {punkt1, 50.0f, white};
  

  Rectangle rect1 {punkt1, punkt2, test};
  Rectangle rect2 {punkt3, punkt2, test};
  
  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    
    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1{400 + 380 * std::sin(t)};
    float y1{400 + 380 * std::cos(t)};

    float x2{400 + 380 * std::sin(2.0f*t)};
    float y2{400 + 380 * std::cos(2.0f*t)};

    float x3{400 + 380 * std::sin(t-10.f)};
    float y3{400 + 380 * std::cos(t-10.f)};

    
    win.draw_point(x1, y1,
        1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,0.0,0.0);
    }

    win.draw_line(0, m.second, 10, m.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    win.draw_text(10, 5, 35.0f, text);

    //AUFGABE 2.11
    rect1.draw(win,test);
    cir1.draw(win,white);

    //AUFGABE 2.12
    cir2.draw(win,overload);
    rect2.draw(win,overload);
    win.update();
  }

  
  return 0;
}
