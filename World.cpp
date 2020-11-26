#include "World.h"
#include "Constant.h"
#include "Fruit.h"
#include <time.h>

World::World(Vector2u WindowSize)
{
  m_BlockSize = 20;
  m_WindowSize = WindowSize;
  srand(time(NULL));
  m_Item = Vector2i(15,10);
  Apple.SetPosition(m_Item.x*m_BlockSize,m_Item.y*m_BlockSize);

  for(int i = 0; i < 4; ++i)
  {
    m_Bounds[i].setFillColor(GREY);
    if(!((i + 1)%2))
    {
      m_Bounds[i].setSize(Vector2f(m_WindowSize.x,m_BlockSize).ConverttoSF());
    }
    else
    {
      m_Bounds[i].setSize(Vector2f(m_BlockSize,m_WindowSize.y).ConverttoSF());
    }
    if(i < 2)
    {
      m_Bounds[i].setPosition(0,0);
    }
    else
    {
      //auto ptr = Vector2f(m_WindowSize);
      m_Bounds[i].setOrigin(m_Bounds[i].getSize());
      m_Bounds[i].setPosition(m_WindowSize.ConverttoSF());
    }
  }
}

World::~World(){}

int World::GetBlockSize()
{
  return m_BlockSize;
}


void World::RespawnFruit(Player &Obj)
{
  int MaxX = (m_WindowSize.x/m_BlockSize - 2);
  int MaxY = (m_WindowSize.y/m_BlockSize - 2);
  m_Item = Vector2i(rand()% MaxX + 1, rand()% MaxY + 1);
  for(auto i = Obj.GetSnakeBody().begin(); i!= Obj.GetSnakeBody().end(); i++)
  {
    if(m_Item.x == i->Position.x && m_Item.y == i->Position.y)
    {
      m_Item = Vector2i(rand()% MaxX + 1, rand()% MaxY + 1);
    }
  }
  Apple.SetPosition(m_Item.x *m_BlockSize, m_Item.y*m_BlockSize);
}


void World::Update(Player& PlayerObj)
{
  Apple.Update();
  if(PlayerObj.GetPosition() == m_Item)
  {
    PlayerObj.Extend();
    PlayerObj.IncreaseScore();
    RespawnFruit(PlayerObj);
  }
  int GridSizeX = m_WindowSize.x / m_BlockSize;
  int GridSizeY = m_WindowSize.y / m_BlockSize;
  if(PlayerObj.GetPosition().x <=0 ||
    PlayerObj.GetPosition().y <=0 ||
    PlayerObj.GetPosition().x >= GridSizeX - 1 ||
    PlayerObj.GetPosition().y >= GridSizeY - 1)
  {
    PlayerObj.Lose();
  }
}


void World::Render(sf::RenderWindow& Window)
{
  for(int i = 0; i < 4; ++i)
  {
    Window.draw(m_Bounds[i]);
  }
  Apple.Render(Window);
}
