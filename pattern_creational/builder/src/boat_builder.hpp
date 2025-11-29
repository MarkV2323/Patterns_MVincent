#pragma once

#include "boat.hpp"
#include "builder.hpp"

class BoatBuilder : public IBuilder {
public:
  BoatBuilder() = default;
  ~BoatBuilder() override = default;

  void Reset() noexcept override { boat_ = Boat(); }

  void BuildStepOne(int age) noexcept override { boat_.SetAge(age); }

  void BuildStepTwo(int miles) noexcept override { boat_.SetMiles(miles); }

  void BuildStepThree(Color color) noexcept override { boat_.SetColor(color); }

  // Return finished object
  Boat Build() noexcept { return boat_; };

private:
  Boat boat_{};
};
