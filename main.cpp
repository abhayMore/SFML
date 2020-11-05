#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Game.h"
#include "Vector2.h"
#include <math.h>



struct Config
{
	std::string WINDOW_TITLE;
	Vector2u WINDOWSIZE;
	Config(): WINDOW_TITLE("Saanp"), WINDOWSIZE(400,400)
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
				Sin >> LocalData.WINDOWSIZE.x;

			else if( Line.find("HEIGHT") != -1)
				Sin >> LocalData.WINDOWSIZE.y;

			else if(Line.find("TITLE") != -1)
				Sin >> LocalData.WINDOW_TITLE;
		}
	}
	return LocalData;
}





int main()
{
	const Config Data(GetnLoadConfigData());

	Game GameWindow(Data.WINDOW_TITLE,Data.WINDOWSIZE);

	while(GameWindow.isRunning())
	{
		GameWindow.Event();
		GameWindow.Update();
		GameWindow.RestartClock();
		GameWindow.Render();
	}

	return 0;
}
