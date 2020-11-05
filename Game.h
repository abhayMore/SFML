#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "World.h"
#include "Player.h"
#include "Vector2.h"

class Game
{
private:
  sf::RenderWindow WindowScreen;
  World m_World;
  Player m_Snake;
  sf::Clock clock;
  float Elapsed;

  sf::Event GameEvent;
public:
  Game(const std::string Name, const Vector2u WindowSize);
  ~Game();

  bool isRunning();
  void Event();
  void Update();
  void Render();
  sf::Time GetElapsed();
  void RestartClock();


};


#endif /* GAME_H_ */
