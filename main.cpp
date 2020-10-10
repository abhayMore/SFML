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

int main()
{
	const  Config Data(GetConfigData());

	sf::RenderWindow Window(sf::VideoMode(Data.WINDOW_WIDTH, Data.WINDOW_HEIGHT), Data.WINDOW_TITLE);


	sf::RectangleShape Rectangle;
	const float RectSizeWidth  = 20.0f;
	const float RectSizeHeight = 20.0f;
	const int RectPositionX	   = 0;
	const int RectPositionY	   = 0;

	Rectangle.setSize(sf::Vector2f(RectSizeWidth, RectSizeHeight));
	Rectangle.setFillColor(RED);
	Rectangle.setPosition(RectPositionX,RectPositionY);

	float Speed = 10.0f;
	float MoveX =  0.0f;
	float MoveY =  0.0f;

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
					switch(GameEvent.key.code)
					{
						case sf::Keyboard::Right:
						{
							MoveX += Speed;
						}
						break;
						case sf::Keyboard::Left:
						{
							MoveX += -Speed;
						}
						break;
						case sf::Keyboard::Up:
						{
							MoveY += -Speed;
						}
						break;
						case sf::Keyboard::Down:
						{
							MoveY += Speed;
						}
						break;
					}
				}
				break;
			}


			Rectangle.setPosition(MoveX, MoveY);



			Window.clear();

			Window.draw(Rectangle);

			Window.display();
		}
	}
	return 0;
}
