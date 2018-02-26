#ifndef __CRENDERERSPRITESFML_H__
#define __CRENDERERSPRITESFML_H__

#include <crendererobjimpl.h>
#include <string>

namespace sf {
   class Texture;
   class Sprite;
   class RenderWindow;
}
class CRendererObjSTDP;

class CRendererSpriteSFML : public CRendererObjImpl {
public:
   const float kSprWidth  = 32.0;
   const float kSprHeight = 32.0;

   CRendererSpriteSFML() = delete;
   CRendererSpriteSFML(std::string objf, sf::RenderWindow* window, const std::string& filename);
   virtual ~CRendererSpriteSFML();
   
   virtual void draw() const override;
   virtual void setPosition(uint8_t x, uint8_t y) override;
protected:
   sf::Texture*      m_texture;  // Sprite's Texture
   sf::Sprite*       m_sprite;   // The Sprite
   sf::RenderWindow* m_window;   // Pointer to the render window
};

#endif