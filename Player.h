#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "Vector2.h"

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



public:

  Player(int BlockSize);
	~Player();

	void SetDirection(PlayerDirection Direction);

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
	void Update();

	void Cut(int Segments);
  void Render(sf::RenderWindow& Window);



  void onKeyDown(sf::Keyboard::Key&);
  void onKeyUp(sf::Keyboard::Key&);

};


#endif /* PLAYER_H_ */
