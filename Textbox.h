#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "SFML/Graphics.hpp"
#include "Vector2.h"

class Textbox
{
private:
  sf::Font m_Font;
  sf::Text m_Content;



public:
  Textbox();
  Textbox(int CharSize, int Width, Vector2f ScreeenPos);
  ~Textbox();
  void Setup( int CharSize, int Width, Vector2f ScreeenPos);
  void Add(const std::string& Message);
  void Render(sf::RenderWindow& Wind);
};



#endif //TEXTBOX_H
