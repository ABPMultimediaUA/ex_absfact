#ifndef __CRENDEREROBJ_H__
#define __CRENDEREROBJ_H__

#include <cstdint>

class CRendererObj {
public:
   virtual ~CRendererObj() = default;

   virtual void draw() const = 0;
   virtual void setPosition(uint8_t x, uint8_t y) = 0;
};

#endif