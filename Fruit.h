#ifndef FRUIT_H
#define FRUIT_H

#include "SFML/Graphics.hpp"
#include "Vector2.h"



class Fruit
{
private:
  Vector2i m_FruitPos;
  Vector2f m_FruitSize{20,20};
  Vector2i m_Item;
  sf::RectangleShape m_Fruit;

public:
  Fruit();
  void SetPosition(int a, int b);
  Vector2i GetPosition();
  void Render(sf::RenderWindow&);
  void Update();
};


#endif /* FRUIT_H */
