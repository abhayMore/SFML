#include "Game.h"
#include "SFML/Graphics.hpp"
#include "Constant.h"
#include "Player.h"

Game::Game(const std::string Name, const Vector2u WindowSize):m_World(WindowSize),m_Snake(m_World.GetBlockSize(), &m_TextboxScore, &m_TextboxLives)
{
  WindowScreen.create(sf::VideoMode(WindowSize.x, WindowSize.y), Name);
  clock.restart();
  Elapsed = 0.0f;

  m_TextboxScore.Setup(0,14,350,Vector2f(20,0));
  m_TextboxScore.Add("Score : "+std::to_string((long long)m_Snake.GetScore()));

  m_TextboxLives.Setup(0,14,350,Vector2f(WindowSize.x - 75,0));
  m_TextboxLives.Add("Lives : "+std::to_string((long long)m_Snake.GetLives()));


}

bool Game::isRunning()
{
  return WindowScreen.isOpen();
}

Game::~Game()
{
}
sf::Time Game::GetElapsed()
{
  return clock.getElapsedTime();
}
void Game::RestartClock()
{
  Elapsed += clock.restart().asSeconds();
}

void Game::Event()
{
  while(WindowScreen.pollEvent(GameEvent))
  {
    if(GameEvent.type == sf::Event::Closed)
      WindowScreen.close();
    else if(GameEvent.type == sf::Event::KeyPressed)
      m_Snake.onKeyDown(GameEvent.key.code);
    else if(GameEvent.type == sf::Event::KeyReleased)
        m_Snake.onKeyUp(GameEvent.key.code);

  }
}

void Game::Update()
{
  float timestep =  1.0f/m_Snake.GetSpeed();
  if(Elapsed >= timestep)
    {
      m_Snake.Update();
      m_World.Update(m_Snake);
      Elapsed -= timestep;
      if(m_Snake.HasLost())
      {
        m_TextboxScore.Add("Game Over! Score: " + std::to_string((long long)m_Snake.GetScore()));
        m_Snake.Reset();
      }
    }
}

void Game::Render()
{
  WindowScreen.clear(BLACK);

  m_World.Render(WindowScreen);
  m_Snake.Render(WindowScreen);
  m_TextboxScore.Render(WindowScreen);
m_TextboxLives.Render(WindowScreen);

  WindowScreen.display();
}
