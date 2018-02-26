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

   void  setImplementation(CRendererObjImpl* impl);
private:
   CRendererObjImpl* m_impl = nullptr;  // Implementation

   void  clearImpl();
};

#endif