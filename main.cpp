#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

const std::string& Title = "Snake";  //Window/Game Name
const int WIDTH		 = 600;      //Window Width
const int HEIGHT         = 600;      //Window Height

sf::Color RED(255,0,0);

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), Title);

	sf::RectangleShape rectangle;
	const float RectSizeWidth  = 20.0f;
	const float RectSizeHeight = 20.0f;
	const int RectPositionX	   = 0;
	const int RectPositionY	   = 0;

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
