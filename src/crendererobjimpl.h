#ifndef __CRENDEREROBJIMPL_H__
#define __CRENDEREROBJIMPL_H__

#include <cstdint>

class CRendererObjImpl {
public:
   virtual ~CRendererObjImpl() = default;

   virtual void draw() const = 0;
   virtual void setPosition(uint8_t x, uint8_t y) = 0;
};

#endif