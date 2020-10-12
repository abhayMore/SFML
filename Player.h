#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "Constant.h"

class Player
{
private:
	int Width;
	int Height;
	sf::RectangleShape m_Rectangle;
	const float m_RectSizeWidth	= 20.0f;
	const float m_RectSizeHeight	= 20.0f;
	const int m_RectPositionX	= 0;
	const int m_RectPositionY	= 0;
	float m_Speed;
	sf::Vector2f m_Move ;

public:

  Player(int, int);

  void draw(sf::RenderWindow&);

  void onKeyDown(sf::Keyboard::Key&);

  void onKeyUp(sf::Keyboard::Key&);

  void update();

};


#endif /* PLAYER_H_ */
