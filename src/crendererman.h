#ifndef __CRENDERERMANAGER_H__
#define __CRENDERERMANAGER_H__

#include <vector>
#include <crenderer.h>
#include <crendererobj.h>
#include <crendererobjstdp.h>

enum class CRendererType { STDP, STDP2, SFML };
using TVecRenderObjs = std::vector<CRendererObj*>;

class CRendererMan {
public:
   ~CRendererMan();

   static CRendererMan& p();
   CRenderer& renderer();
   void changeToRenderer(CRendererType t, TVecRenderObjs& robjs);
   void switchToSFML(TVecRenderObjs& robjs);

   template<class TRenderTo>
   void switchRenderer(TVecRenderObjs& robjs) {
      delete m_renderer;
      m_renderer = new TRenderTo();
      for(auto* o : robjs) {
         const char* file;
         CRendererObjImpl* newimp; 
         file = o->getImplementation()->getObjFile().c_str();
         newimp = m_renderer->createSpriteImpl(file);
         o->setImplementation(newimp);
      }
   }

private:
   CRendererMan();

   CRenderer* m_renderer = nullptr;
};

#endif