#include <crendererobj.h>
#include <crenderersfml.h>
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

CRendererObj* 
CRendererSFML::createSprite(const char* filename) const {
   // Create SFML Sprite   

   return new CRendererObj(nullptr);
}

CRendererObj* 
CRendererSFML::createString(const char* str) const {
   // Create SFML String

   return new CRendererObj(nullptr);
}

void
CRendererSFML::setFilePath(const char* filepath) { 
   m_filepath = filepath;
}
