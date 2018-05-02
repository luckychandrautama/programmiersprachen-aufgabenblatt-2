#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

TEST_CASE("vec2 constructor", "[vector1]"){
  REQUIRE(Vec2().x==0);
  REQUIRE(Vec2().y==0);

  REQUIRE(Vec2(2,3).x == Approx(2.00f).epsilon(0.001));
  REQUIRE(Vec2(2.56,3.78).y == Approx(3.78f).epsilon(0.001));

/*   Vec2 test_vector3 ();
  REQUIRE(test_vector3.x == 0);
  REQUIRE(test_vector3.y == 0); */


}

TEST_CASE("vec2 operator+=", "[vector2]"){
  REQUIRE((Vec2()+=Vec2(2.56,3.78)).x == 2.56f);
  REQUIRE((Vec2()+=Vec2(2.56,3.78)).y == 3.78f);

  REQUIRE((Vec2(-1.56,-2.01)+=Vec2(2.56,3.78)).x == Approx(1.0f).epsilon(0.01));
  REQUIRE((Vec2(-1.56,-2.01)+=Vec2(2.56,3.78)).y == Approx(1.77f).epsilon(0.01));

}


TEST_CASE("vec2 operator-=", "[vector3]"){
  Vec2 test_vector1 (2.67f,-1.78f);
  Vec2 test_vector2 (-3.87f, 2.00f);

  Vec2 test_vector3();
  Vec2 test_vector4 (-3.87f, -2.00f);

  REQUIRE((test_vector1-=test_vector2).x == Approx(6.54f).epsilon(0.01));
  REQUIRE((test_vector1-=test_vector2).x == Approx(10.41f).epsilon(0.01));

  REQUIRE((test_vector1-=test_vector2).y == Approx(-7.78f).epsilon(0.01));
/*   REQUIRE((test_vector3-=test_vector4).x == 3.78f);
  REQUIRE((test_vector3-=test_vector4).y == 2.00f); */



  REQUIRE((Vec2()-=test_vector2).x==Approx(3.87f).epsilon(0.01));
}

TEST_CASE("vec2 operator*=", "[vector4]"){
  Vec2 test_vector1 (2.67f,-1.78f);
  Vec2 test_vector3();

  REQUIRE((test_vector1 *= 2.00).x == Approx(5.34f).epsilon(0.01));
  REQUIRE((Vec2()*=1).y == Approx(0).epsilon(0.01));

/*   REQUIRE((test_vector3 *= 5).x == 0);
 */  REQUIRE((test_vector1 *= -1.00).y == Approx(3.56f).epsilon(0.01));

  REQUIRE((test_vector1 *= 0).x == Approx(0).epsilon(0.01));

}

TEST_CASE("vec2 operator/=", "[vector4]"){
  Vec2 test_vector1 (2.67f,-1.78f);
  Vec2 test_vector2 (-3.87f, 2.00f);

  Vec2 test_vector3();

  REQUIRE((test_vector1 /= 2.00).x == Approx(1.34f).epsilon(0.01));
  REQUIRE((Vec2()/=1).y == Approx(0).epsilon(0.01));

/*   REQUIRE((test_vector3 *= 5).x == 0);
 */  REQUIRE((test_vector1 /= -1.5).y == Approx(0.599f).epsilon(0.01));
  REQUIRE((test_vector2 /= 0).x == test_vector2.x);

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
