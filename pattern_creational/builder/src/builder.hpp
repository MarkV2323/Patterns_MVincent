#pragma once

#include "color.hpp"

// Abstract Interface that provides a shared way of "building" objects
// that must be implemented by "concrete builders"
// 
// 1) We want to avoid the shared objects having large constructors
// 2) We want to create different representations of some product
class IBuilder {
public:
  virtual ~IBuilder() = default;

  // Reset the in-progress building of an object
  virtual void Reset() noexcept = 0;

  // Perform build step one involving age
  virtual void BuildStepOne(int age) noexcept = 0;

  // Perform build step two involving miles
  virtual void BuildStepTwo(int miles) noexcept = 0;

  // Perform build step three involving color
  virtual void BuildStepThree(Color color) noexcept = 0;

};

