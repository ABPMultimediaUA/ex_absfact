#ifndef __CRENDERERSTDP_H__
#define __CRENDERERSTDP_H__

#include <crenderer.h>
#include <string>

class CRendererObj;

class CRendererSTDP : public CRenderer {
public:
   CRendererSTDP();
   virtual ~CRendererSTDP();
   
            void          setFilePath(const char* filepath)  override;
   virtual  CRendererObj* createSprite(const char* filename) const override;
   virtual  CRendererObj* createString(const char* str)      const override;
   
   void clearScreen() const override;
   void refresh() const override;      
protected:
   std::string    m_filepath = "graphics/stdp/";
};

#endif