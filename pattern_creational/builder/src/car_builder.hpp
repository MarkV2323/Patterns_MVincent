#pragma once

#include "builder.hpp"
#include "car.hpp"

class CarBuilder : public IBuilder {
public:
  CarBuilder() = default;
  ~CarBuilder() override = default;

  void Reset() noexcept override { car_ = Car(); }

  void BuildStepOne(int age) noexcept override { car_.SetAge(age); }

  void BuildStepTwo(int miles) noexcept override { car_.SetMiles(miles); }

  void BuildStepThree(Color color) noexcept override { car_.SetColor(color); }

  // Return finished object
  Car Build() noexcept { return car_; };

private:
  Car car_{};
};
