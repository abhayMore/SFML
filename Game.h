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
  sf::Event GameEvent;
  sf::Clock clock;
  float Elapsed;
  World m_World;
  Player *m_Snake;
  Textbox m_TextboxScore;
  Textbox m_TextboxLives;

public:
  Game(const std::string Name, const Vector2u WindowSize);
  ~Game();

  sf::Time GetElapsed();
  bool isRunning();
  void Event();
  void RestartClock();
  void Update();
  void Render();
};


#endif /* GAME_H_ */
