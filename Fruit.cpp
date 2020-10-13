#include "Fruit.h"
#include "Constant.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <time.h>


Fruit::Fruit()
{
  srand(time(NULL));
  x =(rand() % 30)*m_FruitSizeWidth;//I want a position variable for fruit. If I want to get Fruit's position somewhere else, make it so that I can retrieve it through object of class fruit.
  y = (rand() % 30)*m_FruitSizeHeight; // with current setup there is no way of getting that outside this class and even if it was I would have to do it through m_Fruit which means making m_Fruit public which I dont want at the moment.
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
  //missed the setposition here. 
}
