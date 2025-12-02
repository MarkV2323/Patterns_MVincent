#include <fmt/base.h>
#include <fmt/color.h>

#include "singleton.hpp"

std::string the_point =
    R"(The singleton pattern:

Technically it violates the Single Responsiblity Principal (SRP);
but it's useful so who cares! Make the default constructor private.
Create a static function that acts as the constructor, return a
copy of the instance if already created.

This version is not a thread-safe version; if we wanted that
we could add a mutex locking mechanisim...

1) Ensure a class has a single instance.
2) Provide a global access point to that instance.
3) Provide locking mechanism for thread-safety.
)";

std::string GetYellowString(std::string_view s) {
  return fmt::format(fmt::fg(fmt::color::yellow), "{}", s);
}

int main(int argc, char *argv[]) {
  fmt::print("\n{}\n", GetYellowString(the_point));

  // Attempt to get a ref to the Singleton object
  auto sing = Singleton::GetSingleton();
  fmt::print("{}", sing.ToString());

  // Getting another ref
  auto sing_2 = Singleton::GetSingleton();
  fmt::print("\n{}", sing.ToString());

  // Setting data on our first ref
  sing.SetData(50);

  // Print both refs toStrings
  fmt::print("\n{}", sing.ToString());
  fmt::print("\n{}", sing.ToString());

  return 0;
}
