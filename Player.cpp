
 #include "Player.h"
 #include <iostream>
 #include "SFML/Graphics.hpp"


Player::Player( int WIDTH, int HEIGHT): Width(WIDTH),Height(HEIGHT)
{
  m_Speed = 20.0f;
  m_Move = sf::Vector2f(0.0f,0.0f);
  m_Rectangle.setSize(sf::Vector2f(m_RectSizeWidth, m_RectSizeHeight));
  m_Rectangle.setFillColor(RED);
  m_Rectangle.setPosition(m_RectPositionX,m_RectPositionY);
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
  if(m_Rectangle.getPosition().x > Width)
  {
    m_Move.x = 0;
  }
  else if(m_Rectangle.getPosition().x  < 0)
  {
    m_Move.x = Width;
  }
  else if(m_Rectangle.getPosition().y > Height)
  {
    m_Move.y = 0;
  }
  else if(m_Rectangle.getPosition().y < 0)
  {
    m_Move.y = Height;
  }

  m_Rectangle.setPosition(m_Move.x, m_Move.y);

}
