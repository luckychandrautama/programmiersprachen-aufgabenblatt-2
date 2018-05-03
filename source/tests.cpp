#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

#include "color.hpp"

// AUFGABE 2.3

TEST_CASE("vec2 constructor", "[vector1]")
{
  REQUIRE(Vec2().x == 0);
  REQUIRE(Vec2().y == 0);

  REQUIRE(Vec2(2, 3).x == Approx(2.00f).epsilon(0.001));
  REQUIRE(Vec2(2.56, 3.78).y == Approx(3.78f).epsilon(0.001));

  Vec2 vector_03{};
  REQUIRE(vector_03.x == 0);
  REQUIRE(vector_03.y == 0);
}

// AUFGABE 2.4

TEST_CASE("vec2 operator+=", "[vector2]")
{
  REQUIRE((Vec2() += Vec2(2.56, 3.78)).x == 2.56f);
  REQUIRE((Vec2() += Vec2(2.56, 3.78)).y == 3.78f);

  REQUIRE((Vec2(-1.56, -2.01) += Vec2(2.56, 3.78)).x == Approx(1.0f).epsilon(0.01));
  REQUIRE((Vec2(-1.56, -2.01) += Vec2(2.56, 3.78)).y == Approx(1.77f).epsilon(0.01));
}

TEST_CASE("vec2 operator-=", "[vector3]")
{
  Vec2 vector_01(2.67f, -1.78f);
  Vec2 vector_02(-3.87f, 2.00f);

  Vec2 vector_03;
  Vec2 vector_04(-3.87f, -2.00f);

  REQUIRE((vector_01 -= vector_02).x == Approx(6.54f).epsilon(0.01));
  REQUIRE((vector_01 -= vector_02).x == Approx(10.41f).epsilon(0.01));

  REQUIRE((vector_01 -= vector_02).y == Approx(-7.78f).epsilon(0.01));
  REQUIRE((vector_03 -= vector_04).x == 3.87f);
  REQUIRE((vector_03 -= vector_04).y == 4.00f);

  REQUIRE((Vec2() -= vector_02).x == Approx(3.87f).epsilon(0.01));
}

TEST_CASE("vec2 operator*=", "[vector4]")
{
  Vec2 vector_01(2.67f, -1.78f);
  Vec2 vector_03;

  REQUIRE((vector_01 *= 2.00).x == Approx(5.34f).epsilon(0.01));
  REQUIRE((Vec2() *= 1).y == Approx(0).epsilon(0.01));

  REQUIRE((vector_03 *= 5).x == 0);
  REQUIRE((vector_01 *= -1.00).y == Approx(3.56f).epsilon(0.01));

  REQUIRE((vector_01 *= 0).x == Approx(0).epsilon(0.01));
}

TEST_CASE("vec2 operator/=", "[vector5]")
{
  Vec2 vector_01(2.67f, -1.78f);
  Vec2 vector_02(-3.87f, 2.00f);

  Vec2 vector_03;

  REQUIRE((vector_01 /= 2.00).x == Approx(1.34f).epsilon(0.01));
  REQUIRE((Vec2() /= 1).y == Approx(0).epsilon(0.01));

  REQUIRE((vector_03 *= 5).x == 0);
  REQUIRE((vector_01 /= -1.5).y == Approx(0.599f).epsilon(0.01));
  REQUIRE((vector_02 /= 0).x == vector_02.x);
}

// AUFGABE 2.4
TEST_CASE("vec2 operator+", "[vector6]")
{
  Vec2 vector_01{2.67f, -1.78f};
  Vec2 vector_02{-3.87f, 2.00f};

  Vec2 vector_03;

  REQUIRE((vector_01 + vector_02).x == Approx(-1.2f).epsilon(0.01));
  REQUIRE((vector_01 + vector_02).y == Approx(0.22f).epsilon(0.01));

  REQUIRE((vector_03 + vector_01).x == Approx(2.67f).epsilon(0.01));
  REQUIRE((vector_03 + vector_01).y == Approx(-1.78f).epsilon(0.01));
}

TEST_CASE("vec2 operator-", "[vector7]")
{
  Vec2 vector_01{2.67f, -1.78f};
  Vec2 vector_02{-3.87f, 2.00f};

  Vec2 vector_03{};

  REQUIRE((vector_01 - vector_02).x == Approx(6.55f).epsilon(0.01));
  REQUIRE((vector_01 - vector_02).y == Approx(-3.78f).epsilon(0.01));

  REQUIRE((vector_03 - vector_01).x == Approx(-2.67f).epsilon(0.01));
  REQUIRE((vector_03 - vector_01).y == Approx(1.78f).epsilon(0.01));
}

TEST_CASE("vec2 operator*", "[vector8]")
{
  Vec2 vector_01{2.67f, -1.78f};
  Vec2 vector_02{-3.87f, 2.00f};

  Vec2 vector_03{};

  REQUIRE((vector_01 * 2.0).x == Approx(5.34f).epsilon(0.01));
  REQUIRE((vector_02 * -1.34).y == Approx(-2.68f).epsilon(0.01));

  REQUIRE((vector_03 * 2.0).x == Approx(0).epsilon(0.01));
  REQUIRE((vector_03 * 2.0).y == Approx(0).epsilon(0.01));

  REQUIRE((2.0 * vector_01).x == Approx(5.34f).epsilon(0.01));
  REQUIRE((-1.34 * vector_02).y == Approx(-2.68f).epsilon(0.01));

  REQUIRE((2.0 * vector_03).x == Approx(0).epsilon(0.01));
  REQUIRE((2.0 * vector_03).y == Approx(0).epsilon(0.01));
}

TEST_CASE("vec2 operator/", "[vector9]")
{
  Vec2 vector_01{2.67f, -1.78f};
  Vec2 vector_02{-3.87f, 2.00f};

  Vec2 vector_03{};

  REQUIRE((vector_01 / 2.0).x == Approx(1.34f).epsilon(0.01));
  REQUIRE((vector_03 / -1.34).y == Approx(0).epsilon(0.01));

  REQUIRE((vector_01 / 0.0).x == Approx(vector_01.x).epsilon(0.01));
  REQUIRE((vector_02 / -12.0).y == Approx(-0.17f).epsilon(0.01));
}

// AUFGABE 2.5
TEST_CASE("mat2 constructor", "[vector10]")
{
  Mat2 mat_01{};
  Mat2 mat_02{-3.87f, 2.00f, -1.11, 5.93};

  REQUIRE(mat_01.a == Approx(1.0f).epsilon(0.01));
  REQUIRE(mat_02.a == Approx(-3.871f).epsilon(0.01));
  REQUIRE(mat_01.c == Approx(0.0f).epsilon(0.01));
  REQUIRE(mat_02.d == Approx(5.934f).epsilon(0.01));
}

TEST_CASE("mat2 operator*=", "[vector11]")
{
  Mat2 mat_01{};
  Mat2 mat_02{-3.87f, 2.00f, -1.11, 5.93};

  REQUIRE((mat_02 *= mat_01).a == mat_02.a);
  REQUIRE((mat_02 *= mat_01).b == mat_02.b);
  REQUIRE((mat_02 *= mat_01).c == Approx(-1.11f).epsilon(0.01));
  REQUIRE((mat_02 *= mat_01).d == Approx(5.93f).epsilon(0.01));
}

TEST_CASE("mat2 operator*", "[vector12]")
{
  Mat2 mat_01{};
  Mat2 mat_02{-3.87f, 2.00f, -1.11, 5.93};

  Mat2 result = mat_02 * mat_01;
  REQUIRE(result.a == Approx(-3.87f).epsilon(0.01));
  REQUIRE(result.b == Approx(2.00f).epsilon(0.01));
  REQUIRE(result.c == Approx(-1.11f).epsilon(0.01));
  REQUIRE(result.d == Approx(5.93f).epsilon(0.01));
}

// AUFGABE 2.6
TEST_CASE("mat2 det", "[vector13]")
{
  Mat2 mat_01{};
  Mat2 mat_02{-3.87f, 2.00f, -1.11, 5.93};
  Mat2 mat_03{2.0f, 2.00f, 1.0f, 1.0f};

  REQUIRE(mat_01.det() == 1);
  REQUIRE(mat_02.det() == Approx(-20.72f).epsilon(0.01));
  REQUIRE(mat_03.det() == Approx(0).epsilon(0.01));
}

TEST_CASE("mat2 *vec2", "[vector14]")
{
  Mat2 mat_01{};
  Mat2 mat_02{-3.87f, 2.00f, -1.11, 5.93};
  Mat2 mat_03{2.0f, 2.00f, 1.0f, 1.0f};

  Vec2 vector_01{2.67f, -1.78f};
  Vec2 vector_02{-3.87f, 2.00f};
  Vec2 vector_03{};

  Vec2 test01 = mat_01 * vector_01;
  Vec2 test02 = vector_01 * mat_01;
  Vec2 test03 = mat_03 * vector_03;
  Vec2 test04 = vector_03 * mat_03;

  REQUIRE(test01.x == Approx(2.67f).epsilon(0.01));
  REQUIRE(test02.x == Approx(2.67f).epsilon(0.01));
  REQUIRE(test03.y == Approx(0.0f).epsilon(0.01));
  REQUIRE(test04.y == Approx(0.0f).epsilon(0.01));
}

TEST_CASE("mat2 inverse", "[vector15]")
{
  Mat2 mat_01{};
  Mat2 mat_02{-3.87f, 2.00f, -1.11, 5.93};
  Mat2 mat_03{2.0f, 2.00f, 1.0f, 1.0f};

  REQUIRE(inverse(mat_01).a == Approx(1.0f).epsilon(0.01));
  REQUIRE(inverse(mat_02).b == Approx(-0.05f).epsilon(0.01));
  REQUIRE(inverse(mat_03).c == Approx(1.0f).epsilon(0.01));
}

TEST_CASE("mat2 transpose", "[vector16]")
{
  Mat2 mat_01{};
  Mat2 mat_02{-3.87f, 2.00f, -1.11, 5.93};
  Mat2 mat_03{2.0f, 2.00f, 1.0f, 1.0f};

  REQUIRE(transpose(mat_01).a == Approx(1.0f).epsilon(0.01));
  REQUIRE(transpose(mat_02).b == Approx(1.11f).epsilon(0.01));
  REQUIRE(transpose(mat_03).c == Approx(-2.00f).epsilon(0.01));
}


TEST_CASE("mat2 ROTATION", "[vector17]")
{
  float degreePhi = 180*M_PI/180;
  float radiaPhi = 0.75*M_PI;

  REQUIRE(make_rotation_mat2(degreePhi).a == Approx(-1.0f).epsilon(0.01));
  REQUIRE(make_rotation_mat2(degreePhi).b == Approx(0.0f).epsilon(0.01));
  REQUIRE(make_rotation_mat2(radiaPhi).c == Approx(0.707f).epsilon(0.01));
  REQUIRE(make_rotation_mat2(radiaPhi).d == Approx(-0.71f).epsilon(0.01));

}

// AUFGABE 2.7
TEST_CASE("COLOR", "[vector18]")
{
  Color black {0.0}; // sets r = g = b =0.0
  Color red {1.0 , 0.0 ,0.0};

  Color test {0.5, 0.5,0.5};
  REQUIRE(black.r == Approx(0.0f).epsilon(0.01f));
  REQUIRE(black.g == Approx(0.0f).epsilon(0.01f));
  REQUIRE(black.b == Approx(0.0f).epsilon(0.01f));
  
  REQUIRE(red.r == Approx(1.0f).epsilon(0.01f));
  REQUIRE(red.g == Approx(0.0f).epsilon(0.01f));
  REQUIRE(red.b == Approx(0.0f).epsilon(0.01f));
  
  REQUIRE(test.r == Approx(0.5f).epsilon(0.01f));
  REQUIRE(test.g == Approx(0.5f).epsilon(0.01f));
  REQUIRE(test.b == Approx(0.5f).epsilon(0.01f));
  
  
}

// AUFGABE 2.8
TEST_CASE("CircleRectangle", "[vector19]")
{
  Vec2 punkt1{};
  Vec2 punkt2{2.2f,-3.4f};
  
  Circle cir1 {punkt1, 2.2f};
  Circle cir2 {punkt2, -5.0f};

  Rectangle rect1 {punkt1, punkt2};

  REQUIRE(cir1.get_radius() == Approx(2.2f).epsilon(0.01f));
  REQUIRE(cir1.get_center().x == Approx(0.0f).epsilon(0.01f));
  REQUIRE(cir2.get_radius() == Approx(5.0f).epsilon(0.01f));
  REQUIRE(cir2.get_center().y == Approx(-3.4f).epsilon(0.01f));
  
  REQUIRE(rect1.get_length()== Approx(3.4f).epsilon(0.01f));
  REQUIRE(rect1.get_width()== Approx(2.2f).epsilon(0.01f));
  REQUIRE(rect1.get_max().x== Approx(2.2f).epsilon(0.01f));
  REQUIRE(rect1.get_max().y== Approx(0.0f).epsilon(0.01f));
  REQUIRE(rect1.get_min().x== Approx(0.0f).epsilon(0.01f));  
  REQUIRE(rect1.get_min().y== Approx(-3.4f).epsilon(0.01f));
  
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
