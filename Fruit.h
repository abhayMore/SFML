#ifndef FRUIT_H
#define FRUIT_H

#include "SFML/Graphics.hpp"


class Fruit
{
private:
  float x, y;
  sf::RectangleShape m_Fruit;
  const float m_FruitSizeWidth = 20.0f;
  const float m_FruitSizeHeight = 20.0f;

public:

  Fruit();

  void draw(sf::RenderWindow&);

  void update();

};


#endif /* FRUIT_H */
