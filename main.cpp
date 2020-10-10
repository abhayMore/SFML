#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

struct Config
{
	std::string TITLE;
	int WIDTH;
	int HEIGHT;
};

void loadconfig(Config& config)
{
	std::ifstream ConfigFile("./Config/config.ini");
	if(!ConfigFile)
	{
		std::cout << "Error loading config.ini" << '\n';
	}
	else
	{
		std::string line;
		while(getline(ConfigFile,line))
		{
			std::istringstream sin(line.substr(line.find("=") + 1));
			if(line.find("WIDTH") != -1)
				sin >> config.WIDTH;
			else if( line.find("HEIGHT") != -1)
				sin >> config.HEIGHT;
			else if(line.find("TITLE") != -1)
				sin >> config.TITLE;
		}
	}
}



sf::Color RED(255,0,0);

int main()
{
	struct Config config;
	loadconfig(config);

	std::cout << config.WIDTH << '\n';
	std::cout << config.HEIGHT << '\n';
	std::cout << config.TITLE << '\n';

	sf::RenderWindow window(sf::VideoMode(config.WIDTH, config.HEIGHT), config.TITLE);

	sf::RectangleShape rectangle;
	const float RectSizeWidth  = 20.0f;
	const float RectSizeHeight = 20.0f;
	const int RectPositionX		 = 0;
	const int RectPositionY 	 = 0;

	rectangle.setSize(sf::Vector2f(RectSizeWidth, RectSizeHeight));
	rectangle.setFillColor(RED);
	rectangle.setPosition(RectPositionX,RectPositionY);

	float Speed = 10.0f;
	float MoveX =  0.0f;
	float MoveY =  0.0f;

	while(window.isOpen())
	{
		sf::Event event;



		while(window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
				{
					window.close();
				}
				break;

				case sf::Event::KeyPressed:
				{
					switch(event.key.code)
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


			rectangle.setPosition(MoveX, MoveY);



			window.clear();

			window.draw(rectangle);

			window.display();
		}
	}
	return 0;
}
