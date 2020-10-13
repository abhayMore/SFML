#ifndef FRUIT_H
#define FRUIT_H

#include "SFML/Graphics.hpp"
#include "Vector2f.h"


class Fruit
{
private:
  Vector2f m_FruitPos;
  sf::RectangleShape m_Fruit;
  const float m_FruitSizeWidth = 20.0f;
  const float m_FruitSizeHeight = 20.0f;

public:

  Fruit();

  void draw(sf::RenderWindow&);

  void update();

  const sf::Vector2f& getPosition();

};


#endif /* FRUIT_H */
