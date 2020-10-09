#include "SFML/Graphics.hpp"
#include <iostream>


int WIDTH = 600;
int HEIGHT = 600;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake");

	sf::RectangleShape rectangle(sf::Vector2f(0.0f,0.0f));

	rectangle.setSize(sf::Vector2f(20.0f,20.0f));

	rectangle.setFillColor(sf::Color(255,0,0));

	rectangle.setPosition(0,0);

	int Speed = 10;
	int Movex = 0;
	int Movey = 0;

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
							Movex += Speed;
						}
						break;
						case sf::Keyboard::Left:
						{
							Movex += -Speed;
						}
						break;
						case sf::Keyboard::Up:
						{
							Movey += -Speed;
						}
						break;
						case sf::Keyboard::Down:
						{
							Movey += Speed;
						}
						break;
					}
				}
				break;
			}


			rectangle.setPosition(Movex, Movey);



			window.clear();

			window.draw(rectangle);

			window.display();
		}
	}
	return 0;
}
