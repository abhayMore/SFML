#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "SFML/Graphics.hpp"
#include "Vector2.h"

class Textbox
{
public:
  Textbox();
  Textbox(int Visible, int CharSize, int Width, Vector2f ScreeenPos);
  ~Textbox();
  void Setup(int Visible, int CharSize, int Width, Vector2f ScreeenPos);
  void Add(std::string Message);
  void Clear();

  void Render(sf::RenderWindow& Wind);
private:
  std::vector<std::string> m_Messages;
  int m_Visible;

  sf::RectangleShape m_Backdrop;
  sf::Font m_Font;
  sf::Text m_Content;
};



#endif //TEXTBOX_H
