#ifndef __CRENDERER_H__
#define __CRENDERER_H__

class CRendererObj;
class CRendererObjImpl;

class CRenderer {
public:
   virtual ~CRenderer() = default;

   virtual void              setFilePath(const char* filepath) = 0;
   virtual CRendererObj*     createSprite(const char* filename)      const = 0;
   virtual CRendererObjImpl* createSpriteImpl(const char* filename)  const = 0;
   virtual CRendererObj*     createString(const char* str)           const = 0;
   virtual CRendererObjImpl* createStringImpl(const char* filename)  const = 0;

   virtual void          clearScreen() const = 0;
   virtual void          refresh() const = 0;   
};

#endif