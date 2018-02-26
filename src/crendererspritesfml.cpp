#include <crendererspritesfml.h>
#include <crendererobjstdp.h>
#include <SFML/Graphics.hpp>

CRendererSpriteSFML::CRendererSpriteSFML(std::string objf, sf::RenderWindow* window, const std::string& filename) 
 : CRendererObjImpl(std::move(objf))
{
   // Set the window
   if (!m_window)
      throw std::logic_error("Null SFML Window received (CRendererSpriteSFML).");
   m_window = window;

   // Load texture
   m_texture = new sf::Texture();
   if (!m_texture->loadFromFile(filename.c_str()))
      throw std::logic_error("File not found (" + filename + ").");

   // Generate sprite
   m_sprite = new sf::Sprite(*m_texture);
}

CRendererSpriteSFML::~CRendererSpriteSFML() {
   if (m_sprite)  { delete m_sprite; m_sprite = nullptr; }
   if (m_texture) { delete m_texture; m_texture = nullptr; }
}
   
void 
CRendererSpriteSFML::draw() const {
   // Draw the sprite
   m_window->draw(*m_sprite);
}

void 
CRendererSpriteSFML::setPosition(uint8_t x, uint8_t y) {
   m_sprite->setPosition(x * kSprWidth, y * kSprHeight);
}