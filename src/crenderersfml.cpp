#include <crendererobj.h>
#include <crenderersfml.h>
#include <crendererspritesfml.h>
#include <istream>
#include <SFML/Graphics.hpp>

CRendererSFML::CRendererSFML() {
   // Init SFML
   m_window = new sf::RenderWindow(sf::VideoMode(640, 480), "ex_absfact");
}

CRendererSFML::~CRendererSFML() {  
   if (m_window) {
      m_window->close();
      delete m_window;
      m_window = nullptr;
   }
}

void 
CRendererSFML::clearScreen() const { 
   m_window->clear();
}
void 
CRendererSFML::refresh() const {
   m_window->display();
}

CRendererObjImpl* 
CRendererSFML::createSpriteImpl(const char* filename) const {
   std::string f = m_filepath + filename + m_ext;

   CRendererSpriteSFML* s = new CRendererSpriteSFML(filename, m_window, f);

   return s;
}

CRendererObjImpl* 
CRendererSFML::createStringImpl(const char* str) const {
   // Placeholder at the moment
   return createSpriteImpl(str);
}

CRendererObj* 
CRendererSFML::createSprite(const char* filename) const {
   return new CRendererObj( createSpriteImpl(filename) );
}

CRendererObj* 
CRendererSFML::createString(const char* str) const {
   return new CRendererObj( createStringImpl(str) );
}

void
CRendererSFML::setFilePath(const char* filepath) { 
   m_filepath = filepath;
}
