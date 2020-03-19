#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
int main()
{

	sf::RenderWindow window(sf::VideoMode(600,600),"SCREEN");

	sf::Texture texture;
	if(!texture.loadFromFile("texture.jpeg"))
	{
		cout<<"Error loading file"<<endl;
	}
		
	sf::Sprite sprite(texture);
	
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
			}	
		}
		window.clear();
		
		window.draw(sprite);

		window.display();	
	}	
	
	return 0;
}
