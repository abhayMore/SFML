#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
const sf::Color RED(255,0,0);

class Player
{
private:
	sf::RectangleShape m_Rectangle;
	const float m_RectSizeWidth		= 20.0f;
	const float m_RectSizeHeight	= 20.0f;
	const int m_RectPositionX		= 0;
	const int m_RectPositionY		= 0;
	float m_Speed;
	float m_MoveX;
	float m_MoveY;

public:

  Player();

  void draw(sf::RenderWindow&);

  void onKeyDown(sf::Keyboard::Key&);

  void onKeyUp(sf::Keyboard::Key&);

	void update();

};


#endif /* PLAYER_H_ */
