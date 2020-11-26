#ifndef WORLD_H
#define WORLD_H
#include "Fruit.h"
#include "Vector2.h"
#include "Player.h"
#include "SFML/Graphics.hpp"

class World
{
private:
  Vector2u m_WindowSize;
  int m_BlockSize = 20;
  sf::RectangleShape m_Bounds[4];
  Vector2i m_Item;
  Fruit Apple;

public:
  World(Vector2u WindowSize );
  ~World();
  int GetBlockSize();
  void RespawnFruit(Player &Obj);
  void Update(Player& PlayerObj);
  void Render(sf::RenderWindow& Window);
};

#endif /* WORLD_H_ */
