#include "Textbox.h"
#include "Constant.h"


Textbox::Textbox()
{
  Setup(9,200,Vector2f(0.0f,0.0f));
}


Textbox::Textbox( int CharSize, int Width, Vector2f ScreeenPos)
{
  Setup(CharSize, Width, ScreeenPos);

}


Textbox::~Textbox()
{
}


void Textbox::Setup( int CharSize, int Width, Vector2f ScreeenPos)
{

  Vector2f Offset(2.0f,2.0f);

  if(!m_Font.loadFromFile("arial.ttf"))
  {
      std::cout << "Failed to load arial.ttf" << '\n';
      exit(1);
  }
  m_Content.setFont(m_Font);
  m_Content.setString(" ");
  m_Content.setCharacterSize(CharSize);
  m_Content.setFillColor(BLACK);
  m_Content.setPosition(ScreeenPos.ConverttoSF()+Offset.ConverttoSF());


}


void Textbox::Add(const std::string& Message)
{
  m_Content.setString(Message);
}





void Textbox::Render(sf::RenderWindow& Wind)
{
  Wind.draw(m_Content);
}
