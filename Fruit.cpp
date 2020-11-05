#include "Fruit.h"

#include "SFML/Graphics.hpp"

#include <time.h>
#include "Vector2.h"
#include "Constant.h"



Fruit::Fruit()
{
  srand(time(NULL));

  m_Fruit.setSize(m_FruitSize.ConverttoSF());
  m_Fruit.setFillColor(RED);
}

void Fruit::RespawnFruit(Vector2u WorldWindSize, int BoundSize)
{
  m_Item = Vector2i(0,0);
  int MaxX = (WorldWindSize.x/BoundSize - 2);
  int MaxY = (WorldWindSize.y/BoundSize - 2);
  m_Item = Vector2i(rand()% MaxX + 1, rand()% MaxY + 1);
  m_FruitPos = Vector2i(m_Item.x *BoundSize, m_Item.y*BoundSize);
  m_Fruit.setPosition(m_FruitPos.x, m_FruitPos.y);
}

void Fruit::Render(sf::RenderWindow& Window)
{
  Window.draw(m_Fruit);
}

Vector2i Fruit::GetItem()
{
  return m_Item;
}

void Fruit::Update()
{
 m_Fruit.setPosition(m_FruitPos.x,m_FruitPos.y);
}
