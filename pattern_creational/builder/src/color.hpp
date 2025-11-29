#pragma once

#include <string_view>

enum class Color { Red, Green, Blue };

// return string_view of Color enum
constexpr std::string_view ToString(Color c) noexcept {
  switch (c) {
  case Color::Red:
    return "Red";
  case Color::Green:
    return "Green";
  case Color::Blue:
    return "Blue";
  }
  return "Null";
}
