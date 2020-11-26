#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "Vector2.h"
#include "Textbox.h"

struct SnakeSegment
{
  SnakeSegment(int x, int y): Position(x,y)
  {

  }
  Vector2i Position;
};

enum class PlayerDirection
{
  None,
  Up,
  Down,
  Left,
  Right
};


class Player
{
private:
	void CheckCollision();

	std::vector<SnakeSegment> m_SnakeBody;
	int m_Size;

	PlayerDirection m_Direction;
	int m_Speed;
	int m_Lives;
	int m_Score;
	bool m_Lost;

	sf::RectangleShape m_Rectangle;
  Vector2f RectSize;
  Textbox *m_ScoreLog, *m_LivesLog;



public:

  Player(int BlockSize, Textbox* ScoreLog, Textbox* LivesLog);
	~Player();

	void SetDirection(PlayerDirection Direction);

  std::vector<SnakeSegment> GetSnakeBody();
	PlayerDirection GetDirection();
	int GetSpeed();
	Vector2i GetPosition();
	int GetLives();
	int GetScore();


	void IncreaseScore();
	bool HasLost();

	void Lose();
	void ToggleLost();

	void Extend();
	void Reset();

	void MovePlayer();
	void Cut(int Segments);

  void onKeyDown(sf::Keyboard::Key&);
  void onKeyUp(sf::Keyboard::Key&);

  void Update();
  void Render(sf::RenderWindow& Window);
};


#endif /* PLAYER_H_ */
