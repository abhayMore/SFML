#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

const sf::Color RED(255,0,0);

struct Config
{
	std::string WINDOW_TITLE;
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;

	Config(): WINDOW_TITLE("Snake"), WINDOW_WIDTH(400), WINDOW_HEIGHT(400)
	{
	}
};

Config GetConfigData()
{
	Config LocalData;
	std::ifstream ConfigFile("./Config/config.ini");
	if(!ConfigFile)
	{
		std::cerr << "Error loading config.ini" << '\n';
	}
	else
	{
		std::string Line;
		while(getline(ConfigFile,Line))
		{
			std::istringstream Sin(Line.substr(Line.find("=") + 1));

			if(Line.find("WIDTH") != -1)
				Sin >> LocalData.WINDOW_WIDTH;

			else if( Line.find("HEIGHT") != -1)
				Sin >> LocalData.WINDOW_HEIGHT;

			else if(Line.find("TITLE") != -1)
				Sin >> LocalData.WINDOW_TITLE;
		}
	}
	return LocalData;
}

class Player
{
private:
	sf::RectangleShape m_Rectangle;
	const float m_RectSizeWidth	= 20.0f;
	const float m_RectSizeHeight	= 20.0f;
	const int m_RectPositionX	= 0;
	const int m_RectPositionY	= 0;
	float m_Speed;
	float m_MoveX;
	float m_MoveY;

public:
	Player()
	{
		m_Speed	= 20;
		m_MoveX = 0;
		m_MoveY	= 0;
		m_Rectangle.setSize(sf::Vector2f(m_RectSizeWidth, m_RectSizeHeight));
		m_Rectangle.setFillColor(RED);
		m_Rectangle.setPosition(m_RectPositionX,m_RectPositionY);
	}

	void draw( sf::RenderWindow& Window)
	{
		Window.draw(m_Rectangle);
	}

	void onKeyDown(sf::Keyboard::Key& KeyCode)
	{
		switch(KeyCode)
		{
			case sf::Keyboard::Right:
			{
				m_MoveX += m_Speed;
			}
			break;
			case sf::Keyboard::Left:
			{
				m_MoveX += -m_Speed;
			}
			break;
			case sf::Keyboard::Up:
			{
				m_MoveY += -m_Speed;
			}
			break;
			case sf::Keyboard::Down:
			{
				m_MoveY += m_Speed;
			}
			break;
		}
	}

	void onKeyUp(sf::Keyboard::Key& KeyCode)
	{
	}

	void update()
	{
		m_Rectangle.setPosition(m_MoveX, m_MoveY);
	}
};

int main()
{
	const  Config Data(GetConfigData());

	sf::RenderWindow Window(sf::VideoMode(Data.WINDOW_WIDTH, Data.WINDOW_HEIGHT), Data.WINDOW_TITLE);

	Player Snake;

	while(Window.isOpen())
	{
		sf::Event GameEvent;

		while(Window.pollEvent(GameEvent))
		{
			switch(GameEvent.type)
			{
				case sf::Event::Closed:
				{
					Window.close();
				}
				break;

				case sf::Event::KeyPressed:
				{
					Snake.onKeyDown(GameEvent.key.code);
				}
				break;

				case sf::Event::KeyReleased:
				{
					Snake.onKeyUp(GameEvent.key.code);
				}
				break;
			}

			Snake.update();



			Window.clear();

			Snake.draw(Window);

			Window.display();
		}
	}
	return 0;
}
