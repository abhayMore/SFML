#include "Fruit.h"
#include "SFML/Graphics.hpp"
#include "Vector2.h"
#include "Constant.h"

Fruit::Fruit()
{
  m_Fruit.setSize(m_FruitSize.ConverttoSF());
  m_Fruit.setFillColor(RED);
}


void Fruit::SetPosition(int a, int b)
{
  m_FruitPos = Vector2i(a,b);
}


Vector2i Fruit::GetPosition()
{
  return m_FruitPos;
}


void Fruit::Update()
{
 m_Fruit.setPosition(m_FruitPos.x,m_FruitPos.y);
}


void Fruit::Render(sf::RenderWindow& Window)
{
  Window.draw(m_Fruit);
}
