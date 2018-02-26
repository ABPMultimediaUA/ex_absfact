#ifndef __CRENDEREROBJSTDP2_H__
#define __CRENDEREROBJSTDP2_H__

#include <crendererobjstdp.h>

class CRendererObjSTDP2 : public CRendererObjSTDP {
public:
   CRendererObjSTDP2() = default;
   virtual ~CRendererObjSTDP2() = default;

   void draw() const override;
   void setPosition(uint8_t x, uint8_t y) override;

   friend istream& operator>>(istream& in, CRendererObjSTDP2& robj);
};

#endif