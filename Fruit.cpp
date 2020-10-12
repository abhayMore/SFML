#include "Fruit.h"
#include "Constant.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <time.h>


Fruit::Fruit()
{
  srand(time(NULL));
  x =(rand() % 30)*m_FruitSizeWidth;
  y = (rand() % 30)*m_FruitSizeHeight;
  m_Fruit.setSize(sf::Vector2f(m_FruitSizeWidth, m_FruitSizeHeight));
  m_Fruit.setFillColor(GREEN);
  m_Fruit.setOrigin(m_Fruit.getSize().x/2, m_Fruit.getSize().y/2);
  m_Fruit.setPosition(x,y);
}

void Fruit::draw(sf::RenderWindow& Window)
{
  Window.draw(m_Fruit);
}

void Fruit::update()
{
}
