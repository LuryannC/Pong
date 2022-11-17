#include "Vector.h"

#include <cmath>

Vector::Vector(float _x, float _y)
{
  x = (1 / sqrtf(_x * _x) + (_y * _y));
  y = (1 / sqrtf(_x * _x) + (_y * _y));
}

float Vector::getX(){
  return x;
}

float Vector::getY(){
  return y;
}