#include <fmt/base.h>
#include <fmt/color.h>

#include <string_view>

#include "boat_builder.hpp"
#include "car_builder.hpp"
#include "director.hpp"

std::string the_point =
    R"(The builder pattern:
Abstract Interface that provides a shared way of "building" objects
that must be implemented by "concrete builders"
 
1) We want to avoid the shared objects having large constructors
2) We want to create different representations of some product
)";

std::string GetYellowString(std::string_view s) {
  return fmt::format(fmt::fg(fmt::color::yellow), "{}", s);
}

int main(int argc, char *argv[]) {
  fmt::print("\n{}\n", GetYellowString(the_point));

  // Manually using Car Builder
  auto c_builder = CarBuilder();
  c_builder.BuildStepOne(10);
  c_builder.BuildStepTwo(127'456);
  c_builder.BuildStepThree(Color::Blue);
  auto c1 = c_builder.Build();
  c_builder.Reset();
  auto c2 = c_builder.Build();

  fmt::print("Car 1\n{}\n", c1.ToString());
  fmt::print("Car 2\n{}\n", c2.ToString());

  // Manually using Boat Builder
  auto b_builder = BoatBuilder();
  b_builder.BuildStepOne(20);
  b_builder.BuildStepTwo(100'100);
  b_builder.BuildStepThree(Color::Green);
  auto b1 = b_builder.Build();
  fmt::print("Boat 1\n{}\n", b1.ToString());

  // Using a director
  auto director = Director();
  director.MakeOldVechicle(c_builder);
  c1 = c_builder.Build();
  fmt::print("Car 1\n{}\n", c1.ToString());
  director.MakeNewVechicle(b_builder);
  b1 = b_builder.Build();
  fmt::print("Boat 1\n{}\n", b1.ToString());

  return 0;
}
