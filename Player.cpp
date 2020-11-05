#include "Player.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Constant.h"
#include "Vector2.h"

Player::Player(int BlockSize):  m_Size(BlockSize)
{
  RectSize = Vector2f(m_Size - 1);
  m_Rectangle.setSize(Vector2f(RectSize.x,RectSize.y).ConverttoSF());
  Reset();
}

Player::~Player()
{

}
void Player::Reset()
{
  m_SnakeBody.clear();

  m_SnakeBody.push_back(SnakeSegment(15, 15));
  m_SnakeBody.push_back(SnakeSegment(15, 16));
  m_SnakeBody.push_back(SnakeSegment(15, 17));


  SetDirection(PlayerDirection::None);
  m_Speed = 15;
  m_Lives = 3;
	m_Score = 0;
	m_Lost = false;

}
void Player::SetDirection(PlayerDirection Direction)
{
  m_Direction = Direction;
}

PlayerDirection Player::GetDirection()
{
  return m_Direction;
}

int Player::GetSpeed()
{
  return m_Speed;
}

Vector2i Player::GetPosition()
{
  return (!m_SnakeBody.empty()? m_SnakeBody.front().Position : Vector2i(1, 1));
}

int Player::GetLives()
{
  return m_Lives;
}

int Player::GetScore()
{
  return m_Score;
}

void Player::IncreaseScore()
{
  m_Score += 10;
}

bool Player::HasLost()
{
  return m_Lost;
}
void Player::Lose()
{
  m_Lost = true;
}

void Player::ToggleLost()
{
  m_Lost = !m_Lost;
}

void Player::Extend()
{
  if(m_SnakeBody.empty())
  {
    return;
  }
  SnakeSegment& Tail_Head = m_SnakeBody[m_SnakeBody.size() - 1];

  if(m_SnakeBody.size() > 2)
  {
    SnakeSegment& Tail_Bone = m_SnakeBody[m_SnakeBody.size() - 2];

    if(Tail_Head.Position.x == Tail_Bone.Position.x)
    {
      if(Tail_Head.Position.y > Tail_Bone.Position.y)
      {
        m_SnakeBody.push_back(SnakeSegment(Tail_Head.Position.x,Tail_Head.Position.y + 1));
      }
      else
      {
        m_SnakeBody.push_back(SnakeSegment(Tail_Head.Position.x,Tail_Head.Position.y - 1));
      }
    }
    else if(Tail_Head.Position.y == Tail_Bone.Position.y)
    {
      if(Tail_Head.Position.x > Tail_Bone.Position.x)
      {
        m_SnakeBody.push_back(SnakeSegment(Tail_Head.Position.x + 1,Tail_Head.Position.y));
      }
      else
      {
        m_SnakeBody.push_back(SnakeSegment(Tail_Head.Position.x - 1,Tail_Head.Position.y));
      }
    }
  }
  else
    {
      if(m_Direction == PlayerDirection::Up)
      {
        m_SnakeBody.push_back(SnakeSegment(Tail_Head.Position.x, Tail_Head.Position.y + 1));
      }
      else if(m_Direction == PlayerDirection::Down)
      {
        m_SnakeBody.push_back(SnakeSegment(Tail_Head.Position.x, Tail_Head.Position.y - 1));
      }
      else if(m_Direction == PlayerDirection::Left)
      {
        m_SnakeBody.push_back(SnakeSegment(Tail_Head.Position.x + 1, Tail_Head.Position.y - 1));
      }
      else if(m_Direction == PlayerDirection::Right)
      {
        m_SnakeBody.push_back(SnakeSegment(Tail_Head.Position.x - 1, Tail_Head.Position.y - 1));
      }
    }
}

void Player::Update()
{
  if(m_SnakeBody.empty())
  {
    return;
  }
  if(m_Direction == PlayerDirection::None)
  {
    return;
  }
  MovePlayer();
  CheckCollision();
}







void Player::onKeyDown(sf::Keyboard::Key& KeyCode)
{
  if((KeyCode == sf::Keyboard::Right) && GetDirection()!= PlayerDirection::Left )
  {
    SetDirection(PlayerDirection::Right);
  }
  else if((KeyCode == sf::Keyboard::Left) && GetDirection()!= PlayerDirection::Right)
  {
    SetDirection(PlayerDirection::Left);
  }
  else if((KeyCode == sf::Keyboard::Up) && GetDirection()!= PlayerDirection::Down)
  {
    SetDirection(PlayerDirection::Up);
  }
  else if((KeyCode == sf::Keyboard::Down) && GetDirection()!= PlayerDirection::Up)
  {
    SetDirection(PlayerDirection::Down);
  }
}

void Player::MovePlayer()
{
  for(int i = m_SnakeBody.size() - 1; i > 0; --i)
  {
    m_SnakeBody[i].Position = m_SnakeBody[i - 1].Position;
  }
  if(m_Direction == PlayerDirection::Left)
    --m_SnakeBody[0].Position.x;
  else if(m_Direction == PlayerDirection::Right)
    ++m_SnakeBody[0].Position.x;
  else if(m_Direction == PlayerDirection::Up)
    --m_SnakeBody[0].Position.y;
  else if(m_Direction == PlayerDirection::Down)
    ++m_SnakeBody[0].Position.y;
}

void Player::CheckCollision()
{
  if(m_SnakeBody.size() < 5)
    return;
  SnakeSegment& Head = m_SnakeBody.front();
  for(auto i = m_SnakeBody.begin() + 1; i != m_SnakeBody.end(); ++i)
  {
    if(i->Position == Head.Position)
    {
      int Segments = m_SnakeBody.end() - i;
      Cut(Segments);
      break;
    }
  }
}

void Player::Cut(int Segments)
{
  for(int i = 0; i < Segments; ++i)
  {
    m_SnakeBody.pop_back();
  }
  --m_Lives;
  if(!m_Lives)
    {
      Lose();
      return;
    }
}

void Player::onKeyUp(sf::Keyboard::Key& KeyCode)
{
}

void Player::Render( sf::RenderWindow& Window)
{
  if(m_SnakeBody.empty())
    return;

  auto head = m_SnakeBody.begin();
  m_Rectangle.setFillColor(YELLOW);
  m_Rectangle.setPosition(head->Position.x * m_Size,head->Position.y*m_Size);
  Window.draw(m_Rectangle);

  m_Rectangle.setFillColor(GREEN);
  for(auto i = m_SnakeBody.begin() + 1; i != m_SnakeBody.end(); ++i)
  {
    m_Rectangle.setPosition(i->Position.x * m_Size,i->Position.y*m_Size);
    Window.draw(m_Rectangle);
  }

}
