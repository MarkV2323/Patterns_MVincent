#pragma once

#include <string>

#include <fmt/base.h>
#include <fmt/color.h>

#include "color.hpp"

class Boat {
public:
  Boat() = default;

  // Copy constructor default
  Boat(const Boat &) = default;
  // Move constructor default
  Boat(Boat &&) noexcept = default;
  // Copy assignment default
  Boat &operator=(const Boat &) = default;
  // Move assignment default
  Boat &operator=(Boat &&) noexcept = default;

  void SetAge(int i) { age_ = i; }
  void SetMiles(int i) { miles_ = i; }
  void SetColor(Color c) { color_ = c; }

  int GetAge() const { return age_; }
  int GetMiles() const { return miles_; }
  Color GetColor() const { return color_; }

  std::string ToString() {
    std::string s = "";
    s += fmt::format(fmt::fg(fmt::color::dark_cyan), "{:<5} -> ", "Age");
    s += fmt::format(fmt::fg(fmt::color::dark_orange), "{}\n",
                     std::to_string(age_));
    s += fmt::format(fmt::fg(fmt::color::dark_cyan), "{:<5} -> ", "Miles");
    s += fmt::format(fmt::fg(fmt::color::dark_orange), "{}\n",
                     std::to_string(miles_));
    s += fmt::format(fmt::fg(fmt::color::dark_cyan), "{:<5} -> ", "Color");
    s +=
        fmt::format(fmt::fg(fmt::color::dark_orange), "{}", ::ToString(color_));
    return s;
  }

private:
  int age_ = 0;
  int miles_ = 0;
  Color color_ = Color::Red;
};
