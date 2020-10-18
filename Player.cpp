
 #include "Player.h"
 #include "Constant.h"
 #include <iostream>
 #include "SFML/Graphics.hpp"


Player::Player( int WIDTH, int HEIGHT): WindowWidth(WIDTH),WindowHeight(HEIGHT)
{
  m_Speed = 0.6f;

  m_Rectangle.setSize(sf::Vector2f(m_RectSizeWidth, m_RectSizeHeight));
  m_Rectangle.setFillColor(RED);
  m_Rectangle.setOrigin(m_Rectangle.getSize().x/2,m_Rectangle.getSize().y/2);

  Position = Vector2f(WindowWidth/2,WindowHeight/2);
  m_Rectangle.setPosition(Position.x,Position.y);
  Velocity = Vector2f(0.0f,0.0f);
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
      Velocity.y = 0.0f;
      Velocity.x = m_Speed;
    }
    break;
    case sf::Keyboard::Left:
    {
      Velocity.y = 0.0f;
      Velocity.x = -m_Speed;
    }
    break;
    case sf::Keyboard::Up:
    {
      Velocity.x = 0.0f;
      Velocity.y = -m_Speed;

    }
    break;
    case sf::Keyboard::Down:
    {
      Velocity.x = 0.0f;
      Velocity.y = m_Speed;
    }
    break;
  }
}

void Player::MovePlayer()
{
}


void Player::onKeyUp(sf::Keyboard::Key& KeyCode)
{
}

void Player::update(const sf::Time& Dt)
{

  if(m_Rectangle.getPosition().x > WindowWidth)
  {
    Position.x = 0;
  }
  else if(m_Rectangle.getPosition().x  < 0)
  {
    Position.x = WindowWidth;
  }
  else if(m_Rectangle.getPosition().y > WindowHeight)
  {
    Position.y = 0;
  }
  else if(m_Rectangle.getPosition().y < 0)
  {
    Position.y = WindowHeight;
  }

  Position.x += Velocity.x*Dt.asMilliseconds();
  Position.y += Velocity.y*Dt.asMilliseconds();
  m_Rectangle.setPosition(Position.x,Position.y);

}
