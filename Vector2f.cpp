#include "Vector2f.h"

Vector2f::Vector2f():x(0.0f),y(0.0f)
{
}

Vector2f::Vector2f(float x, float y): x(x),y(y)
{

}

std::ostream& operator<<(std::ostream& Out, const Vector2f &VecObj)
{
  Out << "(" << VecObj.x << ", " << VecObj.y << ")";
  return Out;
}
