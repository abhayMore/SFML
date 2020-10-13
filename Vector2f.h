#ifndef VECTOR2_H
#define VECTOR2_H
#include <iostream>

class Vector2f
{
public:
  float x;
  float y;

Vector2f();

Vector2f(float x, float y);

friend std::ostream& operator<<(std::ostream& out, const Vector2f &VecObj);

};


#endif /* VECTOR2_H */
