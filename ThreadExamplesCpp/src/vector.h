#pragma once

#include <cmath>
#include <string>

class Vector {
 private:
  int x{0}, y{0};

 public:
  Vector() {};
  Vector(int x1, int y1) : x(x1), y(y1) {};
  ~Vector() {};

  int& getX() {
    return x;
  }

  int& getY() {
    return y;
  }

  void setX(int x1) {
    x = x1;
  }

  void setY(int y1) {
    y = y1;
  }

  // L = sqrt (x^2 + y^2)
  double getLength() {
    return std::sqrt(pow(x, 2) + pow(y, 2));
  }

  // A = atan (y / x)
  double getAngle() {
    return std::atan(y / x);
  }

  int dot(Vector& v) {
    return ((x * v.getX()) + (y * v.getY()));
  }

  Vector scale(int s) {
    Vector rVec(x * s, y * s);
    return rVec;
  }

  Vector normal() {
    double currentLength = getLength();
    Vector rVec(x / currentLength, y / currentLength);
    return rVec;
  }

  Vector add(Vector& v) {
    Vector rVec(x + v.getX(), y + v.getY());
    return rVec;
  }

  Vector sub(Vector& v) {
    Vector rVec(x - v.getX(), y - v.getY());
    return rVec;
  }

  std::string toString() {
    std::string rString = "";
    rString += "Length => " + std::to_string(getLength()) + " of (" +
               std::to_string(x) + "," + std::to_string(y) + ")";
    return rString;
  }

  static double convertToDegree(double raidian) {
    return ((180 / M_PI) * raidian);
  }
};
