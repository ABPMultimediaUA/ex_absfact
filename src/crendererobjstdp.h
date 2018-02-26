#ifndef __CRENDEREROBJSTDP_H__
#define __CRENDEREROBJSTDP_H__

#include <crendererobjimpl.h>
#include <cstdint>
#include <string>
#include <fstream>
#include <StdPijo.h>

class CRendererObjSTDP : public CRendererObjImpl {
public:
   CRendererObjSTDP() = delete;
   CRendererObjSTDP(std::string objf) : CRendererObjImpl(std::move(objf)) {};
   CRendererObjSTDP(const CRendererObjSTDP& other);
   virtual ~CRendererObjSTDP() = default;
   
   void setAppearance(const std::string& app);
   void setAttribute(const std::string& att);
   void setFGColor(const std::string& fg);
   void setBGColor(const std::string& bg);

   virtual void draw() const override;
   virtual void setPosition(uint8_t x, uint8_t y) override;

   uint8_t getX() const override { return m_x; }
   uint8_t getY() const override { return m_y; }

   friend std::istream& operator>>(std::istream& in, CRendererObjSTDP& robj);
   friend class CRendererObjSTDP2;
//   friend class CRendererSpriteSFML;   
protected:
   std::string m_appearance   = "O";
   uint8_t     m_attrib       = STDP_A_NORMAL;
   uint8_t     m_fgcolor      = STDP_C_NEGRO;
   uint8_t     m_bgcolor      = STDP_C_BLANCO;
   uint8_t     m_x            = 0;
   uint8_t     m_y            = 0;
};

#endif