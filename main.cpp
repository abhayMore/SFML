#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include<sstream>
#include<fstream>
#include "Player.h"



struct Config
{
	std::string WINDOW_TITLE;
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;
	Config(): WINDOW_TITLE("Snake"), WINDOW_WIDTH(400), WINDOW_HEIGHT(400)
	{
	}


};

Config GetnLoadConfigData()
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
	const  Config Data(GetnLoadConfigData());

	sf::RenderWindow Window(sf::VideoMode(Data.WINDOW_WIDTH, Data.WINDOW_HEIGHT), Data.WINDOW_TITLE);

	Player Snake(Data.WINDOW_WIDTH,Data.WINDOW_HEIGHT);

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
