#pragma once
#include <Arduino.h>

class Vector {
public:

  int x;
  int y;

  Vector(){
    x = 0;
    y = 0;
  }

  Vector(int nx, int ny) {
    x = nx;
    y = ny;
  }

  int8_t get_magnitude() {
    return sqrt(x * x + y * y);
  }

  void normalize() {
    const float norm_const = 1.0f / get_magnitude();

    x *= norm_const;
    y *= norm_const;
  }
};


class Particle {
public:
  Vector pos;
  Vector velocity;

  Particle(){
    pos = Vector();
    velocity = Vector();
  }

  Particle(int x, int y){
    pos = Vector(x, y);
    velocity = Vector();
  }
};