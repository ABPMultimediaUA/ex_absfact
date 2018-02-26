#ifndef __CRENDERERSFML_H__
#define __CRENDERERSFML_H__

#include <crenderer.h>
#include <string>

class CRendererObj;
namespace sf { class RenderWindow; }

class CRendererSFML : public CRenderer {
public:
   CRendererSFML();
   virtual ~CRendererSFML();
   
            void          setFilePath(const char* filepath)  override;
   virtual  CRendererObj* createSprite(const char* filename) const override;
   virtual  CRendererObj* createString(const char* str)      const override;
   
   void clearScreen() const override;
   void refresh() const override;      
protected:
   std::string          m_filepath  = "graphics/SFML/";
   sf::RenderWindow*    m_window    = nullptr;
};

#endif