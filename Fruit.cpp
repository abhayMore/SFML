#include "Fruit.h"
#include "Constant.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <time.h>


Fruit::Fruit()
{
  srand(time(NULL));
  m_FruitPos.x =(rand() % 29)*m_FruitSizeWidth;
  m_FruitPos.y= (rand() % 29)*m_FruitSizeHeight;
  m_Fruit.setSize(sf::Vector2f(m_FruitSizeWidth, m_FruitSizeHeight));
  m_Fruit.setFillColor(GREEN);
  m_Fruit.setOrigin(m_Fruit.getSize().x/2, m_Fruit.getSize().y/2);
  m_Fruit.setPosition(m_FruitPos.x,m_FruitPos.y);

  std::cout << m_FruitPos << '\n';

}

void Fruit::draw(sf::RenderWindow& Window)
{
  Window.draw(m_Fruit);
}

const sf::Vector2f& Fruit::getPosition()
{
  return m_Fruit.getPosition();
}
void Fruit::update()
{
 m_Fruit.setPosition(m_FruitPos.x,m_FruitPos.y);

}
