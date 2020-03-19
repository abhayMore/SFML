#include <SFML/Graphics.hpp>

int main()
{



	sf::RenderWindow window(sf::VideoMode(600,600),"SCREEN");
	while(window.isOpen())
	{
		sf::Event evnt;
		while(window.pollEvent(evnt))
		{
			if(evnt.type == evnt.Closed)
				window.close();	
		}	
	}	
	
	return 0;
}
