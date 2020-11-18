#include "Textbox.h"


Textbox::Textbox()
{
  Setup(5,9,200,Vector2f(0.0f,0.0f));
}

Textbox::Textbox(int Visible, int CharSize, int Width, Vector2f ScreeenPos)
{
  Setup(Visible,CharSize, Width, ScreeenPos);

}

Textbox::~Textbox()
{
  Clear();
}

void Textbox::Setup(int Visible, int CharSize, int Width, Vector2f ScreeenPos)
{
  m_Visible = Visible;
  Vector2f Offset(2.0f,2.0f);

  m_Font.loadFromFile("arial.ttf");
  m_Content.setFont(m_Font);
  m_Content.setString(" ");
  m_Content.setCharacterSize(CharSize);
  m_Content.setFillColor(sf::Color::White);
  m_Content.setPosition(ScreeenPos.ConverttoSF()+Offset.ConverttoSF());

  m_Backdrop.setSize(Vector2f(Width,(Visible*(CharSize*1.2f))).ConverttoSF());
  m_Backdrop.setFillColor(sf::Color(0,0,0,90));
  m_Backdrop.setPosition(ScreeenPos.ConverttoSF());
}

void Textbox::Add(std::string Message)
{
  m_Messages.push_back(Message);
  if(m_Messages.size()<2) return;
  m_Messages.erase(m_Messages.begin());
}


void Textbox::Clear()
{
  m_Messages.clear();
}

void Textbox::Render(sf::RenderWindow& Wind)
{
  std::string Content;
  for(auto &itr : m_Messages)
    Content.append(itr + "\n");

  if(Content != "")
  {
    m_Content.setString(Content);
    Wind.draw(m_Backdrop);
    Wind.draw(m_Content);
  }
}
