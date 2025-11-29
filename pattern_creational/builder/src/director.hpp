#pragma once

#include "builder.hpp"

class Director {
public:
  Director() = default;
  ~Director() = default;

  void MakeOldVechicle(IBuilder &b) {
    b.Reset();
    b.BuildStepOne(100);
    b.BuildStepTwo(999'999'999);
    b.BuildStepThree(Color::Red);
  }

  void MakeNewVechicle(IBuilder &b) {
    b.Reset();
    b.BuildStepOne(0);
    b.BuildStepTwo(0);
    b.BuildStepThree(Color::Blue);
  }
};
