#ifndef __CRENDERERSFML_H__
#define __CRENDERERSFML_H__

#include <crenderer.h>
#include <string>

class CRendererObj;
class CRendererObjImpl;
namespace sf { class RenderWindow; }

class CRendererSFML : public CRenderer {
public:
   CRendererSFML();
   virtual ~CRendererSFML();
   
   void              setFilePath (const char* filepath)  override;
   CRendererObj*     createSprite(const char* filename)      const override;
   CRendererObjImpl* createSpriteImpl(const char* filename)  const override;
   CRendererObj*     createString(const char* str)           const override;
   CRendererObjImpl* createStringImpl(const char* str)       const override;
   
   void clearScreen() const override;
   void refresh() const override;      
protected:
   std::string          m_filepath  = "graphics/SFML/";
   std::string          m_ext       = ".png";
   sf::RenderWindow*    m_window    = nullptr;
};

#endif