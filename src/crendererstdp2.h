#ifndef __CRENDERERSTDP2_H__
#define __CRENDERERSTDP2_H__

#include <crendererstdp.h>

class CRendererSTDP2 : public CRendererSTDP {
public:
   CRendererSTDP2() = default;
   virtual ~CRendererSTDP2() = default;

   CRendererObj* createSprite(const char* filename)         const override;
   CRendererObjImpl* createSpriteImpl(const char* filename) const override;  
   CRendererObj* createString(const char* str)              const override;   
   CRendererObjImpl* createStringImpl(const char* str)      const override;  
};

#endif