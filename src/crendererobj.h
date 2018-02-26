#ifndef __CRENDEREROBJ_H__
#define __CRENDEREROBJ_H__

#include <cstdint>

class CRendererObjImpl;

class CRendererObj {
public:
   CRendererObj() = delete;
   CRendererObj(CRendererObjImpl* impl);
   ~CRendererObj();

   void draw();
   void setPosition(uint8_t x, uint8_t y);
   uint8_t getX() const;
   uint8_t getY() const;

   void              setImplementation(CRendererObjImpl* impl);
   CRendererObjImpl* getImplementation();
private:
   CRendererObjImpl* m_impl = nullptr;  // Implementation

   void  clearImpl();
};

#endif