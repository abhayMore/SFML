#include "Vector2.h"
template<class T>
Vector2<T>::Vector2():x(0.0f),y(0.0f)
{
}

template<class T>
Vector2<T>::Vector2(T x): x(x), y(x)
{
}

template<class T>
Vector2<T>::Vector2(T x, T y): x(x),y(y)
{
}

template<class T>
sf::Vector2<float> Vector2<T>::ConverttoSF()
{
  return sf::Vector2<float>(static_cast<T>(x),static_cast<T>(y));
}


template<class T>
Vector2<T> Vector2<T>::operator+( const Vector2<T>& Right )
{
  return Vector2<T>(x + Right.x, y + Right.y);
}

template<class T>
Vector2<T> Vector2<T>::operator-( const Vector2<T>& Right)
{
  return Vector2<T>(x - Right.x, y - Right.y);
}

template<class T>
Vector2<T>& Vector2<T>::operator=(const Vector2<T>& Vector2Obj)
{
  x = Vector2Obj.x;
  y = Vector2Obj.y;
  return *this;
}

template<class T>
bool Vector2<T>::operator!=(const Vector2<T> &obj)
{
  return !((x == obj.x) && (y == obj.y));
}


template<class T>
bool Vector2<T>::operator==(const Vector2<T> &obj)
{
  return ((x == obj.x) && (y == obj.y));
}

template class Vector2<int>;
template class Vector2<float>;
template class Vector2<unsigned int>;
