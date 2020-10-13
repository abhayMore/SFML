
 #include "Player.h"
 #include "Constant.h"
 #include <iostream>
 #include "SFML/Graphics.hpp"


Player::Player( int WIDTH, int HEIGHT): WindowWidth(WIDTH),WindowHeight(HEIGHT)
{
  m_Speed = 10.0f;
  m_Rectangle.setSize(sf::Vector2f(m_RectSizeWidth, m_RectSizeHeight));
  m_Rectangle.setFillColor(RED);
  m_Rectangle.setOrigin(m_Rectangle.getSize().x/2,m_Rectangle.getSize().y/2);
  m_Move = Vector2f(WindowWidth/2,WindowHeight/2);
  m_Rectangle.setPosition(m_Move.x,m_Move.y);
}

void Player::draw( sf::RenderWindow& Window)
{
  Window.draw(m_Rectangle);
}

void Player::onKeyDown(sf::Keyboard::Key& KeyCode)
{
  switch(KeyCode)
  {
    case sf::Keyboard::Right:
    {
      m_Move.x += m_Speed;
    }
    break;
    case sf::Keyboard::Left:
    {
      m_Move.x += -m_Speed;
    }
    break;
    case sf::Keyboard::Up:
    {
      m_Move.y += -m_Speed;
    }
    break;
    case sf::Keyboard::Down:
    {
      m_Move.y += m_Speed;
    }
    break;
  }
}

void Player::onKeyUp(sf::Keyboard::Key& KeyCode)
{
}


void Player::update()
{
  if(m_Rectangle.getPosition().x > WindowWidth)
  {
    m_Move.x = 0;
  }
  else if(m_Rectangle.getPosition().x  < 0)
  {
    m_Move.x = WindowWidth;
  }
  else if(m_Rectangle.getPosition().y > WindowHeight)
  {
    m_Move.y = 0;
  }
  else if(m_Rectangle.getPosition().y < 0)
  {
    m_Move.y = WindowHeight;
  }

  m_Rectangle.setPosition(m_Move.x, m_Move.y);

}
